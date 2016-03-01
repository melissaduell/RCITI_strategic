/*
 * Network.cpp
 *
 *  Created on: Jul 10, 2013
 *      Author: gwdu818
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Network.h"


Network::Network()
{
	numTimeSteps_ = 0;
   numScenarios_ = 0;
   ODTsMap_.clear();
}

Network::Network(int numNodes,int totalTimeSteps, int numScenarios) 
{
	numTimeSteps_ = totalTimeSteps;
	numScenarios_ = numScenarios;
}

Network::~Network() 
{

}


//Operations:


void Network::importData() 
{

}

void Network::readOptions() 
{

}

void Network::importScenarios()
{

}

void Network::importDemandData()
{

}

void Network::importNetworkData()
{

}


void Network::StrUEDTA()
//most base types are placeholders
//base.RouteIndex and base.RouteData are always mentioned together
//name == id
{
   /*int main(int argc, char* argv[]) //Sections based on 'Coding framework for StrUEDTA' in 'tasks' in 'app4' dropbox
   {			//tell program how many scenarios there are and what iteration
   int iteration; // set to what was passed in.
   int numIterations; //set to what was passed in.
   int numScenarios;

   //Section 1
   Network network;  //change name
   network.readInData("GIVE ME MY DATA"); // what is the SQL code?
   ScenarioList scenarios;
   scenarios.readInData("DATA PLEASE"); //network + demandForEachScenario(?)   //from PSQL //assume already in PSQL
   //also need freeflow cost matrix

   //Section 2.0
   std::map <std::string, ODT> shortestPaths;
   //make sure vista files are organised as we want it
   network.freeFlowShortestPath();
   //creates route files. does not populate shortestPaths.
   shortestPaths = readPaths();
   network.setODTsMap(shortestPaths);
   //reads in route files to shortestPaths.
   //need to combine into a single function.


   //Section 2.1

   VehicleFiles vehicleData = allOrNothingAssisgnment(network.getODTsMap(), scenarios, iteration);
   //for each scenario assign vehicles
   //output: files 'Vehicles.*'
   //written from scratch //why is the iteration needed?
   //will likely use a VehicleFiles data structure

   //Section 3
   ScenarioLinkCost scenarioLinkCost;
   for (int i = 0; i < scenarios.getScenario()[i].getData(); i++) // i might start at 1 if scenarios is a vector
   {
   scenarioLinkCost.getCost()[scenarios.getScenario()[i].getName()] =
   dynamicNetworkLoading(n, scenarios.getScenario()[i]);
   //input: vista files (at least base.RouteIndex...), network?
   //output: link cost matrix for that scenario
   }
   //output: scenario link cost matrices

   bool converges = false;

   converges = doesConverge(); //what are inputs?  -> Path Set and Generalised link costs?
   //stop ever if doesnt converge?
   //input: just iteration? (or gap as well)

   if (doesConverge()) //error class needed
   {
   bool error = true;
   }

   while (!converges)
   {
   //Section 4 //shortest path
   std::map <std::string, ODT> newShortestPaths = SSTDSP(network, scenarioLinkCost); //path for each ODT. what are inputs?
   network.setODTsMap(newShortestPaths); //add SSTDSP to network
   //inputs: link cost matrices, network
   //output: path for each ODT   ie network.Paths

   //Section 5 (its really 4.1) //convert NewShortestPaths to vista format
   network.writeRouteFiles(); //[not tested, but almost done]
   //output: file base.RouteData...
   //Input: NewShortestPaths


   //Section 6
   int iterationNumber; //Not sure where this is set.
   vehicleData = vehicleProportionAssignment(iterationNumber, network.getODTsMap(), vehicleData, scenarios); //not sure what input is at all
   //output: file for vista: 'Vehicle.*' and VehicleData (in RAM)
   //for every scenario
   //input: number of NewShortestPaths (iterationNumber), NewShortestPaths, vehicles (sorted by travel time)

   //Section 7  (same as Section 3)
   for (int i = 0; i < scenarios.getScenario()[i].getData(); i++) // i might start at 1 if scenarios is a vector
   {
   scenarioLinkCost.getCost()[scenarios.getScenario()[i].getName()] =
   dynamicNetworkLoading(network, scenarios.getScenario()[i]);
   }
   //should have scenario link cost matrices = SLinkCost

   //Section 8
   converges = doesConverge(); //what are inputs?  -> Path Set and Generalised link costs?
   }//Section 9 is the loop

   //Section 10
   writeOutput(); //what is input (ie what are we outputting?)
   //Output: Vehicle.*, base.RouteData...(might be done in section 5), maybe vista travel times and anything else needed to restart.

   }

   /*todo:
   output file that can be read in from a current iteration and have the process continue from there.

   */

}

