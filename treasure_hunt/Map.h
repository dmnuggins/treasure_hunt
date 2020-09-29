#pragma once
class Map {
public:
	Map();
	void PrintMap(Player& p1);
	void PopulateMap();
	bool CheckRooms(int row, int col);
	bool WallCheck(Player& p1);

	struct Room {
		int row, col;
		bool hasT;
	};

	Room rooms[9];
private:


};