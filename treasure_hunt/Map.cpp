#include <iostream>
#include <string>

#include "Player.h"
#include "Map.h"

using namespace std;

const int ROOM_COORDINATES[9][2] = {
	{1,1} , {1,4} , {1,7} ,
	{4,1} , {4,4} , {4,7} ,
	{7,1} , {7,4} , {7,7}
};

Map::Map() {
	
}

void Map::MovePlayer(Player& player, char direction) {
	switch (direction)
	{
	case 'w':
		if (BoundsCheck(player, direction)) {
			player.row -= 1;
		}
		break;
	case 'a':
		if (BoundsCheck(player, direction)) {
			player.col -= 1;
		}
		break;
	case 's':
		if (BoundsCheck(player, direction)) {
			player.row += 1;
		}
		break;
	case 'd':
		if (BoundsCheck(player, direction)) {
			player.col += 1;
		}
		break;
	default:
		break;
	}
	
}

void Map::PrintMap(Player& player) {
	char map[9][9] = {};

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			// -- change condition to check when player coord == room coord --
			if (i == player.GetRow() && j == player.GetCol()) {
				cout << "[" << player.GetID() << "]";
			}
			else if (CheckRooms(i, j)) {
				cout << "[R]";
			}
			else {
				cout << "[" << map[i][j] << "]";
			}
			// -- change condition to check when player coord == room coord --

		}
		cout << endl;
	}
	cout << "row: " << player.GetRow() << endl;
	cout << "row: " << player.GetCol() << endl;
	cout << "isContained: " << player.isContained << endl;


}

void Map::PopulateMap() {
	for (int i = 0; i < 9; i++) {

	}
}

bool Map::CheckRooms(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (ROOM_COORDINATES[i][0] == row && ROOM_COORDINATES[i][1] == col) {
			return true;
		}
	}
	return false;
}

bool Map::BoundsCheck(Player& player, char direction){
	bool edgeCollide, roomCollide;
	// outer map check

	// room collision check
	roomCollide = IsCollidingWithRoom(player, direction);

	if (!roomCollide) {
		return true;
	}

	return false;
}

bool Map::IsCollidingWithRoom(Player& player, char direction) {
	for (int i = 0; i < 9; i++) {
		if (!player.isContained) {
			switch (direction)
			{
			case 'w':
				if (ROOM_COORDINATES[i][0] == player.row - 1 && ROOM_COORDINATES[i][1] == player.col) {
					return true;
				}
				break;
			case 'a':
				if (ROOM_COORDINATES[i][0] == player.row && ROOM_COORDINATES[i][1] == player.col - 1) {
					return true;
				}
				break;
			case 'd':
				if (ROOM_COORDINATES[i][0] == player.row && ROOM_COORDINATES[i][1] == player.col + 1) {
					return true;
				}
				break;
			case 's' :
				if (ROOM_COORDINATES[i][0] == player.row + 1 && ROOM_COORDINATES[i][1] == player.col) {
					player.isContained = true;
					return false;
				}
				break;
			default:
				return false;
				break;
			}
		}
		else if (player.isContained) {
			switch (direction)
			{
			case 's':
				return true;
				break;
			case 'a':
				return true;
				break;
			case 'd':
				return true;
				break;
			case 'w':
				player.isContained = false;
				return false;
				break;
			default:
				return false;
				break;
			}
		}
	}
	return false;
}