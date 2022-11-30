#include <iostream>
#include <opencv2/opencv.hpp>
#include <string.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //Command line arguments processing
    if(argc < 3){
        cerr << "Usage: " << argv[0] << " <input_file>< <output_file>\n" ;
        return 1;
    }
    char *inputfile = argv[1];
    char *outputfile = argv[2];

    //Read the image file
    Mat image = imread(inputfile);

    //Check if image exists
    if(image.empty()){
        cout << "Error: Could not open image" << endl;
        return 0;
    }

    //Create output image object
    Mat output(image.rows, image.cols, image.type());

    //Acessing image pixels and copy them to the new image
    for(int i=0; i < image.rows; i++){
        for(int j=0 ; j < image.cols; j++)
            output.ptr<Vec3b>(i)[j] = Vec3b(image.ptr<Vec3b>(i)[j][0], image.ptr<Vec3b>(i)[j][1], image.ptr<Vec3b>(i)[j][2]);
    }

    //Save output image
    imwrite(outputfile ,output); 

    //Show image on window
    namedWindow("Output image", WINDOW_NORMAL);
    resizeWindow("Output image", 1050, 650);
    imshow("Output image", output);
    waitKey(0);
    destroyWindow("Output image");   

    return 0;

}


