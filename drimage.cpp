#include"head.h"
drimage nowimage[20];
void revoke()
{

}

drimage moutodri(mouse_msg msg, int mo)
{
	drimage dr;
	dr.mode = ways;
	switch (mo)
	{
	case 1:
		dr.x1 = msg.x;
		dr.y1 = msg.y;
		break;
	case 2:
		dr.x2 = msg.x;
		dr.y2 = msg.x;
		break;
	case 3:
		dr.x3 = msg.x;
		dr.y3 = msg.y;
	}
	return dr;
}