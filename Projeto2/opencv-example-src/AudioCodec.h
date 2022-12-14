#ifndef AUDIOCODEC_H
#define AUDIOCODEC_H

#include "Golomb.h"

#include <iostream>
#include <stdio.h>
#include <sndfile.h>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

class AudioCodec{

    public:
        /**
         * @brief Construct a new Audio Codec object
         * 
         */
        AudioCodec();

        /**
         * @brief Construct a new Audio Codec object
         * 
         * @param fileSrc filename path to an audio file
         */
        AudioCodec(const char *fileSrc);

        /**
         * @brief Compress an audio file
         * 
         * @param fileDst filename path to a file to store the encoded value
         * @param num value to choose the order of the predictor that will be use. 
         * Choosing 1, the predictor will only consider the previous value; 2 it will consider the 2 previous values; and choosing 3 will consider the 3 previous values.
         * @param lossy value to choose between lossless (0) and lossy (1) encoding.
         * @param num_bits_shift number of bits to be shifted in the predictor
         */
        void compress(const char *fileDst, int num, bool loosy, int num_bits_shift);

        /**
         * @brief Decompress an audio file

         * @param fileSrc path to a file were the stored enconded value is.
         */
        void decompress(const char *fileSrc);

        /**
         * @brief Lossless Preditor 

         * @param audioSamples vector that contains all the samples of the audio file.
         */    
        void preditor(std::vector<short> audioSamples);

         /**
         * @brief Lossy Preditor 

         * @param audioSamples vector that contains all the samples of the audio file.
         * @param num_bits_shift number of bits to be shifted in the predictor
         */   
        void preditorLossy(vector<short> audioSamples, int num_bits_shift);

    private:
        char* fileSrc;
        SF_INFO sfinfo;
        int ninput;
        std::vector<short> chs = {};
        std::vector<short> rn = {};
};

AudioCodec::AudioCodec(){}

AudioCodec::AudioCodec(const char *fileSrc){
    
    SNDFILE *infile;
    int readcount;
    short ch[2];

	if (! (infile = sf_open (fileSrc, SFM_READ, &sfinfo))) {
        cout << "File doesn't exists" << endl;
        exit(EXIT_FAILURE);
	}
    
    while ((readcount = (int) sf_readf_short (infile, ch, 1)) > 0) {
        chs.push_back(ch[0]);
        chs.push_back(ch[1]);
    }
    
	sf_close (infile) ;  
}

void AudioCodec::compress(const char *fileDst, int num, bool lossy, int num_bits_shift){

    ninput = num;

    if(lossy)
        preditorLossy(chs, num_bits_shift);
    else
        preditor(chs);

    Golomb g(fileDst,'e', 0);

    double m = 0;

    for(int i = 0; i < rn.size(); i++) {
        m += g.map_number(rn[i]);
    }
    m = m/rn.size();

    m = (int) ceil(-1/(log2(m/(m+1))));

    g.setM(m);
    g.encodeM(m);
    g.encodeHeaderSound(sfinfo.frames, sfinfo.samplerate, sfinfo.channels, sfinfo.format, lossy);
    
    if(lossy)
        g.encodeNumBitsShift(num_bits_shift);
    //std::ofstream out_file("rn.txt");
    for(int i = 0; i < rn.size(); i++) {
        
		//out_file << rn[i] << '\n';
        g.encode(rn[i]);
    }
    //out_file.close();
    g.close();

}

