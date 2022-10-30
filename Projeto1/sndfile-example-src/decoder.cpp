#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "BitStream.h"

using namespace std;

int main(int argc, char *argv[]) {	

    if (argc < 3) {	
        cerr << "Usage: " << argv[0] << " <input file> <output file>\n" ;
        return 1;
    }

    //input -> Objeto para fazer a leitura do ficheiro
    BitStream input(argv[1], "r");
    
    //Escrita dos bits que foram lidos
    ofstream output(argv[2], ios::out);

    //-> true if the ofstream has no errors, false otherwise.
    if (!output) {
        cerr <<"Output file "<< argv[2] <<"could not be opened \n";
        return 1 ;
    }
    
    //read the bits from the input file
    vector<int> bitArr = input.readNbits(input.getSize()*8);
    input.close();

    //write the bits to the output file
    unsigned int i = 0;
    while(i < bitArr.size()){
        output << bitArr[i];
        i++;
    }

    output.close();
    
    return 0;
}