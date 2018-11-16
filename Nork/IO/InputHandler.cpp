#include "InputHandler.h"

StatusCode::Code InputHandler::handle(std::vector<std::string> inputParams) {

	std::reverse(inputParams.begin(), inputParams.end());
	input = inputParams;

	// Checks last value of the vector, which is the top level command issued by the user
	if (input.back() == "move") {
		input.pop_back();
		return move();
	} else if (input.back() == "quit")
		return quit();
	else if (input.back() == "look")
		return look();
	else
		return StatusCode::InputStatus::INVALID_KEYWORD;
}

StatusCode::Code InputHandler::move() {
	// Valid directions, stored here for organizational purposes
	std::vector<std::string> directions = {"north", "south", "east", "west"};

	if (input.size() < 1)
		return StatusCode::InputStatus::MISSING_PARAM;
	else if (input.size() > 1)
		return StatusCode::InputStatus::EXTRA_PARAM;

	if (std::find(directions.begin(), directions.end(), input[0]) != directions.end()) {
		if (input[0] == directions[NorkConstants::NORTH]) // North
			PlayerAction::movePlayer(NorkConstants::NORTH);
		else if (input[0] == directions[NorkConstants::SOUTH]) // South
			PlayerAction::movePlayer(NorkConstants::SOUTH);
		else if (input[0] == directions[NorkConstants::EAST]) // East
			PlayerAction::movePlayer(NorkConstants::EAST);
		else if (input[0] == directions[NorkConstants::WEST]) // West
			PlayerAction::movePlayer(NorkConstants::WEST);
	} else
		return StatusCode::InputStatus::INVALID_PARAM;

	return StatusCode::InputStatus::SUCCESS;
}

StatusCode::Code InputHandler::quit() {
	return StatusCode::InputStatus::SUCCESS_QUIT;
}

StatusCode::Code InputHandler::look() {
	PlayerAction::look();
	return StatusCode::InputStatus::SUCCESS;
}
