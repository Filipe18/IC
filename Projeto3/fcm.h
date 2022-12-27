#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Fcm
{
private:
    
    map<string, map<char, int>> model;

    vector<char> alphabet;

    int k;

    double alpha;

    int total;

    string file;
      
    fstream f;

public:

    Fcm(){}

    // Constructor for the FCM class
    Fcm(string file, int k, double alpha)
    : file(file), k(k), alpha(alpha)
{
    this->k = k;
    this->alpha = alpha;
    this->file = file;
    this->total = 0;
}

    void openfile(){

        if(not file.empty()){
            f.open(file);
        }
        else{
            cout << "Could not open input file!" << endl;
        }
    }
    void processText(){
        // Clear the model and alphabet from any previous processing
        model.clear();
        alphabet.clear();

        // Create an empty context of size k
        string context(k, ' ');

        // Read characters from the input file stream one by one until the end of the file is reached
        char c;
        while (f.get(c)){
            
            context = context.substr(1) + c;
            if (find(alphabet.begin(), alphabet.end(), c) == alphabet.end())
                alphabet.push_back(c);

            // Update the context count
            if (model.count(context) > 0){
                model[context][c]++;
            }
            else{
                map<char, int> empty;
                model[context] = empty;
                model[context][c]++;
            }
            // Update the count of all other symbols in the context
            for (auto symbol : context)
            {
                if (symbol != c)
                {
                    model[context][symbol]++;
                }
            }
            // Increment the total number of contexts
            total++;
        }
    }

    double calculateEntropy(){

        double totalEntropy = 0;
    
        // Iterate through all contexts in the model
        for (auto it = model.begin(); it != model.end(); it++)
        {
            string context = it->first;
            map<char, int> symbolCounts = it->second;
   
            double contextEntropy = 0;

            // Calculate the probability of each symbol in the alphabet given the context
            for (auto symbol : alphabet)
            {
                int count = symbolCounts[symbol];
                
                double probability = (count + alpha) / (symbolCounts.size() + alpha * alphabet.size());
                contextEntropy += -probability * log2(probability);

            }

            totalEntropy += contextEntropy * symbolCounts.size() / total;

        }

        return totalEntropy;
    }

    void close(){

        if(f.is_open()){
            f.close();
        }
    }
};