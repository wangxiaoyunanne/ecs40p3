// Author: Sean Davis

#include <stdlib.h>
#include "funix.h"

int main()
{
  Funix *funix =  new Funix[1];
  funix[0].run();
  delete[] funix; 
}  // main()

