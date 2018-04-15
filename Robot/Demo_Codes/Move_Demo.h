#ifndef Move_H
#define Move_H

#include <cmath>

class Move
{
public:
	Move();
	~Move();
	char Turn_LeftorRight(int Target_Bearing, int Current_Bearing);
};

#endif // !Move_H