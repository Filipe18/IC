#include "Golomb.h"

using namespace std;

int main() {

    Golomb g;
    cout << g.encode(111111) << endl;
    cout << g.encode(-8) << endl;
    cout << g.decode("1100") << endl;
    cout << g.decode("0100") << endl;
}  