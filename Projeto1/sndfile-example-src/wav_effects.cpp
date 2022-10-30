#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>
#include <sndfile.hh>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    
    
    size_t nFrames;
    
    constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

   
    
    if(argc < 5) {
		cerr << "Usage: " << argv[0] << " <input file> <output file> <effect> <delay> <eco_attenuation>\n";
		return 1;
	}

	SndfileHandle sfhIn { argv[argc-5] };
	if(sfhIn.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sfhIn.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sfhIn.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

    SndfileHandle sfhOut { argv[argc-4], SFM_WRITE, sfhIn.format(),
	sfhIn.channels(), sfhIn.samplerate() };
	if(sfhOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }


    //efeito, delay, eco_attenuation
    int delay = atoi(argv[argc-2]);   //valor entre 1 e 44100(acho)
    double eco_attenuation = atoi(argv[argc-1]);    //valor entre 0 e 1
    
    string effect(argv[argc-3]);

    
    if(effect.compare("simple_echo") != 0 && effect.compare("multiple_echo") != 0){
        cerr << "Error: Effect must be a string equal to simple_echo or multiple_echo\n";
		return 1;
    }


    if(eco_attenuation < 0 || eco_attenuation > 1 ){
        cerr << "Error: eco_attenuation must be a value between 0 and 1 \n";
		return 1;
    }


       
    

    vector<short> samples(FRAMES_BUFFER_SIZE * sfhIn.channels());
    vector<short> samples_out(FRAMES_BUFFER_SIZE * sfhIn.channels());
    double num_samples = sfhIn.samplerate() * sfhIn.channels();
    cout << num_samples;
    
    while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
        samples.resize(nFrames * sfhIn.channels());
        
        for (int i = 0; i< num_samples; i++){
            if( i >= delay){
                
                if (effect == "simple_echo")
                {
                   
                    samples_out.push_back((samples[i] + eco_attenuation*samples[i - delay])/(1 + eco_attenuation)); // para ecos simples
                }

                else{
                    
                    samples_out.push_back((samples[i] + eco_attenuation*samples_out[i - delay])/(1 + eco_attenuation)); // multiplos ecos
                }
                
            }

            else
                samples_out.push_back(samples[i]);
        }

    }

    sfhOut.writef(samples_out.data(), samples_out.size());
}



    