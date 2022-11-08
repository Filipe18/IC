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

    Mat negimg (img.rows, img.cols, img.type());


    for(int i = 0; i < img.rows; i++){
        for (int j = 0; j < img.cols; j++){
            negimg.at<uchar>(i, j) = 255 - img.at<uchar>(i, j);
        }
    }

    //Show image on window
    //namedWindow("negative image", WINDOW_NORMAL);
    //resizeWindow("negative image", 1050, 650);
    imshow("negative image", negimg);
    waitKey(0);
    destroyWindow("negative image");   


    return 0;
}


