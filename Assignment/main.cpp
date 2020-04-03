#include <iostream>
#include <time.h>


int main(int argc, char* argv[])
{
	clock_t start, end;
	int sum = 0;
	start = clock();
	for (int i = 0; i < 100000; i++)
		for (int j = 0; j < 100000; j++)
			sum += i + j;
	end = clock();
	std::cout << end - start << std::endl;
	return 0;
}