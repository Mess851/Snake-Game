#include "Food.h"

//Constructor
Food::Food()
{
	spawnFood();
}

//Methods
void Food::spawnFood()
{
	srand(time(0));

	foodPos.X = rand() % W;
	foodPos.Y = rand() % H;
}

//Getters
COORD Food::getFoodPos()
{
	return foodPos;
}
