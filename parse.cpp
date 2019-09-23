/* FILE: parse.hpp
 * AUTHOR: Bryant Matt && STEPHEN LAMALIE
 * COURSE: COP4634
 * ASSIGNMENT: PROJECT 1 / myShell
 */
 
 #include "parse.hpp"
 
Parse::Parse()
{
	inputRedirect = NULL;
	outputRedirect = NULL;
}

int Parse::getFirstArg()
{
	char quit[] = "quit";
	if (argumentVector[0] != NULL)
	{
		if (strcmp(quit, argumentVector[0])==0)
		{
			return 1;
		}
		
		return 0;
	}
	else 
	{
		return 2;
	}
}
void Parse::parseInput(char *buf)
{
	char* pChar;
	argumentCount = 0;
	background = 0;
	pChar = strtok(buf, " \t\n");  //pChar is the first token to be parsed, it will tell us if it will be a special token.

	while (pChar != NULL)
	{
		if (pChar[0] == '<') 
		{
			inputRedirect = (pChar + 1);
		}
		else if (pChar[0] == '>') 
		{
			outputRedirect = (pChar + 1);
		}
		else if (pChar[0] == '&')
		{
			background = 1;
		}
		else 
		{
			argumentVector[argumentCount] = pChar;
			argumentCount++;
		}
		
		pChar = strtok(NULL, " \n");
	}
}
void Parse::printParams()
{ 
	std::cout << "InputRedirect: [" <<
		((inputRedirect!=NULL) ? inputRedirect : "NULL") << "]" <<std::endl<<
		"OutputRedirect:[" <<
		((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << std::endl <<
		"Background: [" << background << "]" << std::endl <<
		"ArgumentCount: [" << argumentCount << "]" << std::endl;
	 
	for (int i = 0; i < argumentCount; i++)
	{
		std::cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << std::endl; 
	}
}
void Parse::refresh()
{
	inputRedirect = NULL;
	outputRedirect = NULL;
}
