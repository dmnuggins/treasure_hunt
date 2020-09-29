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
	void Up();
	void Down();
	void Left();
	void Right();
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
	void MovePlayer(Player &p1, char direction);
private:

};



int main() {

	Player player;
	Map map;

	char toggle = '0';

	map.PrintMap(player);


	while (toggle != 'p') {
		cin >> toggle;
		map.MovePlayer(player, toggle);
		map.PrintMap(player);
		cout << "toggle: " << toggle << endl;
	}
	

	//PrintMap(player);

	return 0;
}

Player::Player() {
	ID = 'P';
	row = 4;
	col = 2;
}

void Player::Up() {
	row -= 1;
}

void Player::Down() {
	row += 1;
}

void Player::Left() {
	col -= 1;
}

void Player::Right() {
	col += 1;
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

void Map::MovePlayer(Player &player, char direction) {
	switch (direction) {
	case 'w':
		player.Up();
		break;
	case 'a':
		player.Left();
		break;
	case 's':
		player.Down();
		break;
	case 'd':
		player.Right();
		break;
	default:
		break;
	}
	cout << "new_row: " << player.GetRow() << endl;
	cout << "new_col: " << player.GetCol() << endl;
}