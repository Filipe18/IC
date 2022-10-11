#ifndef WAVHIST_H
#define WAVHIST_H

#include <fstream>
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
		std::ofstream out_file("MID_channel.txt");
		for(auto [value, counter] : map_avg)
			out_file << value << '\t' << counter << '\n';
		out_file.close();
	}

	void difference(){
		std::ofstream out_file("SIDE_channel.txt");
		for(auto [value, counter] : map_diff)
			out_file << value << '\t' << counter << '\n';
		out_file.close();
	}
};

#endif

