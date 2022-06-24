#include <ctime>
#include <stdlib.h>
#include "Wheel.h"

int Wheel::Spin()
{
	int result = 0;

	srand((unsigned int)time(0));
	result = rand() % 36 + 1;

	return result;
}
