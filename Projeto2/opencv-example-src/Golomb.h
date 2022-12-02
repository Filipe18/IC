#ifndef GOLOMB_H
#define GOLOMB_H

#include "BitStream.h"
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <math.h> 
#include <string>
#include <vector>

using namespace std;


vector<int> convertToBin(int number, int numBits){
    
    string  bit_string = "";
    vector<int> binaryNum;

    while(number != 0){
        // storing remainder in binary array
        bit_string += to_string(number % 2);
        number = number / 2;
        numBits--;
    }
    while(numBits != 0){
        bit_string += '0';
        numBits--;
    }

    for(int i = bit_string.length() -1 ; i >= 0; i--){
        binaryNum.push_back(bit_string[i] & 1);
    }

    return binaryNum;
}

int convertToInt(vector<int> bit_string, int size){
    int number = 0;
    for(int i = 0; i < size; i++){
        if(bit_string[i] != 0){
            number += pow(2,size-1-i);
        }
    }
    return number;
}
  
/**
 * Class for encoding and decoding values using golomb code.
 */
class Golomb {
    public:
        Golomb();

        /**
         * Construct a new Golomb object
         * 
         * @param filename 
         * @param mode 
         * @param mvalue value of m that will be used in golomb encoding and decoding . 
         */
        Golomb(string filename, char mode, int mvalue);

        /**
         * Encode a number (positive or negative) using golomb code.
         * @param n Integer number, positive or negative to be encoded.
         * @return size of encoded string
         * */
        int encode(int n);

        /**
         * Decode a number using golomb code.
         * @return the decoded value.
         * */
        int decode();

        /**
         * Convert an integer (positive or negative) into positive using golomb technique for signed integers
         * 
         * @param number integer number to be converted
         * @return converted number
         */
        int map_number(int number);

        /**
         * Convert a positive integer to integer using golomb technique for signed integers
         * 
         * @param number integer number to be converted
         * @return converted number
         */
        int unmap_number(int number);

        /**
         * Set value of m
         * @param mValue integer that represents the m
         * */
        void setM(int mValue);

        /**
         * 
         * @param m
         */
        void encodeM(int m);

        /**
         * @brief 
         * 
         * @return int 
         */
        int decodeM();

        /**
         * @brief 
         * 
         * @param nFrames 
         * @param sampleRate 
         * @param channels 
         * @param format 
         * @param lossy 
         */
        void encodeHeaderSound(int nFrames, int sampleRate, int channels, int format, bool lossy);

        /**
         * @brief 
         * 
         */
        void decodeHeaderSound(int header[]);

        /**
         * @brief brief description
         * @param num_bits_shift 
         **/
        void encodeNumBitsShift(int num_bits_shift);

        /**
         * @brief brief description
         * @return 
         **/
        int decodeNumBitsShift();

        /**
         * @brief 
         * 
         */
        void close();

    private:
        BitStream BitStreamFile;
        int m; 
        int b;
};

Golomb::Golomb(){}

Golomb::Golomb(string filename, char mode, int mValue){

    if (mode != 'd' && mode != 'e'){
        cout << "ERROR: invalid mode!" << endl;
        exit(EXIT_FAILURE);
    }
    if (mode == 'd')
        BitStreamFile = BitStream(filename, "r");
    else
        BitStreamFile = BitStream(filename, "w");
    m = mValue;
    b = ceil(log2(m));
}

int Golomb::encode(int number){
    int q, r, nbits, temp;
    int size = 0;
    vector<int> binaryPart;

    number = map_number(number);
    q = floor(number/m);
    r = number - q*m;

    for (int j = 0; j < q; j++) {

        size++;
        BitStreamFile.writeBit(1);
    }
    size++;
    BitStreamFile.writeBit(0);

    // check if m is a power of 2
    if (ceil(log2(m)) != floor(log2(m))) {

        if (r < pow(2, b) - m){
            temp = r;
            nbits = b-1;
        }
        else{
            temp = r + pow(2,b) - m;
            nbits = b;
        }
    }
    else{
        temp = r;
        nbits = b;
    }
    
    binaryPart = convertToBin(temp, nbits); 
    for (int i = 0; i < binaryPart.size(); i++){
        BitStreamFile.writeBit(binaryPart[i]);
    }
    size += nbits;
    return size;
}

