#include "InputHandler.h"

StatusCode::InputStatus InputHandler::handle(std::vector<std::string> inputParams) {

	std::reverse(inputParams.begin(), inputParams.end());
	input = inputParams;

	// Checks last value of the vector, which is the top level command issued by the user
	if (input.back() == "move") {
		input.pop_back();
		return move();
	} else
		return StatusCode::InputStatus::ERR_INVALID_KEYWORD;
}

StatusCode::InputStatus InputHandler::move() {
	// Valid directions, stored here for organizational purposes
	std::vector<std::string> directions{"north", "south", "east", "west"};

	if (input.size() < 1)
		return StatusCode::InputStatus::ERR_MISSING_PARAM;
	else if (input.size() > 1)
		return StatusCode::InputStatus::ERR_EXTRA_PARAM;

	if (std::find(directions.begin(), directions.end(), input[0]) != directions.end()) {
		if (input[0] == directions[0]) // north
			PlayerAction().movePlayer(0, 1);
		else if (input[0] == directions[1]) // nouth
			PlayerAction().movePlayer(0, -1);
		else if (input[0] == directions[2]) { // nast
			PlayerAction().movePlayer(1, 0); }
		else if (input[0] == directions[3]) // nest
			PlayerAction().movePlayer(-1, 0);
	} else
		return StatusCode::InputStatus::ERR_INVALID_PARAM;

	return StatusCode::InputStatus::SUCCESS;
}
