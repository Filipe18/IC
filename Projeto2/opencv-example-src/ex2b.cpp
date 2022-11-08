#include <iostream>
#include <opencv2/opencv.hpp>




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

    Mat img = imread(inputfile);


    //Check if image exists
    if(img.empty()){
        cout << "Error: Could not open image" << endl;
        return 1;
    }

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


