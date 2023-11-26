#include <iostream>
#include <conio.h>
#include <time.h>

#include "Snake.h"
#include "Food.h"

#define W 20
#define H 20

using namespace std;

//Variables
int score;
bool finished;

Snake snake({W/2, H/2}, 1);
Food food;

//Methods
void init()
{
	system("cls"); //Linux -> system ("clear")

	finished = false;
	score = 0;
}


void render()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

	//Render top
	for(int i = 0; i < W + 2; i++)
	{
		cout<<"#";
	}
	cout<<endl;

	//Render intermediate parts
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			if(j == 0)
				cout<<"#";

			if(j == snake.getSnakePos().X && i == snake.getSnakePos().Y)
				cout<<"O";

			else if(j == food.getFoodPos().X && i == food.getFoodPos().Y)
				cout<<"*";

			else
			{
				bool printTail = false;

				for(int k = 0; k < snake.getBody().size(); k++)
				{

					if(j == snake.getBody()[k].X && i == snake.getBody()[k].Y)
					{
						cout<<"o";
						printTail = true;
					}
				}

				if(!printTail)
					cout<<" ";
			}

			if(j == W - 1)
				cout<<"#";
		}

		cout<<endl;
	}

	//Render bottom
	for(int i = 0; i < W + 2; i++)
	{
		cout<<"#";
	}

	cout<<endl<<endl;

	cout<<"Score: "<<score<<endl;
}


void input()
{
	if(_kbhit()) //True if the user pressed a key
	{
		switch(_getch()) //Get the key pressed in keyboard
		{
			case 'w':
				snake.changeDirection('U');
				break;
			case 's':
				snake.changeDirection('D');
				break;
			case 'a':
				snake.changeDirection('L');
				break;
			case 'd':
				snake.changeDirection('R');
				break;
			case 'q':
				finished = true;
				break;
		}
	}

	snake.move();
}

void gameLogic()
{
	//Check collisions
	if(snake.checkCollisions())
		finished = true;

	//Check eating
	if(snake.checkEatFood(food.getFoodPos()))
	{
		score += 10;
		food.spawnFood();
		snake.increaseSnakeLenght();
	}
}

//Main
int main()
{
	init();

	while(!finished)
	{
		render();
		Sleep(65); //Make the game slower

		input();
		gameLogic();
	}

	cout<<"END OF THE GAME"<<endl;

	return 0;
}
