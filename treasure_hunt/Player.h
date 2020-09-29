#pragma once

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