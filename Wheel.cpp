#include <ctime>
#include <stdlib.h>
#include "Wheel.h"

int Wheel::Spin()
{
	int ret_val = 0;

	srand((unsigned int)time(0));
	ret_val = rand() % 36 + 1;

	return ret_val;
}
