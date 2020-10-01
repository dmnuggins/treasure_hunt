#include <iostream>
#include <conio.h>
#include <string>
#include "Player.h"
#include "Map.h"

using namespace std;

const int mapRows = 9;
const int mapCols = 9;

int main() {

	Player player;
	Map map;

	char toggle = '0';

	map.PrintMap(player);


	while (toggle != 'p') {
		cin >> toggle;
		map.MovePlayer(player, toggle);
		map.PrintMap(player);
		cout << "toggle: " << toggle << endl;
	}

	return 0;
}



