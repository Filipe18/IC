// g++ BitStream.h Golomb.h AudioCodec.h tests/testAudioCodec.cpp -o tests/testAudioCoded -lsndfile

#include "../AudioCodec.h"

using namespace std;

int main(int argc, char* argv[]) {

   if(argc != 2){
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1; 
    }
    char *inputfile = argv[1];

    AudioCodec c(inputfile);
    
    int op1 = -1;
    while(!(op1 == 0 || op1 == 1)) {
        cout << "Choose codec option (0 for lossless or 1 for lossy): ";
        cin >> op1;
    }
    
    int op2 = 0;
    while(op2 < 1 || op2 > 3) {
        cout << "Choose the predictor (1, 2 or 3): ";
        cin >> op2;
    }
    
    int num_bits_shift = -1;
    if(op1 == 1){
        while(num_bits_shift < 0 || num_bits_shift > 15) {
            cout << "Choose number of bits to shift: ";
            cin >> num_bits_shift;
        }
    }
    c.compress("compress.txt", op2, op1, num_bits_shift);

    c.decompress("compress.txt");
    
}  