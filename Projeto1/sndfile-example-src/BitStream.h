#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class BitStream {
    private:
    //nome do ficheiro
    std::string name;
    std::fstream file;
    //tamanho do ficheiro
    int size;
    //tipo de ficheiro -> escrita ou leitura       
    std::string mode;  
    //Array de bits
    std::vector<int> bitArr; 
    //variavel que contem a posicao do bit atual no array de bits
    int pointerBit;

    public:
        BitStream(std::string filename, std::string tipo){ 
            name = filename;
            mode = tipo;
            if(tipo == "w"){ // write, mode = 0
                file.open(name, ios::binary | ios::out);
                pointerBit = 0;
            }else if(tipo == "r"){  // read, mode = 1
                file.open(name, std::ios::binary | std::ios::in);
                pointerBit = 0;
                size = getSize();
            }else{ 
                std::cout << "Incorrect mode for file" << std::endl;
                //throw runtime_error("Wrong open mode file");
            }
        }

        int readBit(){ 
            if(mode == "w") throw runtime_error("Cannot read in 'w' mode");
            if(pointerBit == 0){
                char byte;
                file.read((&byte), 1);
                bitArr = getBit(byte);
            }

            int bit = bitArr[pointerBit];
            pointerBit = (pointerBit + 1) % 8;
            
            return bit;
        }

        std::vector<int> readNbits(int n){
            if(mode == "w") throw runtime_error("Cannot read in 'w' mode");
            
            std::vector<int> arrayNbits;
        
            for(int i = 0; i < n; i++){
                if(pointerBit == 0){
                    char byte;
                    file.read(&byte, 1);
                    bitArr = getBit(byte);
                }
                arrayNbits.push_back(bitArr[pointerBit]);
                pointerBit++;
                //caso o ponteiro seja igual a 8 significa que
                //foi lido 1 byte, logo tenho de ler o próximo byte
                if(pointerBit == 8){
                    pointerBit = 0;
                }
            }
            return arrayNbits;
        }

         void writeBit(int bit){
            if(mode == "r") throw runtime_error("Cannot write in 'r' mode");    
            //ver se temos 1 byte
            //caso sim, escrever no ficheiro
            if(pointerBit == 8){
                char byte = getByte(bitArr);
                file.write((&byte), 1);            
                pointerBit = 0;//reset no ponteiro
            }
            //se o ponteiro é 0, entao é necessario 
            //inicializar o array, pois só foi referido O ARRAY E NAO INICIALIZADO
            if(pointerBit == 0){
                bitArr = std::vector<int>(8);
            }
            //Adicionar ao array o bit que se pretende escrever
            bitArr[pointerBit] = bit;
            pointerBit++;
        }  

        void writeNbits(std::vector<int> array){    
            if(mode == "r") throw runtime_error("Cannot write in 'r' mode");
            
            int size = array.size();

            //for para percorrer todos os bits
            for(int i = 0; i < size; i++){
                if(pointerBit == 8){
                    char byte = getByte(bitArr);
                    file.write((&byte), 1);            
                    pointerBit = 0;//reset no ponteiro
                }
                //se o ponteiro é 0, entao é necessario 
                //inicializar o array, visto que só foi 
                if(pointerBit == 0){
                    bitArr = std::vector<int>(8);
                }
                //Adicionar ao array os bits que se pretende escrever no ficheiro
                bitArr[pointerBit] = array[i];
                pointerBit++;
            }  
        }

        //Função para ler um byte (=) 8 bits
        //e guardar num array
        std::vector<int> getBit(char byte){
            //bitArr[0] = bit7
            //bitArr[1] = bit6
            std::vector<int> arrayBits;

            for(int i = 7; i >= 0; i--){
                arrayBits.push_back((byte >> i) & 0x01);
            }
            return arrayBits;
        }      

        //funcao para obter um byte apartir do array de bits
        char getByte(std::vector<int> array){
            char byte = 0;
            int counter = 7;
            for(int i = 0; i < 8; i++){
                byte |= array[i] << counter;
                counter--;
            }
            return byte;
        }

        int getSize() {
            int size;
            file.seekg(0, std::ios::end);
            size=file.tellg();
            file.seekg(0, std::ios::beg);
            return size;
        }


        // Escreve o que resta no aray no ficheiro
        void close(){
            char byte = getByte(bitArr);
            file.write(&byte, 1);
            file.close();
        }
};

#endif