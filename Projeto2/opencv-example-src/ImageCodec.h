#ifndef IMAGECODEC_H
#define IMAGECODEC_H

#include "Golomb.h"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <vector>

using namespace std;
using namespace cv;

//Auxiliary function to PredictorPLS
int predictorJLS(int a, int b, int c){
    
    int x = 0;

    if (c >= max(a,b)) {
        x = min(a,b);
    }
    else if (c <= min(a,b)) {
        x = max(a,b);
    }
    else {
        x = a + b - c;
    }
    return x;
}

class ImageCodec{

    public:
        /**
         * @brief Construct a new Image Codec object
         * 
         */
        ImageCodec();

        /**
         * @brief Construct a new Image Codec object
         * 
         * @param fileSrc filename path to an image file
         */
        ImageCodec(const char *fileSrc);

        /**
         * @brief Compress an input file using lossless

         * @param fileDst path to the image file to be compressed
         */
        void compress(const char *fileDst);

        /**
         * @brief Decompress an input image file

         * @param fileSrc path to the image file to be decompressed
         */
        void decompress(const char *fileSrc);

        /**
         * @brief Lossless Compress Preditor 
         * 
         * @param src source image
         * @param res vector to store the residuals
         */
        void predictorEnc(Mat src, vector<int>& res);

        /**
         * @brief Lossless Descompress Preditor
         * 
         * @param res vector with the residuals
         * @param nRows number of rows of the image
         * @param nCols number of columns of the image
         * @return Mat 
         */

        Mat predictorDec(vector<int>& res, int nRows, int nCols);

        /**
         * @brief Calculate the ideal
         * 
         * @param g Golomb Object 
         * @param resR vector with the residuals of the red channel
         * @param resG vector with the residuals of the green channel
         * @param resB vector with the residuals of the blue channel
         * @return ideal m
         */
        int calculateM(Golomb& g, vector<int>& resR, vector<int>& resG, vector<int>& resB);

    private:
        char* fileSrc;
        Mat image;
};

ImageCodec::ImageCodec(){}

ImageCodec::ImageCodec(const char *fileSrc){

    image = imread(fileSrc, IMREAD_COLOR);

    //Check if image exists
    if(image.empty()){
        cout << "Image doesn't exists" << endl;
        exit(EXIT_FAILURE);
    }
    this->fileSrc = (char*) fileSrc;
}

void ImageCodec::compress(const char *fileDst){

    Mat rgb[3];  

    // split RGB image into 3 arrays (rgb[0] -> Blue channel / rgb[1] -> Green channel / rgb[2] -> Red channel)
    split(image,rgb);  
        
    vector<int> resR, resG, resB;
    predictorEnc(rgb[2], resR);
    predictorEnc(rgb[1], resG);
    predictorEnc(rgb[0], resB);

    Golomb g = Golomb(fileDst, 'e', 0);

    // calculate an ideal M for the 3 channel residual values
    int m = calculateM(g, resR, resG, resB);

    g.setM(m);
    g.encodeM(m);
    g.encode(image.cols);
    g.encode(image.rows);
    
    for(auto r: resR){ g.encode(r); }

    for(auto r: resG){ g.encode(r); }

    for(auto r: resB){ g.encode(r); }
    g.close();
}

void ImageCodec::decompress(const char *fileSrc){

    Golomb g = Golomb(fileSrc, 'd', 0);

    int m = g.decodeM();
    g.setM(m);

    int ncols = g.decode();
    int nrows = g.decode();

    vector<int> resR, resG, resB;
		
    for(int i = 0; i < ncols*nrows; i++){   resR.push_back(g.decode()); }

    for(int i = 0; i < ncols*nrows; i++){   resG.push_back(g.decode()); }

    for(int i = 0; i < ncols*nrows; i++){   resB.push_back(g.decode()); }

    g.close();

    /* Mats for each color channel */
    //rgb[0] -> Blue channel / rgb[1] -> Green channel / rgb[2] -> Red channel

    Mat rgb[3];
    
	rgb[2] = predictorDec(resR, nrows, ncols); 
    rgb[1] = predictorDec(resG, nrows, ncols);
	rgb[0] = predictorDec(resB, nrows, ncols);

    Mat img (image.rows, image.cols, image.type());
	for(int i = 0; i < nrows; i++) {
		for(int j = 0; j < ncols; j++) {
			img.at<Vec3b>(i,j) = Vec3b(rgb[0].at<uchar>(i,j), rgb[1].at<uchar>(i,j), rgb[2].at<uchar>(i,j));
		}
	}

	/* Write mat to file */
	imwrite("output.ppm", img);

    Mat out;
    hconcat(image, img, out);
    //Show image on window
    imshow("Initial image & restored image", out);
    waitKey(0);
    destroyWindow("Initial image & restored image"); 
}

void ImageCodec::predictorEnc(Mat src, vector<int>& res){

    int a, b, c, x;
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            // canto superior esquerdo
            if (i == 0 && j == 0) {
                a = 0;
                b = 0;
                c = 0;
            } 
            else if (i == 0 && j != 0) { // linha cima
                a = (int) src.at<uchar>(i,j-1);
                b = 0;
                c = 0;
            }
            else if (i != 0 && j == 0) { // coluna esquerda
                a = 0;
                b = (int) src.at<uchar>(i-1,j);
                c = 0;
            }
            else {
                a = (int) src.at<uchar>(i,j-1);
                b = (int) src.at<uchar>(i-1,j);
                c = (int) src.at<uchar>(i-1,j-1);
            }

            x = predictorJLS(a,b,c);
            // rn = xn - ^xn
            res.push_back(src.at<uchar>(i, j) - x);
        }
    }
}

Mat ImageCodec::predictorDec(vector<int>& res, int nRows, int nCols){

    Mat img (nRows, nCols, CV_8UC1);
    int a, b, c, rn, x;

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            // canto superior esquerdo
            if (i == 0 && j == 0) {
                a = 0;
                b = 0;
                c = 0;
            } 
            else if (i == 0 && j != 0) { // linha cima
                a = (int) img.at<uchar>(i,j-1);
                b = 0;
                c = 0;
            }
            else if (i != 0 && j == 0) { // coluna esquerda
                a = 0;
                b = (int) img.at<uchar>(i-1,j);
                c = 0;
            }
            else {
                a = (int) img.at<uchar>(i,j-1);
                b = (int) img.at<uchar>(i-1,j);
                c = (int) img.at<uchar>(i-1,j-1);
            }

            rn = (int)res.at(i*nCols + j);
            x = predictorJLS(a,b,c);

            img.at<uchar>(i,j) = (uchar) (rn + x);
        }
    }
    return img;
}

int ImageCodec::calculateM(Golomb& g, vector<int>& resR, vector<int>& resB, vector<int>& resG){
    map<int, int> aux;

    for(auto element : resR){ aux[element]++; }
    for(auto element : resG){ aux[element]++; }
    for(auto element : resB){ aux[element]++; }

    int num_samples = 0;
    for(auto i : aux)
        num_samples += i.second;
    //cout << "Number of samples -> " << num_samples << '\n';
   
    double med = 0;
    for(auto i : aux){
        //cout << "{" << i.first << ": " << i.second << "}\n";
        med += g.map_number(i.first) * (i.second);
    }
    med = med / num_samples;
      
    return ceil(-1 / log2(med / (med + 1)));
}

#endif
