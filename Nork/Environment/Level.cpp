#include "Level.h"
#include "../Player/PlayerState.h"

// Initialize globalIndex as 0.
unsigned int Level::globalIndex = 0;

Level::Level(std::string name) {
	// There will always be one room at 0, 0 when a level is created.
	//grid.push_back(Room(0, 0));

	// There will always be one chunk at 0, 0 when a level is created.
	prepareRoom(0, 0);

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
	prepareRoom(Point(relativePos_x, relativePos_y) + PlayerState::pos);
}

void Level::prepareRoomRelative(Point relativePos) {
	prepareRoom(Point(PlayerState::pos + relativePos));
}

void Level::prepareRoom(int absolutePos_x, int absolutePos_y) {
	prepareRoom(Point(absolutePos_x, absolutePos_y));
}

// Should be called before attempting to move to any point.
void Level::prepareRoom(Point absolutePos) {
	// Do nothing if room already exists
	if (roomExists(absolutePos))
		return;

	generateChunk(absolutePos);
}

void Level::generateChunk(Point absolutePos) {
	// Create chunk of rooms with size of CHUNK_SIZE
	Point chunkCorner = absolutePos;

	if (chunkCorner.x < 0)
		chunkCorner.x -= NorkConstants::CHUNK_SIZE - 1;
	if (chunkCorner.y < 0)
		chunkCorner.y -= NorkConstants::CHUNK_SIZE - 1;

	Point chunkLocation = Point(chunkCorner.x / NorkConstants::CHUNK_SIZE * NorkConstants::CHUNK_SIZE,
								chunkCorner.y / NorkConstants::CHUNK_SIZE * NorkConstants::CHUNK_SIZE);

	for (unsigned int i = 0; i < NorkConstants::CHUNK_SIZE * NorkConstants::CHUNK_SIZE; i++)
		addRoom(chunkLocation + Point(i % NorkConstants::CHUNK_SIZE, i / NorkConstants::CHUNK_SIZE));

	std::vector<Point> stack;

	stack.push_back(absolutePos);

	while (stack.size() > 0) {
		if (stack.back().x + 1 < chunkLocation.x + NorkConstants::CHUNK_SIZE
				&& !getRoom(stack.back() + Point(NorkConstants::WEST)).generated) { // WEST
			getRoom(stack.back()).generated = true;
			getRoom(stack.back()).doors[NorkConstants::WEST] = true;
			stack.push_back(stack.back() + Point(NorkConstants::WEST));
			getRoom(stack.back()).doors[NorkConstants::EAST] = true;
		} else if (stack.back().x - 1 > chunkLocation.x
				   && !getRoom(stack.back() + Point(NorkConstants::EAST)).generated) { // EAST
			getRoom(stack.back()).generated = true;
			getRoom(stack.back()).doors[NorkConstants::EAST] = true;
			stack.push_back(stack.back() + Point(NorkConstants::EAST));
			getRoom(stack.back()).doors[NorkConstants::WEST] = true;
		} else if (stack.back().y + 1 < chunkLocation.y
				   && !getRoom(stack.back() + Point(NorkConstants::NORTH)).generated) { // NORTH
			getRoom(stack.back()).generated = true;
			getRoom(stack.back()).doors[NorkConstants::NORTH] = true;
			stack.push_back(stack.back() + Point(NorkConstants::NORTH));
			getRoom(stack.back()).doors[NorkConstants::SOUTH] = true;
		} else if (stack.back().y - 1 > chunkLocation.y
				   && !getRoom(stack.back() + Point(NorkConstants::SOUTH)).generated) { // SOUTH
			getRoom(stack.back()).generated = true;
			getRoom(stack.back()).doors[NorkConstants::SOUTH] = true;
			stack.push_back(stack.back() + Point(NorkConstants::SOUTH));
			getRoom(stack.back()).doors[NorkConstants::NORTH] = true;
		} else {
			if (!getRoom(stack.back()).generated)
				getRoom(stack.back()).generated = true;
			stack.pop_back();
		}
	} // End map generation loop
}

void Level::addRoomRelative(int relativePos_x, int relativePos_y) {
	addRoom(Point(relativePos_x, relativePos_y) + PlayerState::pos);
}

void Level::addRoomRelative(Point relativePos) {
	addRoom(Point(PlayerState::pos + relativePos));
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
		grid.erase(std::find_if(grid.begin(), grid.end(), [&pos](Room room) { return room.pos == pos; }));
}

Room& Level::getRoom(int pos_x, int pos_y) {
	return getRoom(Point(pos_x, pos_y));
}

Room& Level::getRoom(Point pos) {
	return *std::find_if(grid.begin(), grid.end(), [&pos](Room& room) { return room.pos == pos; });
}

std::vector<Room> Level::getRooms() {
	return grid;
}
