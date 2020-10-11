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

int Player::GetRow() {
	return row;
}

int Player::GetCol() {
	return col;
}

char Player::GetID() {
	return ID;
}