#ifndef STREUDTA_MAIN_H
#define STREUDTA_MAIN_H

//StrEUDTA stands for:

#include <iostream>
#include <vector>
#include <map>

#include "Link.h"
#include "Network.h"
#include "Node.h"
#include "ODT.h"
#include "Path.h"
#include "Scenario.h"
#include "Test.h"

//need to move function definitions into their own .cpp files and class declarations into .h files
//leaving function be for now and it will serve as a checklist of sorts
/*
std::vector<int> dynamicNetworkLoading(Network n, Scenario scenario)
{
   std::vector<int> result; //[numLinks]
	int routeSimOutput = routeSim(n,scenario); //database.RouteSim()? not sure inputs  //vista 
		//feeds into RouteSim
	result = costExtraction(routeSimOutput); // output: link cost matrices     //might be vista
	
	return result; 
}

int routeSim(Network n, Scenario scenario)
{
	//does it just affect database or should it return something. 
	//	If it just changes database, it should be a member function
}

std::vector<int> costExtraction(int routeSimOutput)
{
	//does it just affect database or should it return something. 
	//	If it just changes database, it should be a member function
}

std::map <std::string, ODT> pythonCode(Network n, ScenarioLinkCost output2)
{
   std::map <std::string, ODT> output3;
	//do python stuff
	return output3;
}

std::map <std::string, ODT> SSTDSP(Network n, ScenarioLinkCost output2) // just run python code?
{
   std::map <std::string, ODT> output3 = pythonCode(n,output2); //using boost? using terminal command?
	return output3;
}



VehicleFiles vehicleProportionAssignment(int iterationNumber, std::map <std::string, ODT> shortestPaths,
                                                   VehicleFiles vehicleData,ScenarioList scenarios)
{
	VehicleFiles output5;
	//do stuff
	//	how do we choose which vehicle to move? -> tied to convergence check?

	//MSA

	return output5;
}

bool doesConverge()
{
	bool converges = false;
	//check for convergence here
	//find gap
	return converges;
}

void writeOutput()
{
	//assuming outputing to a file (or multiple)
	//file<<AllOutputDataInNiceFormat
}

VehicleFiles allOrNothingAssisgnment(std::map <std::string, ODT> paths, ScenarioList scenarios, int iteration)
{
	for (int i = 0; i < scenarios.getScenario().size(); i++)
	{
		//create files: Vehicles.*
	}
	//should have a set of Vehicles.* files for each scenario
}

void freeFlowShortestPath(const char* command);


*/
#endif  // STREUDTA_MAIN_H  
