#include <cstdio>
using namespace std;

int main(void) {
	
	int n = 0x00111111;
	char* c = (char*)& n;
	if (c[0])
		printf("little endian");
	else
		printf("big endian");
	return 0;
}