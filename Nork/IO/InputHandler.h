#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Player/PlayerAction.h"
#include "../StatusCodes.h"

// Takes vector of input strings and issues commands.
class InputHandler
{
	// Stores input for usage between functions
	std::vector<std::string> input;

	StatusCode::InputStatus move();
public:
	StatusCode::InputStatus handle(std::vector<std::string> input);
};
