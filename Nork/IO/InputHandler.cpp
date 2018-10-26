#include "InputHandler.h"

void InputHandler::handle(std::vector<std::string> input) {

    //std::vector<string>()input.at(i)
	std::vector<std::string> directions{"north", "south", "east", "west"};

    // Loop through each word
    for(unsigned long i = 0; i < static_cast<unsigned long>(input.size()); i++) {
		if(input.at(i) == "move") {
			if(++i < static_cast<unsigned long>(input.size()) &&
					std::find(directions.begin(), directions.end(), input.at(i)) != directions.end()) {
				if(input.at(i) == directions.at(0)) // North
					PlayerAction().movePlayer(0, 1);
				else if(input.at(i) == directions.at(1)) // South
					PlayerAction().movePlayer(0, -1);
				else if(input.at(i) == directions.at(2)) { // East
					PlayerAction().movePlayer(-1, 0); }
				else if(input.at(i) == directions.at(3)) // West
					PlayerAction().movePlayer(1, 0);
            } else {
                // error
            }
        }
    }
}
