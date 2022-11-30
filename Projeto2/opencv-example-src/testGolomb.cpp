#include "Golomb.cpp"

using namespace std;

int main() {

    Golomb g(5);
    
    for(int i = -8; i <= 7; i++){
        cout << i << " -> " << g.encode(i) << endl;
    }
    
}  