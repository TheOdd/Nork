#pragma once

#include <iostream>
#include <string>
#include <vector>

class Input
{
public:
	std::vector <std::string> getActions();
private:
	std::string getInput();
	std::vector <std::string> splitString(std::string str, char delim);
};
