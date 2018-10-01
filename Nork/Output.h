#pragma once

#include <vector>
#include <string>
#include <iostream>

class Output
{
public:
	void writeBuffer(std::string, int code);
	std::vector <std::string> readBuffer();
	std::vector <int> readBufferCodes();
	void printBuffer();
	void clearBuffer();
private:
	static std::vector <std::string> buffer;
	static std::vector <int> bufferCodes;
};
