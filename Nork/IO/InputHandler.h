#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Player/PlayerAction.h"
#include "../StatusCodes.h"
#include "../Constants.h"

// Takes vector of input strings and issues commands.
class InputHandler
{
	// Stores input for usage between functions
	std::vector<std::string> input;

	StatusCode::Code move();
	StatusCode::Code quit();
	StatusCode::Code look();
public:
	StatusCode::Code handle(std::vector<std::string> input);
};
