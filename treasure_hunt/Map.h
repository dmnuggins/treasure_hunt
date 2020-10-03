#pragma once

class Map {
public:
	Map();
	void PrintMap(Player& p1);
	void MovePlayer(Player& player, char direction);
	void PopulateMap();
	bool CheckRooms(int row, int col);
	bool NotColliding(Player& player, char direction);
	bool IsCollidingWithEdge(Player& player, char direction);
	bool IsCollidingWithRoom(Player& player, char direction);
	struct Room {
		int row, col;
		bool hasT;
	};

	
private:


};