void Network::initialSP()
{

}

void Network::SSTDSP() 
{

}

void Network::readRouteFiles() //populates ODTsMap_ from the base.route files
{
   //only called at the beginning (freeflow iteration)
   std::string command1 = "python /var/opt/vtg/lib/vista/vista/test_james_1/base_extract_new.py " //Need to make relative paths
      "/var/opt/vtg/lib/vista/vista/test_james_1"; //same line continued
   system(command1.c_str()); //change to direct output into a stringstream

   std::string line;
   std::string entry;
   std::string hash, origin, destination, steps, link, ODT;
   std::ifstream file("/var/opt/vtg/lib/vista/vista/test_james_1/python_route.txt");
   std::vector<Link> linkSet;
   Link tempLink = Link();
   //Path pathEntry;
   //std::vector<Path> pathEntryWhole;
   //std::map <std::string, ODT> pathSet; //not being used normally
   if (file.is_open())
   {
      //std::cout << "File open" << endl;
      bool isFieldRow = true;
      while (std::getline(file, line))
      {
         std::stringstream linestream(line);
         //std::cout << "Entered first while loop" << endl;
         if (isFieldRow)
         {
            //do nothing, skip to next line
            //std::cout << "Field row. " << endl;
            isFieldRow = false;
         }
         else  //need a ODT string instead of a hash
         {
            linkSet.clear();
            std::getline(linestream, hash, ','); // useless for our program, but used by addpaths i think
                                                 //std::cout << hash << ',';
            std::getline(linestream, origin, ',');
            //std::cout << origin << ',';
            std::getline(linestream, destination, ',');
            //std::cout << destination << ',';
            std::getline(linestream, steps, ',');
            //std::cout << steps << ", Links: ";
            //while (std::getline(linestream, links, ','))  //or i = 0; while (i < std::atoi(steps.c_str()))
            for (int i = 0; i < std::atoi(steps.c_str()); i++)
            {
               std::getline(linestream, link, ',');
               tempLink.setName(std::atoi(link.c_str()));
               linkSet.push_back(tempLink);
               //std::cout << tempLink.getName() << ',';
            }
            std::string time = ""; // needs to be added in
            ODT = origin + destination + time;
            /*for (int i = 0; i < linkSet.size(); i++)
            {
            std::cout << linkSet[i].getName() << ' ';
            }*/
            Path pathEntry(linkSet);
            //std::cout << endl << endl << endl << endl ;
            for (int i = 0; i < pathEntry.getLinks().size(); i++)
            {
               //std::cout << pathEntry.getLinks()[i].getName() << ' ';
            }
            //std::cout << "\n";
            pathEntry.setHash(std::atoi(hash.c_str()));
            /*std::cout << "Before pathEntry added" << endl;
            pathEntryWhole.push_back(pathEntry);
            std::cout << "After pathEntry added. Total paths (size) so far: " << pathEntryWhole.size() << endl;*/

            //??what if pathSet[ODT] doesnt already exist?? 

            ODTsMap_[ODT].setOrigin(std::atoi(origin.c_str())); //need to do this?
            ODTsMap_[ODT].setDestination(std::atoi(destination.c_str())); //need to do this?
            ODTsMap_[ODT].addPath(pathEntry); //std::cout "Path added"
                                              //std::cout << "ODTsMap_[" << ODT << "] size: " << ODTsMap_[ODT].getPaths().size() << endl;
         }
      }
      file.close();
      std::cout << "File closed." << std::endl;
      //std::cout << "ODTsMap_ total size: " << ODTsMap_.size() << endl; //only stores unique paths
      //std::cout <<"size of first path in [12]: " << ODTsMap_["12"].getPaths()[0].getLinks().size() << endl;
      //std::cout << "proof we can touch the path\n";
   }

}

