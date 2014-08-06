#include "ConsoleDisplay.h"

#include <string>

using namespace std;

static const int width = 10;
static const int height = 10;
static const int count = 3;
static const int over = 100;

int main()
{

	ConsoleDisplay display(count, width, height);

	for (int i = 0; i < count + over; ++i)
		for (int j = 0; j < height + over; ++j)
			for (int k = 0; k < height + over; ++k)
				display.write(i, j, "X");
			

	display.refresh();

	while(1);

	return 0;
}
