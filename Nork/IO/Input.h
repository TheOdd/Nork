#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Input
{
public:
	std::vector <std::string> getInput();
private:
	std::vector <std::string> splitString(std::string str, char delim);
	std::vector <std::string> toLowerCase(std::vector <std::string> convert);
};
