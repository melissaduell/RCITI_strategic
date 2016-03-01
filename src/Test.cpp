#include "Test.h"



Test::Test()
{
   networkState1(1);
   //keep track of which networks are 'active'?
}

Test::Test(int networkNum, Network network)
{
   networks_.insert(std::pair<int, Network>(networkNum, network));
}

Test::~Test()
{
}

void Test::addNetwork(int networkNum, Network network)
{
   //need to check that networkNum is not already occupied
   networks_.insert(std::pair<int, Network>(networkNum, network));
}

void Test::networkState1(int network)
{
   Network state1 = Network();
   //setup state1
   networks_[network] = state1;
}

void Test::readRouteTest1(int network)
{
   std::cout << std::endl << std::endl << "Starting readRouteTest1" << std::endl << std::endl;
   std::cout << "   Running readRouteFiles" << std::endl << std::endl;
   networks_[network].readRouteFiles();
   std::cout << "   Running printODTPaths" << std::endl << std::endl;
   networks_[network].printODTPaths();
   std::cout << "Passed readRouteTest1" << std::endl << std::endl;
}

void Test::writeRouteTest1(int network)
{
   //need to rewrite
   std::cout << std::endl << std::endl << "Starting writeRouteTest1" << std::endl << std::endl;
   std::map <std::string, ODT> placeholder = networks_[network].getODTsMap();
   //networks_[network].setODTsMap(networks_[network].getODTsMap());
   networks_[network].writeRouteFiles();
   std::string command1 = "python /var/opt/vtg/lib/vista/vista/test_james_1/base_extract_new.py"
                                                "/var/opt/vtg/lib/vista/vista/test_james_1";
   system(command1.c_str()); // creates/updates 'python_route.txt' with the previous path set (not the one just created above)

   networks_[network].setODTsMap(placeholder);
   std::cout << "Passed writeRouteTest1" << std::endl << std::endl;
}



