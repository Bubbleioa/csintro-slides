#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
int pid, fd;
uint8_t changed = 0xeb;
/*
add $0x1,%ebx -> sub $0x1,%ebx
83 c3 01 -> 83 eb 01
*/

int main(int argc, char *argv[])
{
	char buf[32];
	setbuf(stdout, NULL);
	if (argc != 4)
	{
		printf("Usage: hacker <pid> <start_addr> <length>\n");
		return 0;
	}
	sscanf(argv[1], "%d", &pid) == 1;

	sprintf(buf, "/proc/%d/mem", pid);
	fd = open(buf, O_RDWR);

	// find target
	uintptr_t start, len;
	sscanf(argv[2], "%lx", &start);
	sscanf(argv[3], "%lx", &len);
	uintptr_t size = len * 1024;
	char *mem = malloc(size);
	lseek(fd, start, SEEK_SET);
	read(fd, mem, size);
	for (int i = 1; i < size - 1; i += 1)
	{
		uint8_t v = *(uint8_t *)(&mem[i]);
		if (v == 0xc3 && (*(uint8_t *)(&mem[i - 1]) == 0x83) && (*(uint8_t *)(&mem[i + 1]) == 0x01))
		{
			printf("hack!\n");
			lseek(fd, start + i, SEEK_SET);
			write(fd, &changed, 1);
		}	
	}
	return 0;
}
