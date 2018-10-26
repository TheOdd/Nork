#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Player/PlayerAction.h"
#include "../StatusCode.h"

// Takes vector of input strings and issues commands.
class InputHandler
{
public:
	StatusCode::InputStatus handle(std::vector<std::string> keywords);
};
