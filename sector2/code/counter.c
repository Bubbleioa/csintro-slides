#include <stdio.h>
#include <unistd.h>
int main()
{
	int count = 0;
	while (1)
	{
		sleep(1);
		count++;
		printf("\rcount: %d", count);
		fflush(stdout);
	}
	return 0;
}
