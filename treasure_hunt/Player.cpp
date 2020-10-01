#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"

using namespace std;

Player::Player() {
	ID = 'P';
	row = 0;
	col = 0;
	isContained = false;
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

//Player::Position* Player::getPosition() {
//	return pos;
//}