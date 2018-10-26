#include "InputHandler.h"

StatusCode::InputStatus InputHandler::handle(std::vector<std::string> input) {

    //std::vector<string>()input.at(i)
	std::vector<std::string> directions{"north", "south", "east", "west"};

    // Loop through each word
	for(unsigned long i = 0; i < input.size(); i++) {
		if(input[i] == "move") {
			if(++i < static_cast<unsigned long>(input.size()) &&
					std::find(directions.begin(), directions.end(), input[i]) != directions.end()) {
				if(input[i] == directions[0]) // North
					PlayerAction().movePlayer(0, 1);
				else if(input[i] == directions[1]) // South
					PlayerAction().movePlayer(0, -1);
				else if(input[i] == directions[2]) { // East
					PlayerAction().movePlayer(1, 0); }
				else if(input[i] == directions[3]) // West
					PlayerAction().movePlayer(-1, 0);
			} else
				return StatusCode::InputStatus::ERR_INVALID_PARAM;
		} else
			return StatusCode::InputStatus::ERR_INVALID_KEYWORD;
    }

	return StatusCode::InputStatus::SUCCESS;
}
