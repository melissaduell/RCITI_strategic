//General overview framework for Strategic DTA code
//James Sloan 17/11/15

#include "Main.h"
//need to add 'vista' folder to directory 

int main(int argc, char* argv[]) 
{			
   Network network = Network();

   Test test = Test(1, network);
   
   test.readRouteTest1(1);  //should populate ODTsMap_and output the paths in it

   //test.writeRouteTest1(1); //should write from ODTsMap_

   return 0;
}
 

