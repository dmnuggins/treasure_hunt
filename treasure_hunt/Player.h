#pragma once

class Player {
public:
	Player();
	bool CheckBounds(int coordinate);
	int GetRow();
	int GetCol();
	char GetID();

	int row, col;
	bool isContained;
	char ID;

private:

};