#include <iostream>
#include "fcm.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 4){
        cout << "Wrong number of arguments!" << endl;
        exit(EXIT_FAILURE);
    }

    Fcm fcm(argv[1], stoi(argv[2]), atof(argv[3]));

    fcm.openfile();

    fcm.processText();

    double entropy = fcm.calculateEntropy();

    cout << "Entropy: " << entropy << endl;

    fcm.close();
        
    
    return 0;
}

