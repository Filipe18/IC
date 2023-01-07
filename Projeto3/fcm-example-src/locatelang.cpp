#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

int main(int argc, char* argv[]) {

    if (argc < 5) {
        cout << "Wrong number of arguments!" << endl;
        exit(EXIT_FAILURE);
    }

    int k = stoi(argv[2]);
    double alpha = atof(argv[3]);
    int window_size = stoi(argv[4]);
    string texts[] = {
        "textos/dutch.txt", "textos/eng.txt", "textos/esp.txt",
        "textos/fin.txt",   "textos/fr.txt",  "textos/ger.txt",
        "textos/ita.txt",   "textos/pol.txt", "textos/pt.txt",
        "textos/swe.txt"};

    string language[] = {"dutch","eng","esp","fin","fr","ger","ita","pol","pt","swe"};

    // Abre o arquivo de texto a ser processado
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

            for (int i = 0; i < 10; i++) {
                string temp = language[i];
                Fcm fcm(texts[i], k, alpha);
                fcm.processText();
                double distance = fcm.calculateDistanceSegment(segment);
                language_averages[temp] += distance;
            }

            string minLanguage;
            double minDistance = numeric_limits<double>::max();
            for (auto lang : language_averages) {
                if (lang.second < minDistance) {
                    minDistance = lang.second;
                    minLanguage = lang.first;
                }
            }
            cout << "Da posição " << start_pos << " até à posição " << end_pos << " a linguagem é " << minLanguage << endl;
            segment = "";
        }
    }
}