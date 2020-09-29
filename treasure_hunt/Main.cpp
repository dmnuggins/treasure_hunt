#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

char map[10][10] = {};
const int mapRows = 10;
const int mapCols = 10;

class Player {
public:
	Player();
	void MovePlayer(char direction);
	bool CheckBounds(int coordinate);
	int GetRow();
	int GetCol();
	char GetID();

private:
	int row, col;
	char ID;
};

class Map {
public:
	void PrintMap(Player &p1);
private:

};



int main() {

	Player player;
	Map map;

	char toggle = '0';

	map.PrintMap(player);


	while (toggle != 'p') {
		cin >> toggle;
		player.MovePlayer(toggle);
		map.PrintMap(player);
		cout << "toggle: " << toggle << endl;
	}

	return 0;
}

Player::Player() {
	ID = 'P';
	row = 0;
	col = 0;
}

void Player::MovePlayer(char direction) {

	switch (direction) {
	case 'w':
		if (CheckBounds(row - 1)) {
			row -= 1;
		}
		else {
			cout << "[WARNING] Out of Bounds" << endl;
		}
		break;
	case 'a':
		if (CheckBounds(col - 1)) {
			col -= 1;
		}
		else {
			cout << "[WARNING] Out of Bounds" << endl;
		}
		break;
	case 's':
		if (CheckBounds(row + 1)) {
			row += 1;
		}
		else {
			cout << "[WARNING] Out of Bounds" << endl;
		}
		break;
	case 'd':
		if (CheckBounds(col + 1)) {
			col += 1;
		}
		else {
			cout << "[WARNING] Out of Bounds" << endl;
		}
		break;
	default:
		break;
	}
}

bool Player::CheckBounds(int coordinate) {
	if (coordinate > 9 || coordinate < 0) {
		return false;
	}
	else {
		return true;
	}
}
int Player::GetRow() {
	return row;
}

int Player::GetCol() {
	return col;
}

char Player::GetID() {
	return ID;
}

void Map::PrintMap(Player &player) {
	for (int i = 0; i < mapRows; i++) {
		for (int j = 0; j < mapCols; j++)
		{

			if (i == player.GetRow() && j == player.GetCol()) {
				cout << "[" << player.GetID() << "]";
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
