#include "Output.h"

std::vector <std::string> Output::buffer;
std::vector <int> Output::bufferCodes;

void Output::writeBuffer(std::string str, int code) {
	buffer.push_back(str);
	bufferCodes.push_back(code);
}

std::vector <std::string> Output::readBuffer() {
	return buffer;
}

std::vector <int> Output::readBufferCodes() {
	return bufferCodes;
}

void Output::printBuffer() {
	// TODO: Eventually give context for string contents based on associated buffer code
	for (auto const& val : buffer)
		std::cout << val << std::endl;
}

void Output::clearBuffer() {
	buffer.clear();
}