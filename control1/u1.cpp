#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;
int main() {

	const char *fifo1="/tmp/mififo";
	mkfifo(fifo1,0666);
	int fd = open(fifo1, O_WRONLY);
	int num=13;
	write(fd, &num, sizeof(num)); 
	close(fd);
	return 0;
	

}

