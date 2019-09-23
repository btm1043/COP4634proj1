#  Makefile for project 1. it will make use of make(make all), make run, make debug, and make clean. 
CXX=g++
OBJECTS= myshell.o parse.o
CXXFLAGS= -std=c++11 -c -g -Wall

# all compiles both files and then links the object files to build the myshell exe
all: $(OBJECTS)
	$(CXX) $(OBJECTS) -o myshell
	
# creates the myshell object file
myshell.o: myshell.cpp
	$(CXX) $(CXXFLAGS) myshell.cpp
	
#creates the parse object file		
parse.o: parse.cpp
	$(CXX) $(CXXFLAGS) parse.cpp
	
# function to compile build and run the program to save time testing	
run: all
	./myshell
	
# function to compile build and run the program with the -Debug param needed to run in debug mode	
debug: all
	./myshell -Debug
	
# basic remove to clean the folder
clean:
	$(RM) *o myshell
