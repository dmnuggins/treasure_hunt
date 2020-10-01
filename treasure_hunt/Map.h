#pragma once

class Map {
public:
	Map();
	void PrintMap(Player& p1);
	void MovePlayer(Player& player, char direction);
	void PopulateMap();
	bool CheckRooms(int row, int col);
	bool BoundsCheck(Player& player, char direction);
	bool IsCollidingWithRoom(Player& player, char direction);
	bool IsContained(Player& player);
	struct Room {
		int row, col;
		bool hasT;
	};

	
private:


};