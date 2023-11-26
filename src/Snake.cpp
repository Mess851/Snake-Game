#include "Snake.h"

//Constructor
Snake::Snake(COORD _snakePos, int _snakeVelocity)
{
	snakePos = _snakePos;
	snakeVelocity = _snakeVelocity;
	snakeLenght = 1;
	snakeDirection = 'S';
	body.push_back(snakePos);
}


//Methods
void Snake::changeDirection(char _newDirection)
{
	snakeDirection = _newDirection;
}

void Snake::move()
{
	switch(snakeDirection)
	{
		case 'U':
			snakePos.Y -= snakeVelocity;
			break;

		case 'D':
			snakePos.Y += snakeVelocity;
			break;

		case 'L':
			snakePos.X -= snakeVelocity;
			break;

		case 'R':
			snakePos.X += snakeVelocity;
			break;
	}

	body.push_back(snakePos);

	if(body.size() > snakeLenght)
		body.erase(body.begin());
}

bool Snake::checkEatFood(COORD _foodPos)
{
	bool eaten = false;

	if(snakePos.X == _foodPos.X && snakePos.Y == _foodPos.Y)
	{
		eaten = true;
	}

	return eaten;
}

bool Snake::checkCollisions()
{
	bool collision = false;

	if(snakePos.X >= W || snakePos.X < 0 || snakePos.Y >= H || snakePos.Y < 0)
	{
		collision = true;
	}

	for(int i = 0; i < snakeLenght - 1; i++)
	{
		if(snakePos.X == body[i].X && snakePos.Y == body[i].Y)
		{
			collision = true;
		}
	}

	return collision;
}

void Snake::increaseSnakeLenght()
{
	snakeLenght++;
}

//Getters
COORD Snake::getSnakePos()
{
	return snakePos;
}

vector<COORD> Snake::getBody()
{
	return body;
}
