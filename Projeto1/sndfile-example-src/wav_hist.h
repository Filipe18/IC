#ifndef WAVHIST_H
#define WAVHIST_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>

class WAVHist {
  private:
	std::vector<std::map<short, size_t>> counts;
	std::map<short, size_t> map_avg, map_diff;

  public:
	WAVHist(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	}

	void update(const std::vector<short>& samples) {
		size_t n { };
		for(auto s : samples)
			counts[n++ % counts.size()][s]++;

		if(counts.size() == 2){
			for(size_t i = 0; i < samples.size(); i+=2){
				map_avg[(samples[i] + samples[i+1])/2]++;
				map_diff[(samples[i] - samples[i+1])/2]++;
			}
		}
	}

	void dump(const size_t channel) const {
		for(auto [value, counter] : counts[channel])
			std::cout << value << '\t' << counter << '\n';
	}

	void average(){
		std::cout << "Histogram of the average of the channels" << '\n';
		for(auto [value, counter] : map_avg)
			std::cout << value << '\t' << counter << '\n';
	}

	void difference(){
		std::cout << "Histogram of the difference of the channels" << '\n';
		for(auto [value, counter] : map_diff)
			std::cout << value << '\t' << counter << '\n';
	}
};

#endif

