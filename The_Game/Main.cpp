#include "GameController.h"
#include<iostream>

using namespace std;

int main(){
	//set up game controller
	GameController *controller = new GameController();

	controller->gameLoop();
	//start the game loop here until game ends.

	system("pause");
	return 0;
}
