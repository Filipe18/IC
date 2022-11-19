#ifndef GOLOMB_H
#define GOLOMB_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

class Golomb {
    public:
        string encode(int number, int m){
            
            int q, r;
            string bit_string, aux, temp; 

            // swith signed integers we need to perform some changes:
            // When number is greater than or equal to zero, the number is mapped to the m-th even number (number*2)
            if ( number >= 0){
                number *= 2;
            }
            // When the number is less than zero(negative), the number is is mapped to the nth odd number (-2*number - 1 )
            else{
                number = -(number*2) - 1;
            }
            q = floor(number/m);
            r = number - q*m;

            for (int j = 0; j < q; j++) {
                bit_string += '1';
            }
            bit_string += '0';
            int b = floor(log2(m));
            // check if m is a power of 2
            if ((log2(m) - b) != 0) {
                int n_bits;

                if (r < pow(2, b+1) - m){
                    n_bits = b;
                }
                else{
                    r += pow(2,b+1) - m;
                    n_bits = b + 1;
                }
                aux = bitset<64>(r).to_string();
                for (int j = (63 - n_bits)+1; j <= 63; j++){
                    temp += aux[j];
                }
                bit_string += temp;
            }
            else{
                aux = bitset<64>(r).to_string();
                for (int j = (63 - b)+1; j <= 63; j++){
                    temp += aux[j];
                }
                bit_string += temp;
            }
            return bit_string;
        }

        int decode(string bit_string, int m){

            int r;
            int q = 0;
            string in_q;

            // Descobrir a posição onde está o primeiro '0'(delimitador)
            // Se tiver na primeira, significa que não há quociente. Se nao tiver na primeira, o quociente acaba na posição anterior à do delimitador
            // Exemplo : '11101110' -> quociente = 111
            int sep = (int) bit_string.find("0");

            for(int i = 0; i < sep; i++){
                q++;        // number of '1' before the first '0'
            }
            
            // remainder code
            int b = floor(log2(m));
            r = stoi(bit_string.substr(sep+1,b), 0, 2); // interpret next b bits as a binary number r'
            if(r >= pow(2, b+1) - m){
                r = stoi(bit_string.substr(sep+1,b+1), 0, 2); // // interpret next b+1 bits as a binary number r'
                r = r - pow(2, b+1) + m;
            }
            int number = q*m + r;
            if( number % 2 == 0){
                return number/2;
            }
            else{
                return (-number - 1)/2;
            }
        }

};

#endif