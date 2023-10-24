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
	int fd = open(fifo1, O_RDONLY);
	int num=13;
	read(fd, &num, sizeof(num)); 
	cout<<num;
	close(fd);
	return 0;
	

}

