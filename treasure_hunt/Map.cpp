#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Map.h"

using namespace std;

const int ROOM_COORDINATES[9][2] = {
	{1,1} , {1,4} , {1,7} ,
	{4,1} , {4,4} , {4,7} ,
	{7,1} , {7,4} , {7,7}
};



Map::Map() {
	SetTreasureRoom();
}

void Map::SetTreasureRoom() {
	srand(time(0));
	int random = rand() % 9;
	cout << "Random Num: " << random << endl;
	treasure.row = ROOM_COORDINATES[random][0];
	treasure.col = ROOM_COORDINATES[random][1];
}

void Map::PrintMap(Player& player) {
	char map[9][9] = {};

	
	cout << "Treasure.row: " << treasure.row << endl;
	cout << "Treasure.col: " << treasure.col << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			// -- change condition to check when player coord == room coord --
			if (i == player.GetRow() && j == player.GetCol()) {
				cout << "[" << player.GetID() << "]";
			}
			else if (CheckRooms(i, j)) {
				if (CheckTreasure(i, j)) {
					cout << "[T]";
				}
				else {
					cout << "[R]";
				}
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

void Map::MovePlayer(Player& player, char direction) {
	switch (direction)
	{
	case 'w':
		if (NotColliding(player, direction)) {
			player.row -= 1;
		}
		break;
	case 'a':
		if (NotColliding(player, direction)) {
			player.col -= 1;
		}
		break;
	case 's':
		if (NotColliding(player, direction)) {
			player.row += 1;
		}
		break;
	case 'd':
		if (NotColliding(player, direction)) {
			player.col += 1;
		}
		break;
	default:
		break;
	}

}

void Map::PopulateMap() {
	for (int i = 0; i < 9; i++) {

	}
}

//checks if the passed in coordinate matches the designated room coordinates
bool Map::CheckRooms(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (ROOM_COORDINATES[i][0] == row && ROOM_COORDINATES[i][1] == col) {
			return true;
		}
	}
	return false;
}

//checks if the passed in coordinate matches the designated treasure coordinates
bool Map::CheckTreasure(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (treasure.row == row && treasure.col == col) {
			return true;
		}
	}
	return false;
}


// checks if the player is breaking any boundaries (room/edge of map)
bool Map::NotColliding(Player& player, char direction){
	bool edgeCollide, roomCollide, notColliding = true;
	// outer map check
	edgeCollide = IsCollidingWithEdge(player, direction);
	cout << "edgeCollide: " << edgeCollide << endl;
	// room collision check
	roomCollide = IsCollidingWithRoom(player, direction);
	cout << "roomCollide: " << roomCollide << endl;

	if (edgeCollide) {
		notColliding = false;
	}
	if (roomCollide) {
		notColliding = false;
	}
	return notColliding;
}

bool Map::IsCollidingWithEdge(Player& player, char direction) {
	switch (direction)
	{
	case 'w':
		if (player.row - 1 < 0) {
			cout << "Player r: " << player.row - 1 << endl;
			cout << "Player c: " << player.col << endl;

			return true;
		}
		break;
	case 'a':
		if (player.col - 1 < 0) {
			cout << "Player r: " << player.row << endl;
			cout << "Player c: " << player.col - 1 << endl;

			return true;
		}
		break;
	case 'd':
		if (player.col + 1 > 8) {
			cout << "Player r: " << player.row << endl;
			cout << "Player c: " << player.col + 1 << endl;
			return true;
		}
		break;
	case 's':
		if (player.row + 1 > 8) {
			cout << "Player r: " << player.row + 1 << endl;
			cout << "Player c: " << player.col << endl;
			return true;
		}
		break;
	default:
		return false;
		break;
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