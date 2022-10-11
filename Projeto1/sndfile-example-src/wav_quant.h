#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>

class WAVQuant {
  private:
    std::vector<short> quant_samples;

  public:
    WAVQuant(const SndfileHandle& sfh) {
      quant_samples.resize(sfh.channels());
    }

    void uniform_scalar_quantization(const std::vector<short>& samples, int num_bits_shift) {
      for (auto s : samples) {
          short t = s >> num_bits_shift;
          quant_samples.push_back(t << num_bits_shift);
      }
    }
    void writetoWavFile(SndfileHandle& sfhOut){
      sfhOut.writef(quant_samples.data(), quant_samples.size());  
    }
};

#endif

