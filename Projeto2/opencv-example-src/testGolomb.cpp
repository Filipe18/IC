#include "Golomb.h"

using namespace std;

int main() {

    Golomb g;
    
    for(int i = -8; i <= 7; i++){
        cout << i << " -> " << g.encode(i,1) << endl;
    }
    
}  