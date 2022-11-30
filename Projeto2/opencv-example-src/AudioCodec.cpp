#ifndef AUDIOCODEC_H
#define AUDIOCODEC_H

#include <iostream>
#include <stdio.h>
#include <sndfile.h>
#include <math.h>
#include <vector>
#include <map>
#include <Golomb.h>

using namespace std;

class AudioCodec{

    public:
        /**
         * @brief Construct a new Audio Codec object
         * 
         * @param fileSrc 
         */
        AudioCodec(const char *fileSrc);

        /**
         * @brief 
         * 
         * @param fileDst 
         */
        void compress(const char *fileDst);

        /**
         * @brief 
         * 
         * @param audioSamples 
         */
        void preditor(std::vector<short> audioSamples);

    private:
        char* fileSrc;
        SF_INFO sfinfo;
        int ninput;
        std::vector<short> chs = {};
        std::vector<short> rn = {};
}

AudioCodec::AudioCodec(const char *fileSrc){
    
    SNDFILE *infile;
    int readcount;
    short ch[2];

	if (! (infile = sf_open (filename, SFM_READ, &sfinfo))) {
        cout << "File doesn't exists" << endl;
        exit(EXIT_FAILURE);
	}
    
    while ((readcount = (int) sf_readf_short (infile, ch, 1)) > 0) {
        chs.push_back(ch[0]);
        chs.push_back(ch[1]);
    }
    
	sf_close (infile) ;  
}

void AudioCodec::compress(const char *fileDst, int num){

    ninput = num;
    preditor(chs);

    Golomb g(fileDst, 0);

    double m = 0;

    for(int i = 0; i < rn.size(); i++) {
        m += g.map_number(rn[i]);
    }
    m = m/rn.size();

    m = (int) ceil(-1/(log2(m/(m+1))));

    g.setM(m);

}

void AudioCodec::preditor(std::vector<short> audioSamples){
    
    vector<short> side_channel;
    vector<short> mid_channel;
    for(int i = 0; i < chs.size()-1; i+=2){
        left.push_back(chs[i]);
        right.push_back(chs[i+1]);
    }

    vector<short> xn_side, xn_mid;
    if(ninput == 1) {
        for(int i = 0; i < left.size(); i++) {
            if(i == 0) {
                xnl.push_back(0);
                xnr.push_back(0);
            }
            else {
                xnl.push_back(left[i-1]);
                xnr.push_back(right[i-1]);
            }
            rn.push_back(left[i]-xnl[i]);
            rn.push_back(right[i]-xnr[i]);
        }
    }
    else if(ninput == 2) {
        for(int i = 0; i < left.size(); i++) {
            if(i == 0 || i == 1) {
                xnl.push_back(0);
                xnr.push_back(0);
            }
            else {
                xnl.push_back(2*left[i-1] - left[i-2]);
                xnr.push_back(2*right[i-1] - right[i-2]);
            }
            rn.push_back(left[i]-xnl[i]);
            rn.push_back(right[i]-xnr[i]);
        }
    }
    else {
        for(int i = 0; i < left.size(); i++) {
            if(i == 0 || i == 1 || i == 2) {
                xnl.push_back(0);
                xnr.push_back(0);
            }
            else {
                xnl.push_back(3*left[i-1] - 3*left[i-2] + left[i-3]);
                xnr.push_back(3*right[i-1] - 3*right[i-2] + right[i-3]);
            }
            rn.push_back(left[i]-xnl[i]);
            rn.push_back(right[i]-xnr[i]);
        }
    }
}
#endif