void AudioCodec::decompress(const char *fileSrc){

    Golomb g(fileSrc, 'd', 0);

    int m = g.decodeM();

    g.setM(m);

    int headerSoundDecoder[5]; 
    g.decodeHeaderSound(headerSoundDecoder);

    vector<short> resChs;
    vector<short> resl, resr;
    vector<short> resXl, resXr;

    if(headerSoundDecoder[0] == 1){
        int num_bits_shift = g.decodeNumBitsShift();
        for(int i = 0; i < headerSoundDecoder[1]*headerSoundDecoder[4]; i++){
            resChs.push_back(g.decode() << num_bits_shift) ;
        }
    }
    else{
        //std::ofstream out_file("resChs.txt");
        for(int i = 0; i < headerSoundDecoder[1]*headerSoundDecoder[4]; i++){
            resChs.push_back(g.decode());
            //out_file << resChs[i] << '\n';
        }
        //out_file.close();
    }
    
    for(int i = 0; i < resChs.size()-1; i+=2){
        resl.push_back(resChs[i]);          // left channel -> MID Channel
        resr.push_back(resChs[i+1]);        // right channel -> SIDE channel
    }

    g.close();

    vector<short> resXN;
    vector<short> resHatXl, resHatXr; 
    
    if(ninput == 1) {
        resXl.push_back(resl[0]);
        resXr.push_back(resr[0]);
        resXN.push_back(resl[0]);
        resXN.push_back(resr[0]);
        for(int i = 1; i < resl.size(); i++) {
            resXl.push_back((short) resl[i] + resXl[i-1]);
            resXr.push_back((short) resr[i] + resXr[i-1]);
            resXN.push_back(resXl[i]);
            resXN.push_back(resXr[i]);
        }
    }
    else if(ninput == 2) {
        for(int i = 0; i < 2; i++) {
            resHatXl.push_back(0);
            resHatXr.push_back(0);
            resXl.push_back(resl[i]);
            resXr.push_back(resr[i]);
            resXN.push_back(resXl[i]);
            resXN.push_back(resXr[i]);
        }
        for(int i = 2; i < resl.size(); i++) {
            resHatXl.push_back((int) (2*resXl[i-1] - resXl[i-2]));
            resHatXr.push_back((int) (2*resXr[i-1] - resXr[i-2]));
            resXl.push_back((short) resl[i] + resHatXl[i]);
            resXr.push_back((short) resr[i] + resHatXr[i]);
            resXN.push_back(resXl[i]);
            resXN.push_back(resXr[i]);
        }
    }
    else {
        for(int i = 0; i < 3; i++) {
            resHatXl.push_back(0);
            resHatXr.push_back(0);
            resXl.push_back(resl[i]);
            resXr.push_back(resr[i]);
            resXN.push_back(resXl[i]);
            resXN.push_back(resXr[i]);
        }
        for(int i = 3; i < resl.size(); i++) {
            resHatXl.push_back((int) (3*resXl[i-1] - 3*resXl[i-2] + resXl[i-3]));
            resHatXr.push_back((int) (3*resXr[i-1] - 3*resXr[i-2] + resXr[i-3]));
            resXl.push_back((short) resl[i] + resHatXl[i]);
            resXr.push_back((short) resr[i] + resHatXr[i]);
            resXN.push_back(resXl[i]);
            resXN.push_back(resXr[i]);
        }
    }

    SF_INFO sfinfoOut ;
    sfinfoOut.channels = headerSoundDecoder[4];
    sfinfoOut.samplerate = headerSoundDecoder[2];
    sfinfoOut.format = headerSoundDecoder[3];
    sfinfoOut.frames = headerSoundDecoder[1];

    SNDFILE * outfile = sf_open("out.wav", SFM_WRITE, &sfinfoOut);
    sf_count_t count = sf_write_short(outfile, &resXN[0], resXN.size()) ;
    sf_write_sync(outfile);
    sf_close(outfile);
}

void AudioCodec::preditor(std::vector<short> audioSamples){
    
    vector<short> left, right;
    
    for(int i = 0; i < chs.size()-1; i+=2){
        left.push_back((chs[i]+chs[i+1])/2);       // left -> MID Channel
        right.push_back(chs[i]-chs[i+1]);          // right -> SIDE Channel
    }

    vector<short> xnl, xnr;
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

void AudioCodec::preditorLossy(vector<short> audioSamples, int num_bits_shift) {

    vector<short> left, right;
    for(int i = 0; i < chs.size()-1; i+=2){
        left.push_back((chs[i]+chs[i+1])/2);       // left -> MID Channel
        right.push_back(chs[i]-chs[i+1]);          // right -> SIDE Channel
    }

    vector<int> xnr, xnl;
    
    if(ninput == 1) {
        for(int i = 0; i < left.size(); i++) {
            if(i == 0) {
                xnr.push_back(0);
                xnl.push_back(0);
            }
            else {
                xnl.push_back(left[i-1]);
                xnr.push_back(right[i-1]);
            }
            rn.push_back(((left[i]-xnl[i]) >> num_bits_shift) );
            rn.push_back(((right[i]-xnr[i]) >> num_bits_shift) );
            left[i] = (rn[2*i] << num_bits_shift) + xnl[i];
            right[i] = (rn[2*i+1] << num_bits_shift) + xnr[i];
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
            rn.push_back(((left[i]-xnl[i]) >> num_bits_shift) );
            rn.push_back(((right[i]-xnr[i]) >> num_bits_shift) );
            left[i] = (rn[2*i] << num_bits_shift) + xnl[i];
            right[i] = (rn[2*i+1] << num_bits_shift) + xnr[i];
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
            rn.push_back(((left[i]-xnl[i]) >> num_bits_shift) );
            rn.push_back(((right[i]-xnr[i]) >> num_bits_shift) );
            left[i] = (rn[2*i] << num_bits_shift ) + xnl[i];
            right[i] = (rn[2*i+1] << num_bits_shift )  + xnr[i];
        }
    }
}

#endif
