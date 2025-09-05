#include "DiagnosticDataQuery.h"
#include "DirectionManager.h"

int DirectionManager::Direction()
{

	input = _getch();
	if (input == 224)
	{
		input = _getch();
		switch (input)
		{
		case UP:
			return -1;

		case DOWN:
			return 1;

		case RIGHT:
			return 2;

		case LEFT:
			return 3;

		case ENTER:
			return 4;

		default:
			return 122;
		}
	}
}
