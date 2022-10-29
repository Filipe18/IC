#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "BitStream.h"

using namespace std;

int main(int argc, char *argv[]) {

	if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <input file> <output file>\n";
		return 1;
	}

    ifstream input (argv[1], ios::in);
    string output = argv[2];

    //-> true if the ifstream has no errors, false otherwise.
    if(!input){
        cerr <<"Input file "<< argv [1] <<"could not be opened \n";
        return 1;
    }

    //guardar todos os 0's e 1's para uma string
    string aux;
    //Método que extrai os chars contidos no ficheiro e vai guarda-los na string aux
    getline(input,aux);
    input.close();

    //cout << "\ndebugging1\n";
    //outputF -> objecto BitStream para escrita no ficheiro contido na variavel output
    BitStream outputF(output, "w");
    
    //cout << "debugging2";

    
    std::vector<int> bitArr;
   
    // '0' e '1' -> 0, 1
    for(int i = 0; (unsigned)i < aux.length(); i++){ 
        bitArr.push_back(aux[i] & 1);
    }
    
    //Escrever os bits anteriormente guardados no array para o outputF
    outputF.writeNbits(bitArr);
    outputF.close();

    return 0;
} ; 