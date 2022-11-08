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



