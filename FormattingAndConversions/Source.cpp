#include <iostream>
#include <string>
#include <vector>
#include <bitset>
const char CODING_SYMBOL = 27;

using namespace std;

vector<bool> string_to_bits(const string& input) {
	vector<bool> output;
	for (auto c : input) {
		bitset<8> bits(c);
		for (int i = 7; i >= 0; i--) {
			//bits are stored from back to front so i reverse traverse the array
			//this is only for display, in real life we dont need this
			output.push_back(bits[i]);
		}
	}
	return output;
}

void print_bit_vector(const vector<bool>& bits) {
	int counter = 0;
	for (auto bit : bits) {
		if (counter % 8 == 0 && counter != 0)
			cout << " ";
		cout << bit;
		counter++;
	}
}

vector<int> null_suppression_encode(const vector<int>& input) {
	//encodes sequences of 5 or more 0 symbols
	vector<int> output;
	int counter = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 0) {
			counter++;
		}
		if(input[i] != 0 || i == input.size() -1){
			if (counter > 1 && counter < 5) {
				for (int j = 0; j < counter; j++) {
					output.push_back(0);
				}
			}

			if(counter >= 5) {
				output.push_back(CODING_SYMBOL);
				output.push_back(counter);
			}

			counter = 0;
			output.push_back(input[i]);
		}

	}
	cout << "compression " << (double)output.size() / (double)input.size() << " %\n";
	return output;
}

vector<int> null_suppression_decode(const vector<int>& input) {
	vector<int> output;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == CODING_SYMBOL) {
			for (int j = 1; j <= input[i + 1]; j++) {
				output.push_back(0);
			}
			i += 1;
		}
		else {
			output.push_back(input[i]);
		}
	}
	return output;
}

int main() {
	vector<int> test;
	int temp;
	for (int i = 0; i < 10; i++) {
		cin >> temp;
		test.push_back(temp);
	}
	//cout << test.size();
	for (auto n : null_suppression_decode(null_suppression_encode(test))) {
		cout << n << " ";
	}
	return 0;
}