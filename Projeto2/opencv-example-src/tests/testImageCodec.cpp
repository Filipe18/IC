// g++ BitStream.h Golomb.h ImageCodec.h tests/testImageCodec.cpp -o tests/test_ImageCodec  $(pkg-config --libs --cflags opencv4)
#include "../ImageCodec.h"

using namespace std;

int main(int argc, char* argv[]) {

   if(argc != 2){
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1; 
    }
    char *inputfile = argv[1];

    ImageCodec c(inputfile);
    
    c.compress("compressImage.bin");

    c.decompress("compressImage.bin");
    
}  