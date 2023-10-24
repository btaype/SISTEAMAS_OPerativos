#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {

	const char *fifo1="/tmp/mififo	";
	mkfifo(fifo1,666);
	ofstream fifoEscritura(fifo1,ios::binary);
	int num=13;
	fifoEscritura.write(reinterpret_cast<const char*>(&num),sizeof(num));
	fifoEscritura.close();
	return 0;
	

}

