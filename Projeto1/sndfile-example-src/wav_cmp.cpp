#include <iostream>
#include <vector>
#include <sndfile.hh>
#include <cmath>

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

	if(argc < 3) {
		cerr << "Usage: " << argv[0] << " <original file> <compressed file>\n";
		return 1;
	}

	SndfileHandle sndOriginalFile { argv[argc-2] };
    SndfileHandle sndCompressedFile { argv[argc-1] };
	if(sndOriginalFile.error() || sndCompressedFile.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	if((sndOriginalFile.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV || 
        (sndCompressedFile.format() & SF_FORMAT_TYPEMASK) != SF_FORMAT_WAV) {
		
        cerr << "Error: file is not in WAV format\n";
		return 1;
	}

	if((sndOriginalFile.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16 ||
        (sndCompressedFile.format() & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {

		cerr << "Error: file is not in PCM_16 format\n";
		return 1;
	}

	//files must have same number of samples
    if((sndOriginalFile.samplerate() * sndOriginalFile.channels()) != (sndCompressedFile.samplerate() * sndCompressedFile.channels())){
        cerr << "files do not have the same number of samples\n";
        return 1;
    }

    double num_samples = sndOriginalFile.samplerate() * sndOriginalFile.channels();
    double Ex = 0, Er = 0, SNR = 0, absolute_error = 0, temp_error = 0;
	size_t nFrames;
    
	vector<short> OriginalFile_samples(FRAMES_BUFFER_SIZE * sndOriginalFile.channels());
    vector<short> CompressedFile_samples(FRAMES_BUFFER_SIZE * sndCompressedFile.channels());

	while((nFrames = sndOriginalFile.readf(OriginalFile_samples.data(), FRAMES_BUFFER_SIZE),
			(nFrames = sndCompressedFile.readf(CompressedFile_samples.data(), FRAMES_BUFFER_SIZE)))) {

		OriginalFile_samples.resize(nFrames * sndOriginalFile.channels());
		CompressedFile_samples.resize(nFrames * sndCompressedFile.channels());

        for(int i=0;i<num_samples; i++){
            Ex += pow(OriginalFile_samples[i],2);
			Er += pow(CompressedFile_samples[i],2);
			temp_error = abs(OriginalFile_samples[i] - CompressedFile_samples[i]);
            if(temp_error > absolute_error)
                absolute_error = temp_error;
        }
	}
    
	SNR = 10 * log10((Ex/Er));
    cout << "SNR" << " = " << SNR << " db " << '\n';
	cout << "Maximum absolute error" << " = " << absolute_error << '\n';
	return 0;
}

