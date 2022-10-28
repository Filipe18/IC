#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

class BitStream {
    private:
    std::fstream file;
    int size; //tamanho do ficheiro
    std::string mode; //tipo de ficheiro, escrita ou leitura
    std::string name;
    //Array de bits
    std::vector<int> bitArr; 
    //Array que contem varios arrays de 8 bits
    std::vector<std::vector<int>> byteArr; 
    //variavel que contem a posicao do bit atual no array de bits
    int pointerBit;
    //variavel que contem a posicao do array atual no array de bytes
    int pointerByte;   

    public:
        BitStream(std::string filename, std::string tipo){ 
            if(tipo == 'w'){ // write, mode = 0
                file = fstream(filename, ios::binary | ios::out);
                pointerBit = 0;
                pointerByte = 0;
            }else if(tipo == 'r'){  // read, mode = 1
                file = fstream(filename, std::ios::binary | std::ios::in);
                pointerBit = 0;
                file.seekg(0, ios::end);
                size = file.tellg();
                file.seekg(0, ios::beg);
            }else{
                throw runtime_error("Wrong file open mode");
            }
        }

        //Função para ler um byte (=) 8 bits
        // e guardar num array
        std::vector<int> getByte(char byte){
            //bitArr[0] = bit7
            //bitArr[1] = bit6
            //bitArr[2] = bit5
            std::vector<int> arrayBits;

            for(int i = 7; i >= 0; i--){
                arrayBits.push_back((byte >> i) & 0x01);
            }
            return arrayBits;
        }

        int readBit(){ 
            if(mode == 0) throw runtime_error("Cannot read in 'w' mode");
            if(pointerBit == 0){
                char byte;
                file.read(reinterpret_cast<char*>(&byte), 1);
                bitArr = getByte(byte);
            }

            int bit = bitArr[pointerBit];
            pointerBit = (pointerBit + 1) % 8;
            
            return bit;
        }

        std::vector<int> readNbits(int n){
            if(mode == "w") throw runtime_error("Cannot read in 'w' mode");
            
            std::vector arrayNbits;
        
            for(int i = 0; i < n; i++){
                if(pointerBit == 0){
                    char byte;
                    file.read(reinterpret_cast<char*>(&byte), 1);
                    bitArr = getByte(byte);
                }
                arrayNbits.push_back(bitArr[pointerBit]);
                pointerBit == pointerBit + 1;
                //caso o ponteiro seja igual a 8 significa que
                //foi lido 1 byte, logo tenho de ler o próximo byte
                if(pointerBit == 8){
                    pointerBit = 0;
                }
            }
            return arrayNbits;
        }

         void writeBit(char bit){
            if(mode == 1) throw runtime_error("Cannot write in 'r' mode");
            if(pointer == 1){
                buffer |= (bit & 0x01);
                file.write(reinterpret_cast<char*>(&buffer), 1);
                buffer = 0;
                pointer = 8;
                return;
            }       
            pointer--;
            buffer |= ((bit & 0x01) << pointer);
        }  

        void writeNbits(char* bits, int n){    
            if(mode == 1) throw runtime_error("Cannot write in 'r' mode");
            for(int i = 0; i < n; i++){
                writeBit(bits[i]);
            }
        }      
};

#endif