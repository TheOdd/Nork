#include "World.h"

std::vector <Room> World::grid;

World::World() {
	grid.push_back(Room(0, 0));
}

bool World::roomExists(int pos_x, int pos_y) {
	return roomExists(Point(pos_x, pos_y));
}

bool World::roomExists(Point pos) {
	return std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.p == pos; }) != grid.end();
}

void World::addRoom(int relativePos_x, int relativePos_y, int playerPos_x, int playerPos_y) {
	addRoom(Point(relativePos_x, relativePos_y) + Point(playerPos_x, playerPos_y));
}

void World::addRoom(Point relativePos, Point playerPos) {
	addRoom(Point(playerPos + relativePos));
}

void World::addRoom(int absolutePos_x, int absolutePos_y) {
	addRoom(Point(absolutePos_x, absolutePos_y));
}

void World::addRoom(Point absolutePos) {
	if(!roomExists(absolutePos))
		grid.push_back(Room(absolutePos));
}

void World::removeRoom(int pos_x, int pos_y) {
	removeRoom(Point(pos_x, pos_y));
}

void World::removeRoom(Point pos) {
	if (roomExists(pos))
		grid.erase(std::find_if(grid.begin(), grid.end(), [&pos](Room room) {return room.p == pos; }));
}

std::vector<Room> World::getRooms() {
	return grid;
}