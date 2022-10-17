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
    fstream file;
    int size; //tamanho do ficheiro
    unsigned char buffer; // contem 8 bits
    int pointer; // goes from 0 to 7
    int mode;   // 0-> write && 1 -> read

    public:
        BitStream();

        BitStream(const char *filename, char tipo);

        void writeBit(char bit);

        unsigned char readBit();

        void writeNbits(char* bits, int n);

        void readNbits();
};

#endif