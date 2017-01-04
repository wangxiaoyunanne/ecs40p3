// Author: Sean Davis
#ifndef FUNIX_H
  #define FUNIX_H

#include "directory.h"

const int COMMAND_LENGTH = 80;
const int NUM_COMMANDS = 5;
const int MAX_ARGUMENTS = 40;

class Funix
{
public:
  Funix();
  ~Funix();
  Directory *currentDirectory;
  int umask;
  int time;

    void cd(int argCount, const char *arguments[]);
  // calls cd() with currentDirectory as one of its parameters
    int eXit(int argCount, const char *arguments[]);
  // checks "exit" command, returns 0 on proper exit
    void getCommand(char *command);  
  // writes prompt and reads command
    void ls(int argCount, const char *arguments[]);
  // calls ls() with currentDirectory as one of its parameters
    void mkdir(int argCount, const char *arguments[]);
  // calls mkdir() with currentDirectory as one of its parameters
    int processCommand(char *command);
  // returns 0 on proper exit
    void run();  
  // reads and processes commands in a loop until proper exit
    void umas(int argCount, const char *arguments[]);
  // checks "umask" command and executes it if it is proper
    void writePrompt(); 
  // shows path and '#'
};// Funix class
#endif

