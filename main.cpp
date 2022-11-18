#include"head.h"
int main()
{
	initgraph(1536, 864, INIT_NOBORDER | INIT_RENDERMANUAL);
	PIMAGE neww = newimage();
	while (!opens());
	options();
	getch();
	return 0;
}