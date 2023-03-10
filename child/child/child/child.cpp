#include <iostream>
#include <windows.h>


using namespace std;
int main(int argc, char* argv[])
{
	cout << argc << endl;

	int out = 0;
	
	for (int i = 1; i < argc; i++)
	{
		out += atoi(argv[i]);
	}

	cout << out;
}
