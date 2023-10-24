#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	const char *fifo1="/tmp/mififo";
	mkfifo(fifo1,666);
	ifstream lifoLectura(fifo1,ios::binay)
	int numero=0;
	fifoLectura.read(reinterpret_cast<char*>(num),size(numero));
	cout<<numero;
	fifoLectura.close();
	
}

