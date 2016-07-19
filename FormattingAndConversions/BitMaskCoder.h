#pragma once
#include "SequenceCoder.h"
#include <vector>

class BitMaskCoder :
	public SequenceCoder
{
public:
	BitMaskCoder();
	~BitMaskCoder();

	std::vector<int> encode_sequence(const std::vector<int>&);

	std::vector<int> decode_sequence(const std::vector<int>&);
};

