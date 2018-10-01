#include "Level.h"

// Initialize globalIndex as 0.
unsigned int Level::globalIndex = 0;

Level::Level() {
	// There will always be one room at 0, 0 when a level is created.
	grid.push_back(Room(0, 0));
	localIndex = globalIndex++;
}

bool Level::roomExists(int pos_x, int pos_y) {
	return roomExists(Point(pos_x, pos_y));
}

bool Level::roomExists(Point pos) {
	return std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.p == pos; }) != grid.end();
}

void Level::addRoomRelative(int relativePos_x, int relativePos_y) {
	addRoom(Point(relativePos_x, relativePos_y) + PlayerState().p);
}

void Level::addRoomRelative(Point relativePos) {
	addRoom(Point(PlayerState().p + relativePos));
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
		grid.erase(std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.p == pos; }));
}

Room Level::getRoom(int pos_x, int pos_y) {
	return getRoom(Point(pos_x, pos_y));
}

Room Level::getRoom(Point pos) {
	return *std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.p == pos; });
}

std::vector<Room> Level::getRooms() {
	return grid;
}