#include <iostream>
#include <opencv2/opencv.hpp>
#include <string.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //Command line arguments processing
    if(argc < 2){
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n" ;
        return 1;
    }

    char *inputfile = argv[1];
    char *outputfile = argv[2];

    Mat image = imread(inputfile);


    //Check if image exists
    if(image.empty()){
        cout << "Error: Could not open image" << endl;
        return 1;
    }

    Mat negimg (image.rows, image.cols, image.type());


    for(int i=0; i < image.rows; i++){
        for(int j=0 ; j < image.cols; j++)
            negimg.ptr<Vec3b>(i)[j] = Vec3b(255-image.ptr<Vec3b>(i)[j][0], 255-image.ptr<Vec3b>(i)[j][1], 255-image.ptr<Vec3b>(i)[j][2]);
        
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


