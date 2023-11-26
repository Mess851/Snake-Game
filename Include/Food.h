#ifndef FOOD_H_
#define FOOD_H_

#define W 20
#define H 20

#include <windows.h>
#include <stdlib.h>
#include <time.h>

class Food
{
	//Attributes
	private:
		COORD foodPos;

	public:
		//Constructor
		Food();

		//Methods
		void spawnFood();

		//Getters
		COORD getFoodPos();
};

#endif /* FOOD_H_ */
