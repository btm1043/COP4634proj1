
#include "parse.hpp"

int main(int argc, const char* argv[])
{	
	char debug[] = "-Debug";


	//execl("/bin/ls", "ls", "-l", (char*)NULL);

	Parse p = Parse();
	while (p.getFirstArg()!=1)
	{
		char buf[256];
		std::cout << "$$$ ";
		fgets(buf, 256, stdin);

		p.parseInput(buf);
		if (argc > 1)
		{
			if (strcmp(debug, argv[1]) == 0)
			{
				p.printParams();
			}
		}
		//reassign the input and output back to NULL
		p.refresh();		
	}
}

