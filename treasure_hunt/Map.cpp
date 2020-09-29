#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"

using namespace std;

Map::Map() {
	int roomCoordinates[9][2] = {
	{1,1} , {1,4} , {1,7} ,
	{4,1} , {4,4} , {4,7} ,
	{7,1} , {7,4} , {7,7}
	};

	// initialize rooms
	for (int i = 0; i < 9; i++) {
		rooms[i].row = roomCoordinates[i][0];
		rooms[i].col = roomCoordinates[i][1];
	}
}

void Map::PrintMap(Player& player) {
	char map[9][9] = {};

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{

			if (i == player.GetRow() && j == player.GetCol()) {
				cout << "[" << player.GetID() << "]";
			}
			else if (CheckRooms(i, j)) {
				cout << "[R]";
			}
			else {
				cout << "[" << map[i][j] << "]";
			}
		}
		cout << endl;
	}
	cout << "row: " << player.GetRow() << endl;
	cout << "row: " << player.GetCol() << endl;

}

void Map::PopulateMap() {
	for (int i = 0; i < 9; i++) {

	}
}

bool Map::CheckRooms(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (rooms[i].row == row && rooms[i].col == col) {
			return true;
		}
	}
	return false;
}

bool Map::WallCheck(Player& p1) {
	return false;
}