void Network::writeRouteFiles() //adjust
{
   //need to navigate to correct directory  (RouteFile->add)
   //delete existing base.route files

   //appends to/creates base.RouteIndex and base.RouteData files -> do not need to store in memory
   //there is existing c++ code to make the seperate files. either: 
   //	dropbox/VISTA/addpaths.cpp
   //	vista@129.94.56.93     /home/vista/VISTA_DEV_CODE/addpaths.cpp //added some comments and std::cout messages to this one

   vista::route::RouteFile * routefile;
   routefile = new vista::route::RouteFile("base", 0);
   std::cout << "Route file is open? : " << routefile->isOpen() << std::endl;
   routefile->reset(true);

   unsigned int path_id;

   path_id = -1;

   //iterate through newShortestPaths (ODT)
   std::map <std::string, ODT>::iterator iter;
   for (iter = ODTsMap_.begin(); iter != ODTsMap_.end(); iter++)
   {
      vista::route::RouteFileEntry entry;//this is an important bit - the VISTA object for the route file
      v_id * links;//this is a pointer of type v_id, which point to the links of the path
      path_id++;

      entry.setOrigin(iter->second.getOrigin());
      entry.setDestination(iter->second.getDestination());

      std::vector<Path> entryPaths = iter->second.getPaths();
      std::vector<Path>::iterator iter2;
      for (iter2 = entryPaths.begin(); iter2 != entryPaths.end(); iter2++)
      {
         entry.setSize(iter2->getSize());
         links = entry.getLinks(); //this should be empty at this point.
         std::vector<Link> entryPathLinks = iter2->getLinks();
         std::vector<Link>::iterator iter3;
         int j = 0;
         for (iter3 = entryPathLinks.begin(); iter3 != entryPathLinks.end(); iter3++)
         {
            iter3->getName() >> links[j];       //assuming links[j] refers to linkid (or name in this case)
                                                //what use does links[] serve? 
                                                //addpaths works and this is based off that.
            j++;
         }
         routefile->add(path_id, entry); //will also increment path_id

      }//continue this loop until entry added i think


   }
}

void Network::MSAAssignment(int iteration)
{

}

void Network::networkLoading()
{

}

void Network::costExtraction()
{

}

bool Network::convergenceCheck()
{

}

void Network::prepareOutput()
{

}

void Network::freeFlowShortestPath() //is this the same as initial SP?
{
   // "$VISTABASE_DIR/libexec/vista/msa-dta -U $USER -P $PASSWORD -n $NETWORK -I 1"
   // becomes: "/opt/vtg/libexec/vista/msa-dta -U $USER -P $PASSWORD -n StrUEDTA_test -I 1"
   //assuming 'StrUEDTA_test' doesnt need to be in quotations. This is the name of the SQL table for the network.
   std::string command1 = "/opt/vtg/libexec/vista/msa-dta -U $USER -P $PASSWORD -n " + name_ + " -I 1";
   system(command1.c_str());            //.c_str() converts to const char*
                                        //mel needs to create the 'StrUEDTA_test' network   (name_ here would be StrUEDTA_test)
                                        //? where will this output the files? with the network's other files? "var/opt/vtg/lib/vista/vista/test_james_1"?
                                        //? does 'test_james_1' need to have the same name as 'StrUEDTA_test'?

   std::map <std::string, ODT> shortestPaths;
   //read in paths (do not know if this can be done with readRouteFiles)
   setODTsMap(shortestPaths);
}


//Management:

std::string Network::getName()
{
   return name_;
}

void Network::setName(std::string name)
{
   name_ = name;
}

int Network::getNumTimeSteps()
{
   return numTimeSteps_;
}

void Network::setNumTimeSteps(int numTimeSteps)
{
   numTimeSteps_ = numTimeSteps;
}

int Network::getNumDeparturePeriods()
{
   return numDeparturePeriods_;
}

void Network::setNumDeparturePeriods(int numDeparturePeriods)
{
   numDeparturePeriods_ = numDeparturePeriods;
}

int Network::getNumScenarios()
{
   return numScenarios_;
}

void Network::setNumScenarios(int numScenarios)
{
   numScenarios_ = numScenarios;
}

std::map <std::string, ODT> Network::getODTsMap()
{
   return ODTsMap_;
}

void Network::setODTsMap(std::map <std::string, ODT> ODTsMap)
{
   ODTsMap_ = ODTsMap;
}

std::map<int, Scenario> Network::getScenariosMap()
{
   return ScenariosMap_;
}

void Network::setScenariosMap(std::map<int, Scenario> ScenariosMap)
{
   ScenariosMap_ = ScenariosMap;
}

std::map<int, Link> Network::getLinksMap()
{
   return LinksMap_;
}

void Network::setLinksMap(std::map<int, Link> LinksMap)
{
   LinksMap_ = LinksMap;
}









