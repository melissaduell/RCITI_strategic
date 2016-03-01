/*
 * Network.h
 *
 *  Created on: Jul 10, 2013
 *      Author: gwdu818
 */
									

#ifndef STREUDTA_NETWORK_H_
#define STREUDTA_NETWORK_H_

#define STARTNODE 0
#define ENDNODE 1
#define TIMESTEP 2
#define FIRSTPROBABILITY 3
#define LINK_DEFINITION 3

//need to check which of these is necessary
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <map>

#include "Node.h"
#include "Link.h"
#include "Path.h"
#include "ODT.h"
#include "Scenario.h"
#include "Network.h"
#include "Path.h"
#include "./vista/RoadRouteDAO.h"
#include "./vista/VehicleDot.h"
#include "./vista/FileStore.hpp"


class Network {
public:
   Network();
   Network(int numNodes, int numTimeSteps, int nbScenarios);
   ~Network(); 

   //operations
   void importData(); 
   void readOptions();
   void importScenarios();
   void importDemandData();
   void importNetworkData();
   void StrUEDTA();
   void initialSP();
   void SSTDSP();
   void readRouteFiles();
   void writeRouteFiles();
   void MSAAssignment(int iteration);
   void networkLoading();
   void costExtraction();
   bool convergenceCheck();
   void prepareOutput();
   void freeFlowShortestPath(); //is this the same as initialSP()?

   //Management
   std::string getName();
   void setName(std::string name);
   int getNumTimeSteps();
   void setNumTimeSteps(int numTimeSteps);
   int getNumDeparturePeriods();
   void setNumDeparturePeriods(int numDeparturePeriods);
   int getNumScenarios();
   void setNumScenarios(int numScenarios);
   std::map <std::string, ODT> getODTsMap();
   void setODTsMap(std::map <std::string, ODT> ODTsMap);
   std::map<int, Scenario>  getScenariosMap();
   void setScenariosMap(std::map<int, Scenario> ScenariosMap);
   std::map<int, Link> getLinksMap();
   void setLinksMap(std::map<int, Link> LinksMap);
   void printODTPaths();
   //need getters and setters for all data
   
   /*not sure if needed:   
   std::vector<Link> getArrivingLinkList(int nodeName); 
   bool createLink(int name, Node start, Node end, std::map<int, std::map<int, double> > costs);
   void addPath(int origin, int destination, int timestep, Path path); //move to ODT Class?
   */
 
private:
   std::string name_;
   int numTimeSteps_;
   int numDeparturePeriods_;
   int numScenarios_;
   std::map<std::string, ODT>           ODTsMap_; 
   std::map<int, Scenario>         ScenariosMap_;
   std::map<int, Link>                 LinksMap_;
};


#endif // STREUDTA_NETWORK_H_ 