int Golomb::decode(){
    
    int r = 0, q = 0;
    int value;
    // Count the number of '1' before the first '0'
    while(true){
        value = BitStreamFile.readBit();
        if(value == 0)
            break;
        q++;
    }
    // check if m is a power of 2
    if (ceil(log2(m)) == floor(log2(m))) {

        vector<int> binary = BitStreamFile.readNbits(b);
        
        //Extract b Msbs of the original word without the first ones and the first zero and calculate R in decimal
        int temp = 0;
        for( int i = b-1; i >= 0; i--){
            if(binary[i] != 0)
                r+= pow(2, temp);
            temp++;
        }
        return unmap_number(m*q + r);
    }
    else{
        int temp = 0;

        //Extract b-1 Msbs of the original word without the first ones and the first zero and calculate R in decimal
        vector<int> binary = BitStreamFile.readNbits(b-1);
        binary[b-1] = 0;
        for (int i = b-2; i >= 0; i--){
            if(binary[i] != 0)
                r+= pow(2, temp);
            temp++;
        } 
        if(r < pow(2, b) - m){
    
            return unmap_number(m*q + r);
        }
        //Extract b Msbs of the original word without the first ones and the first zero and calculate R in decimal
        else{

            binary[b-1] = BitStreamFile.readBit();
            r = 0, temp= 0;
            for (int i = b-1; i >= 0; i--){
                if(binary[i] != 0)
                    r+= pow(2, temp);
                temp++;
            }
            return unmap_number(m*q + r - (pow(2, b) - m)); 
        }
    }
    
    return 0;
    
}

int Golomb::map_number(int number){
    // When number is greater than or equal to zero, the number is mapped to the m-th even number (number*2)
    if (number >= 0){
        return number*2;
    }
    // When the number is less than zero(negative), the number is is mapped to the nth odd number (-2*number - 1 )
    else{
        return abs(number)*2-1;
    }
}

int Golomb::unmap_number(int number){
    if (number % 2 == 0)
        return number/2;
    else
        return (-1)*ceil(number/2)-1;

}

void Golomb::setM(int mValue){
    this->m = mValue;
    b = ceil(log2(m));
}

void Golomb::encodeM(int m){
    vector<int> binary_m = convertToBin(m, 32);
    
    BitStreamFile.writeNbits(binary_m);
}

int Golomb::decodeM(){

    return convertToInt(BitStreamFile.readNbits(32), 32);
}

void Golomb::encodeHeaderSound(int nFrames, int sampleRate, int channels, int format, bool lossy){
    /*
     * Header
     * Golomb m                 -> 32 bits
     * LossyOrLosses            -> 1 bit(0->Lossless, 1->Lossy)
     * Number of samples        -> 32 bits
     * Sample Rate              -> 32 bits
     * Format                   -> 32 bits
     * Channels                 -> 4 bits
     */ 
    vector<int> header, temp;
    if(lossy)
        header.push_back(1);
    else
        header.push_back(0);

    temp = convertToBin(nFrames, 32);
    header.insert(header.end(), temp.begin(), temp.end());
    temp = convertToBin(sampleRate, 32);
    header.insert(header.end(), temp.begin(), temp.end());
    temp = convertToBin(format, 32);
    header.insert(header.end(), temp.begin(), temp.end());
    temp = convertToBin(channels, 4);
    header.insert(header.end(), temp.begin(), temp.end());

    BitStreamFile.writeNbits(header);
}

void Golomb::decodeHeaderSound(int header[]){
        
    header[0] = BitStreamFile.readBit();
    header[1] = convertToInt(BitStreamFile.readNbits(32),32);
    header[2] = convertToInt(BitStreamFile.readNbits(32),32);
    header[3] = convertToInt(BitStreamFile.readNbits(32),32);
    header[4] = convertToInt(BitStreamFile.readNbits(4),4);

}

void Golomb::encodeNumBitsShift(int num_bits_shift){

    vector<int> binary_nbsh= convertToBin(num_bits_shift, 5);
    BitStreamFile.writeNbits(binary_nbsh);
}

int Golomb::decodeNumBitsShift(){
    return convertToInt(BitStreamFile.readNbits(5), 5);
}

void Golomb::close(){
    BitStreamFile.close();
}

#endif