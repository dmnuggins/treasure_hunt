#pragma once

class Player {
public:
	Player();
	int GetRow();
	int GetCol();
	char GetID();

	int row, col;
	bool isContained;
	char ID;
};