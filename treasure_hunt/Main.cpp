#include <iostream>
#include <string>

using namespace std;

char map[10][10] = {};
const int mapRows = 10;
const int mapCols = 10;



class Map {
public:
private:

};

class Player {
public:
	Player();
	int GetRowPosition();
	int GetColPosition();
	char GetID();
	void MovePlayer(char direction);

private:
	int row, col;
	char ID;
};



void PrintMap(Player player);

int main() {

	Player player;

	PrintMap(player);

	return 0;
}

void PrintMap(Player player) {
	for (int i = 0; i < mapRows; i++) {
		for (int j = 0; j < mapCols; j++)
		{

			if (i == player.GetRowPosition() && j == player.GetColPosition()) {
				cout << "[" << player.GetID() << "]";
			}
			else {
				cout << "[" << map[i][j] << "]";
			}
		}
		cout << endl;
	}
}

Player::Player() {
	ID = 'P';
	row = 4;
	col = 2;
}

int Player::GetRowPosition() {
	return row;
}

int Player::GetColPosition() {
	return col;
}

char Player::GetID() {
	return ID;

}

MoveDirection Player::MovePlayer(char direction) {
	switch (direction) {
	case 'w':
		break;
	case 'a':
		break;
	case 's':
		break;
	case 'd':
		break;
	default:
		break;
	}
}