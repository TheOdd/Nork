#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Player/PlayerAction.h"

// Takes vector of input strings and issues commands.
class InputHandler
{
public:
	void handle(std::vector<std::string> keywords);
};
