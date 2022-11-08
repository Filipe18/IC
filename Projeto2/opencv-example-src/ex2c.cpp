#include <iostream>
#include <opencv2/opencv.hpp>
#include <string.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //Command line arguments processing
    if(argc < 2){
        cerr << "Usage: " << argv[0] << " <input file>\n" ;
        return 1;
    }

    char *inputfile = argv[1];

    Mat img = imread(inputfile, cv::IMREAD_GRAYSCALE);


    //Check if image exists
    if(img.empty()){
        cout << "Error: Could not open image" << endl;
        return 1;
    }


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


