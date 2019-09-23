
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
		
		if (p.getFirstArg() != 1) {
			pid = fork();
			if (pid == 0) {
				p.execute();
				exit(1);
			}
			else {
				if (p.getBackground() != 1)
				{
					result = waitpid(pid, &status, 0);
				}
			}
			if (argc > 1)
			{
				if (strcmp(debug, argv[1]) == 0)
				{
					p.printParams();
				}
			}
			//reassign the input and output back to NULL
			p.refresh();
		}else{
			while ((pid = wait(&status)) > 0);
		}
	}
}

