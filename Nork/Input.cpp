#include "Input.h"

std::vector <std::string> Input::getActions() {
	std::string input = getInput();
	return splitString(input, ' ');
}

std::string Input::getInput() {
	std::string input;
	std::getline(std::cin, input);
	return input;
}

// Helper function to split string into individual "words" to be parsed later
std::vector <std::string> Input::splitString(std::string str, char delim) {
	while (str.back() == delim)
		str.pop_back();
	while (str.front() == delim)
		str = str.substr(1, str.length());
	std::vector <std::string> resultVector;
	unsigned int lastIndex = 0;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == delim) {
			resultVector.push_back(str.substr(lastIndex, i - lastIndex));
			for (; i < str.length() - 1 && str[i + 1] == delim; i++);
			lastIndex = i + 1;
		}
	}
	resultVector.push_back(str.substr(lastIndex, str.length() + 1 - lastIndex));
	return resultVector;
}
