#include <cstring>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "string.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //Command line arguments processing
    if(argc < 3){
        cerr << "Usage: " << argv[0] << "<alínea> <input_file> <output_file>\n" ;
        return 1;
    }
    char* alinea = {};
    alinea = argv[1];
    char *inputfile = argv[2];
    char *outputfile = argv[3];
    Mat img = imread(inputfile);
    //Check if image exists
    if(img.empty()){
        cout << "Error: Could not open image" << endl;
        return 1;
    }

    if(!strcmp(alinea,"a")){
        
        Mat negimg (img.rows, img.cols, img.type());


        for(int i=0; i < img.rows; i++){
            for(int j=0 ; j < img.cols; j++)
                negimg.ptr<Vec3b>(i)[j] = Vec3b(255-img.ptr<Vec3b>(i)[j][0], 255-img.ptr<Vec3b>(i)[j][1], 255-img.ptr<Vec3b>(i)[j][2]);
            
        }

        //Save output image
        imwrite(outputfile ,negimg); 

        //Show image on window
        namedWindow("Negative image", WINDOW_NORMAL);
        resizeWindow("Negative image", 1050, 650);
        imshow("Negative image", negimg);
        waitKey(0);
        destroyWindow("Negative image");  

        return 0;
    }
    
    else if(!strcmp(alinea,"b")){
    
        Mat horizontal (img.rows, img.cols, img.type());
        Mat vertical (img.rows, img.cols, img.type());

        Mat out;    //Guarda os valores das imagens apos tendo sido feito o mirror horizontal e vertical

        flip(img, horizontal, 1); //Mirror version of img (horizontally)
        flip(img, vertical, 0); //Mirror version of img (vertically)

        hconcat(horizontal, vertical, out);

        //Show image on window
        imshow("horizontal and vertical image", out);
        waitKey(0);
        destroyWindow("horizontal image");   

        return 0;

    }

    else if(!strcmp(alinea,"c")){
        
        //Outra forma de se fazer
        //Mat rotateimg (img.rows, img.cols, img.type());
        //transpose(img, rotateimg);
        //flip(rotateimg, rotateimg, 1);

        // get the center coordinates of the image to create the 2D rotation matrix
        Point2f center((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);

        //Using getRotationMatrix2D() to get the rotation matrix
        Mat rotation = getRotationMatrix2D(center, -90, 1);

        //Saving the resulting image in rotatedimg matrix
        Mat rotatedimg;

        //Rotate the image using warpAffine
        warpAffine(img, rotatedimg, rotation, img.size());


        //Show image on window
        imshow("rotated image", rotatedimg);
        waitKey(0);
        destroyWindow("rotated image");   


        return 0;
    }

    else if(!strcmp(alinea,"d")){

        Mat imgmorelight;
        Mat imglesslight;

        img.convertTo(imgmorelight, -1, 1, 100); //Increase the brightness by 100

        img.convertTo(imglesslight, -1, 1, -100); //Decrease the brightness by 100

        Mat out;
        hconcat(imgmorelight, imglesslight, out);
        

        //Show image on window
        imshow("Brightness Increased & brightness Decreased", out);
        waitKey(0);
        destroyWindow("Brightness Increased & brightness Decreased"); 

        /* OR THIS WAY
            int beta = 0;      //Simple brightness control 

            cout << "* Enter the beta value [0-100]: ";    cin >> beta;

            for( int y = 0; y < image.rows; y++ ) {
                for( int x = 0; x < image.cols; x++ ) {
                    for( int c = 0; c < image.channels(); c++ ) {
                        new_image.at<Vec3b>(y,x)[c] =
                        saturate_cast<uchar>(image.at<Vec3b>(y,x)[c] + beta );
                    }
                }
            }
            imshow("new image", new_image);
        */
        //Ver qual das 2 formas é a que parece ser a melhor maneira


        return 0;

    }
    
    else{
        cerr << "Escolha uma alíena existente\n" ;
        return 1;

    }


    
    
}


