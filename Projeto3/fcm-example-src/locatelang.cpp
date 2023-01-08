#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

int main(int argc, char* argv[]) {

    if (argc < 6) {
        cerr << "Usage: " << argv[0] << " <file_t> <model_order> <alpha> <window_size> [<file_r>, ...]\n" ;
        exit(EXIT_FAILURE);
    }

    int k = stoi(argv[2]);
    double alpha = atof(argv[3]);
    int window_size = stoi(argv[4]);


    fstream target;
    target.open(argv[1]);

    string segment = "";
    int total = 0;
    char c;

    while (target.get(c)) {
        if (c == '\n' or c == '\t') continue;

        segment += c;
        total++;

        if (segment.length() == (size_t)window_size) {
            map<string, double> language_averages;
            int start_pos = total - window_size;
            int end_pos = total - 1;
            char start_char = segment[0];

            for (int i = 5; i < argc; i++) {
                Fcm fcm(argv[i], k, alpha);
                fcm.processText();
                double distance = fcm.calculateDistanceSegment(segment);
                language_averages[argv[i]] += distance;
            }

            string minLanguage;
            double minDistance = numeric_limits<double>::max();
            for (auto lang : language_averages) {
                if (lang.second < minDistance) {
                    minDistance = lang.second;
                    minLanguage = lang.first;
                }
            }
            cout << "Da posição " << start_pos << "(que corresponde ao char " << start_char <<") até à posição " << end_pos << " a linguagem é " << minLanguage << endl;
            segment = "";
        }
    }

    if (segment.length() > 0) {
        map<string, double> language_averages;
        int start_pos = total - segment.length();
        int end_pos = total - 1;
        char start_char = segment[0];
        
        for (int i = 5; i < argc; i++) {
            Fcm fcm(argv[i], k, alpha);
            fcm.processText();
            double distance = fcm.calculateDistanceSegment(segment);
            language_averages[argv[i]] += distance;
        }

        string minLanguage;
        double minDistance = numeric_limits<double>::max();
        for (auto lang : language_averages) {
            if (lang.second < minDistance) {
                minDistance = lang.second;
                minLanguage = lang.first;
            }
        }
        cout << "Da posição " << start_pos << "(que corresponde ao char " << start_char <<") até à posição " << end_pos << " a linguagem é " << minLanguage << endl;
    }
    return 0;
}