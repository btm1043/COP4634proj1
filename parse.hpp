/* FILE: parse.hpp
 * AUTHOR: Bryant Matt && STEPHEN LAMALIE
 * COURSE: COP4634
 * ASSIGNMENT: PROJECT 1 / myShell
 */
#ifndef PARSE_HPP
#define PARSE_HPP

#include <cstring>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

#define MAXARGS 32

class Parse
{
	public:
		Parse();
		int getFirstArg();
		void parseInput(char *buf);
		void printParams();
		void refresh();
		
	private:
		char* inputRedirect;           /* file name or NULL */
		char* outputRedirect;          /* file name or NULL */
		int  background;               /* either 0 (false) or 1 (true) */
		int  argumentCount;            /* number of tokens in argument vector */
		char* argumentVector[MAXARGS]; /* array of strings */
		
};

#endif
