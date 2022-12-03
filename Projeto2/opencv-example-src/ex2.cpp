#include <cstring>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "string.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //char option;
    cout << "Chose an Option:\n'N' to negative version of an image\n'M' to mirrored version of an image\n'R' to rotate an image by a multiple of 90º\n'I' to increase and decrease the intensity values of an image\n";
    cout << "Option:";
    //char* option = {};
    char option[0];
    
    
    cin >> option;
    
    //Command line arguments processing
    if(argc < 2){
        cerr << "Usage: " << argv[0] << "<input_file> <output_file>\n" ;
        return 1;
    }
    
    //alinea = argv[1];
    char *inputfile = argv[1];
    char *outputfile = argv[2];
    Mat img = imread(inputfile);
    //Check if image exists
    if(img.empty()){
        cout << "Error: Could not open image" << endl;
        return 1;
    }

    if(!strcmp(option,"N")){

        cout << "olaaaaaaaa";
        
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
    
    else if(!strcmp(option,"M")){
    
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

    else if(!strcmp(option,"R")){
        int multiple;
        cout << "Choose a number multiple of 90º:";
        cin >> multiple;


        while(multiple % 90 != 0){
            cout << "The number you chose is not a multiple of 90\n";
            cout << "Number:";
            cin >> multiple;
            
        }
        
        
        //Outra forma de se fazer
        //Mat rotateimg (img.rows, img.cols, img.type());
        //transpose(img, rotateimg);
        //flip(rotateimg, rotateimg, 1);

        // get the center coordinates of the image to create the 2D rotation matrix
        Point2f center((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);

        //Using getRotationMatrix2D() to get the rotation matrix
        //Mat rotation = getRotationMatrix2D(center, -90, 1);
        Mat rotation = getRotationMatrix2D(center, -multiple, 1);


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

    else if(!strcmp(option,"I")){
        int increase;
        int decrease;
        
        cout << "Choose a positive number to Increase the intensity of an image:";
        cin >> increase;

        cout << "Choose a positive number to Decrease the intensity of an image:";
        cin >> decrease;


        Mat imgmorelight;
        Mat imglesslight;

        img.convertTo(imgmorelight, -1, 1, increase); //Increase the brightness

        img.convertTo(imglesslight, -1, 1, -decrease); //Decrease the brightness

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
        cerr << "Choose a possible option\n" ;
        return 1;

    }


    
    
}


