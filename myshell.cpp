
#include "parse.hpp"

int main(int argc, const char* argv[])
{	
	//Char array to compare user input to for Debug mode
	char debug[] = "-Debug";
	
	//Char array to house user input
	char buf[256];
	
	//Creates Parse object to house parameters
	Parse p = Parse();
	while (p.getFirstArg()!=1)
	{
		//Gets user input
		std::cout << "$$$ ";
		fgets(buf, 256, stdin);
		
		p.parseInput(buf);
		
		//Check if command line argument includes -Debug
		if (argc > 1)
		{
			//If so print paramaters
			if (strcmp(debug, argv[1]) == 0)
			{
				p.printParams();
			}
		}
		//reassign the input and output back to NULL
		p.refresh();		
	}
}