void Network::printODTPaths()  //has issues with the name and doesnt allow for time dependant paths yet
{
   std::vector<Link> test1;
   int test2;
   std::map <std::string, ODT>::iterator iter;
   for (iter = ODTsMap_.begin(); iter != ODTsMap_.end(); iter++)
   {
      std::cout << "Origin: " << iter->second.getOrigin() << ", ";
      std::cout << "Dest: " << iter->second.getDestination() << std::endl;
      std::cout << "Number of paths: " << iter->second.getPaths().size() << std::endl;
      std::cout << "Size of first Path: " << iter->second.getPaths()[0].getSize() << std::endl;
      std::cout << "Paths (displaying link names, not nodes): " << std::endl;

      for (int i = 0; i < iter->second.getPaths().size(); i++) //8 times too many
                                                               //std::vector<Path>::iterator iter2;
                                                               //for (iter2 = iter->second.getPaths().begin(); iter2 != iter->second.getPaths().end(); iter2++)
      {
         std::cout << "   ";
         //std::cout << "entered 2nd for loop" << endl;
         std::cout << "PathString: " << iter->second.getPaths()[i].getPathString() << std::endl;
         //std::cout << "attempting iter2->getHash()" << endl;
         //std::cout << iter->second.getPaths()[i].getHash() << endl;
         // std::cout << "attempting iter2->getSize()" << endl;
         //std::cout << iter->second.getPaths()[i].getSize() << endl;
         //std::cout << "attempting getLinks()..." << endl;
         //test1 = iter->second.getPaths()[i].getLinks();  //ERROR on this line
         //std::cout << "getLinks() passed" << endl;
         //test2 = iter->second.getPaths()[i].getLinks().size();
         // std::cout << "iter2->getLinks().size() passed" << endl;
         // std::cout << "Size of iter2's path: " << iter->second.getPaths()[i].getLinks().size() << endl; //ERROR on this line
         //test whether getLinks is the issue, or .size()
         //std::vector<Link>::iterator iter3;
         //std::cout << "created iter3" << std::endl;
         std::cout << "Link Loop: ";
         for (int j = 0; j < iter->second.getPaths()[i].getLinks().size(); j++)
            //for (iter3 = iter->second.getPaths()[i].getLinks().begin(); iter3 != iter->second.getPaths()[i].getLinks().end(); iter3++)
         {
            //std::cout << "entered 3nd for loop" << std::endl;
            std::cout << iter->second.getPaths()[i].getLinks()[j].getName() << ',';
         }
         //std::cout << "exited 2nd for loop" << std::endl;
         std::cout << std::endl;
      }


      std::cout << std::endl;
   }
   std::cout << std::endl << "Finished printing ODTsMap_" << std::endl;
}


//Not sure if needed: 

 /*
std::vector<Link> Network::getArrivingLinkList(int nodeName)   //why not use the node itself?
{ 
   std::vector<int> linkBeginnings = nodeArray_[nodeName].getArrivingLinkList();
	int numLinks = nodeArray_[nodeName].getNumArrivingLinks();
	std::vector<Link> arrivingLinkList;
	for(int i = 0; i < numLinks; i++)
   {
		//std::cout << linkBeginnings[i] << " -> " << nodeName << endl;
      arrivingLinkList.push_back(LinksMap_[linkBeginnings[i]][nodeName]);
	}
	return arrivingLinkList;
}

bool Network::createLink(int name, Node start, Node end, std::map<int, std::map<int, double> > costs) //need to update
{   	
	bool result = true;
	int numPossibilities;
	//std::cout << "Starting Link Creation" << endl;
   bool startExists = false;
   bool endExists = false;
   std::vector <Node>::iterator iter1;
   for (iter1 = nodeArray_.begin(); iter1 != nodeArray_.end(); iter1++)
      {
         if (iter1->getName() == start.getName())
         {
            startExists = true;
         }
         if (iter1->getName() == end.getName())
         {
            endExists = true;
         }
      }
   if (startExists && endExists)
   {
      Link newLink(name, start, end, costs);
      LinksMap_[start.getName()][end.getName()] = newLink;  //LinksMap_ only a single vector now
   }
   else 
   {
		result = false;// if nodes are not already in the network.
	}
	return result;
}

void Network::addPath(int origin, int destination, int timestep, Path path)
{
   std::stringstream ss;
   ss << origin << "_" << destination << "_" << timestep;
   std::string odt = ss.str();

   ODTsMap_[odt].addPath(path);

   /*
   std::vector<Path>::iterator iter = find(ODTsMap_[odt].begin(), ODTsMap_[odt].end(), path);

   if (iter == ODTsMap_[odt].end())	{ //true if path is not in Paths[odt] (the vector of paths for each odt)
   ODTsMap_[odt].push_back(path);
   }*/
   //add to vista as well

}
*/














