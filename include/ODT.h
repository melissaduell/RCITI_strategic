#ifndef STREUDTA_ODT_H
#define STREUDTA_ODT_H

#include <vector>
#include <algorithm>  
#include <iostream>

#include "Path.h"
#include "Vehicle.h"

class ODT 
{
   friend class Vehicle;
public:
   ODT();
   int getOrigin();
   void setOrigin(int origin);
   int getDestination();
   void setDestination(int destination);
   int getTimestep();
   void setTimestep(int timestep);
   //std::vector<double> getFlowFractions();                   use getPaths, iterate through, and use getFlowFraction
   //void setFlowFractions(std::vector<double> flowFraction);
   std::vector<Path> getPaths();
   void setPaths(std::vector<Path> paths);
   void addPath(Path path);
   bool isPathIncluded(Path path);
   bool isFlowFullyAllocated();

private:
   int origin_;
   int destination_;
   int timestep_; //needed?
   int nPaths;
   std::vector<Path> paths_;
};

#endif  // STREUDTA_ODT_H
