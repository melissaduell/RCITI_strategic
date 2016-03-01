#include <map>
#include "Network.h"

class Test  
{
public:
   Test();
   Test(int networkNum, Network network);
   ~Test();

   //setup
   void addNetwork(int networkNum, Network network); //put in place checks for unique netowrkNum (or have networkNum at all?)
   void networkState1(int network); //placeholder

   //operations
   void readRouteTest1(int network); //visual inspection
   void writeRouteTest1(int network); //visual inspection

private:

   std::map<int, Network> networks_;
};


