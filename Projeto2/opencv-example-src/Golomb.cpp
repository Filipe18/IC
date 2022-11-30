#ifndef GOLOMB_H
#define GOLOMB_H

#include "BitStream.h"
#include <math.h>
#include <cstdlib>
#include <bitset>
#include <string>
#include <math.h> 
#include <string>

using namespace std;

/**
 * Class for encoding and decoding values using golomb code.
 */
class Golomb {
    public:
        Golomb();

        /**
         * Golomb Class Constructor
         * @param mvalue value of m that will be used in golomb encoding and decoding .
         */
        Golomb(int mvalue);

        /**
         * Encode a number (positive or negative) using golomb code.
         * @param n Integer number, positive or negative to be encoded.
         * @return encoded string
         * */
        string encode(int n);

        /**
         * Decode a number using golomb code.
         * @param bit_string Bit string to be decode
         * @return the decoded value.
         * */
        int decode(string bit_string);

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
        
    private:
        int m; 
        int b;
};

Golomb::Golomb(){}

Golomb::Golomb(int mValue){
    m = mValue;
    b = ceil(log2(m));
}

string Golomb::encode(int number){
    int q, r, nbits;
    string bit_string, aux, temp; 

    number = map_number(number);
    q = floor(number/m);
    r = number - q*m;

    for (int j = 0; j < q; j++) {
        bit_string += '1';
    }
    bit_string += '0';
    // check if m is a power of 2
    if (ceil(log2(m)) != floor(log2(m))) {

        if (r < pow(2, b) - m){
            nbits = b-1;
        }
        else{
            r += pow(2,b) - m;
            nbits = b;
        }
        aux = bitset<64>(r).to_string();
    }
    else{
        aux = bitset<64>(r).to_string();
        nbits = b;
       
    }
    for (int j = (63 - nbits)+1; j <= 63; j++){
            temp += aux[j];
        }
        bit_string += temp;
    return bit_string;
}

int Golomb::decode(string bit_string){
    int r;
    int q = 0;
    string in_q;

    // Descobrir a posição onde está o primeiro '1'(delimitador)
    // Se tiver na primeira, significa que não há quociente. Se nao tiver na primeira, o quociente acaba na posição anterior à do delimitador
    // Exemplo : '00011110' -> quociente = 000
    int sep = (int) bit_string.find("1");

    for(int i = 0; i < sep; i++){
        q++;        // number of '1' before the first '0'
    }
    
    // remainder code
    int b = floor(log2(m));
    r = stoi(bit_string.substr(sep+1,b), 0, 2); // interpret next b bits as a binary number r'
    if(r >= pow(2, b+1) - m){
        r = stoi(bit_string.substr(sep+1,b+1), 0, 2); // interpret next b+1 bits as a binary number r'
        r = r - pow(2, b+1) + m;
    }

    return unmap_number(q*m + r);
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

#endif