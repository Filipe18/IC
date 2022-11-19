#include "Golomb.h"

using namespace std;

int main() {

    Golomb g;
    for(int i = -5; i <= 5; i++){
        string bit_string = g.encode(i,5);
        cout << bit_string << endl;
        cout << g.decode(bit_string,5) << endl;
    }
    
}  