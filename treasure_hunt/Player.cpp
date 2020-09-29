#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

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
	if (coordinate > 8 || coordinate < 0) {
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