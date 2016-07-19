#include "BitMaskCoder.h"
#include <bitset>



BitMaskCoder::BitMaskCoder()
{
}


BitMaskCoder::~BitMaskCoder()
{
}

std::vector<int> BitMaskCoder::encode_sequence(const std::vector<int>& input)
{
	std::vector<int> output;
	std::bitset<8> current_mask(0);
	int counter = 0;
	int current_mask_pos = 0;
	for (int i = 0; i < input.size(); i++) {
		if (counter == 0) {
			current_mask_pos = i;
			output[current_mask_pos] = 0;
		}
		counter++;
		if (counter == 8) {
			counter = 0;
			output.push_back(current_mask.to_ulong());
			for (int j = 0; j < current_mask.count(); j++) {
				int traverse = current_mask_pos;
			}
			
		}

		if (input[i] != 0){
			current_mask[counter] = 1;
		}
	}

	return output;
}

std::vector<int> BitMaskCoder::decode_sequence(const std::vector<int>& input)
{
	std::vector<int> output;

	return output;
}
