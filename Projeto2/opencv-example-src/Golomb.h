#ifndef GOLOMB_H
#define GOLOMB_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>
#include <cmath>

using namespace std;

class Golomb {
    public:
        string encode(int number){
            if (number < 0){
                number = number + 1;
                string bit_string = aux_encode(abs(number));
                bit_string = invert_bits(bit_string);
                return bit_string;
            }
            return aux_encode(number);
        }
        string aux_encode(int number){

            string bit_string = "";
            for (int i = 31; i >= 0; i--) {
                int k = number >> i;
                if (k & 1)
                    bit_string += "1";
                else
                    bit_string += "0";
            }
            return bit_string;
        }
    
        int decode(string bit_string){
            
            string temp = bit_string;
            // significa que o numero inteiro é negativo, ou seja temos de inverter a bit_string e adicionar 1
            if (bit_string[0] == '1'){
                temp = invert_bits(bit_string);
                int decimal_number = aux_decode(temp) + 1; // obter o decimal sem sinal e somar + 1 após isso
                return 0 - decimal_number;   // retornar o inverso 
            }

            return aux_decode(temp);
        }

        string invert_bits(string bit_string){
            string result = bit_string;
            int len = bit_string.length();
            for(int i = 0; i < len; i++){
                if(bit_string[i] == '0'){
                    result[i] = '1';
                }
                else{
                    result[i] = '0';
                }
            }
            return result;
        }
        int aux_decode(string bit_string){
            int num = stoi(bit_string);

            int number = 0;
            // Initializing base value to 1, i.e 2^0
            int base = 1;
            int temp = num;
            while (temp) {
                int last_digit = temp % 10;
                temp = temp / 10;
                number += last_digit * base;
                base = base * 2;
            }
            return number;
        }        
};

#endif