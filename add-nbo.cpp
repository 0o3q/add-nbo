#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int arg, char** argv){
	uint32_t v1, v2;

	FILE* p1 = fopen(argv[1], "rb");
	FILE* p2 = fopen(argv[2], "rb");

	fread(&v1, 4, 1, p1);
	fread(&v2, 4, 1, p2);

	v1 = ntohl(v1);
	v2 = ntohl(v2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", v1, v1, v2, v2, v1+v2, v1+v2);

	fclose(p1);
	fclose(p2);

	return 0;
}
