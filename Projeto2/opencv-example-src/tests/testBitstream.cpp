//g++ BitStream.h tests/testBitstream.cpp -o tests/testbitstream 

#include "../BitStream.h"
#include "vector"

using namespace std;

int main() {

    BitStream bs("test_bitstream.txt","w");
    
    vector<int> ola = {1,0,0,0,0,0,0};
    bs.writeNbits(ola);
    
    ola = {0,1,1,1,1,1,1,1};
    bs.writeNbits(ola);
    
    bs.close();
    BitStream bs1("test_bitstream.txt","r");

    int ola1 = bs1.readBit();
    cout << ola1;
    ola = bs1.readNbits(6);

    for(int i = 0; i < 7; i++){
       cout << ola[i];
    }
    cout << '\n';
    
    ola = bs1.readNbits(8);

    for(int i = 0; i < 8; i++){
       cout << ola[i];
    }
    cout << '\n';
    
}  