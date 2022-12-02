#include "../Golomb.h"

using namespace std;

int main() {

    Golomb g("test.txt", 'e',5);
    
    for(int i = 0; i < 14; i++){
        cout <<"Encoded value -> ";
        g.encode(i);
        cout << '\n';
    }
    g.close();
    Golomb g1("test.txt",'d',5);

    for(int i = 0; i < 14; i++){
       cout << "Decoded Value -> " << g1.decode() << '\n';
    }
    g1.close();
    
}  