#include "Level.h"

// Initialize globalIndex as 0.
unsigned int Level::globalIndex = 0;

Level::Level(std::string name) {
	// There will always be one room at 0, 0 when a level is created.
	grid.push_back(Room(0, 0));
	localIndex = globalIndex++;

	this->name = name;
}

std::string Level::getName() {
	return name;
}

bool Level::roomExists(int pos_x, int pos_y) {
	return roomExists(Point(pos_x, pos_y));
}

bool Level::roomExists(Point pos) {
	return std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.pos == pos; }) != grid.end();
}

void Level::prepareRoomRelative(int relativePos_x, int relativePos_y) {
	prepareRoom(Point(relativePos_x, relativePos_y) + PlayerState().pos);
}

void Level::prepareRoomRelative(Point relativePos) {
	prepareRoom(Point(PlayerState().pos + relativePos));
}

void Level::prepareRoom(int absolutePos_x, int absolutePos_y) {
	prepareRoom(Point(absolutePos_x, absolutePos_y));
}

// Should be called before attempting to move to any point.
void Level::prepareRoom(Point absolutePos) {
	bool exists = roomExists(absolutePos);
	
	// Do nothing if room already exists
	if (exists)
		return;
	
	// Generate new chunk if room doesn't exist
	Point delta = absolutePos - PlayerState().pos;
	
	if (delta.x == 0) { // Player moved up/down on grid
		
	} else if (delta.y == 0) { // Player moved left/right on grid
		
	}
}

void Level::addRoomRelative(int relativePos_x, int relativePos_y) {
	addRoom(Point(relativePos_x, relativePos_y) + PlayerState().pos);
}

void Level::addRoomRelative(Point relativePos) {
	addRoom(Point(PlayerState().pos + relativePos));
}

void Level::addRoom(int absolutePos_x, int absolutePos_y) {
	addRoom(Point(absolutePos_x, absolutePos_y));
}

void Level::addRoom(Point absolutePos) {
	if (!roomExists(absolutePos))
		grid.push_back(Room(absolutePos));
}

void Level::removeRoom(int pos_x, int pos_y) {
	removeRoom(Point(pos_x, pos_y));
}

void Level::removeRoom(Point pos) {
	if (roomExists(pos))
		grid.erase(std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.pos == pos; }));
}

Room Level::getRoom(int pos_x, int pos_y) {
	return getRoom(Point(pos_x, pos_y));
}

Room Level::getRoom(Point pos) {
	return *std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.pos == pos; });
}

std::vector<Room> Level::getRooms() {
	return grid;
}
