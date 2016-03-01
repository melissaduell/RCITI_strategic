#include "ODT.h"


ODT::ODT()
{
   nPaths = 0;
}

int ODT::getOrigin()
{
   return origin_;
}

void ODT::setOrigin(int origin)
{
   origin_ = origin; 
}

int ODT::getDestination()
{
   return destination_;
}

void ODT::setDestination(int destination)
{
   destination_ = destination;
}

int ODT::getTimestep()
{
   return timestep_;
}

void ODT::setTimestep(int timestep)
{
   timestep_ = timestep;
}

/*std::vector<double> ODT::getFlowFractions() //to get them, use getPaths and iterate through that, using getFlowFraction
{
   return flowFraction_;
}

void ODT::setFlowFractions(std::vector<double> flowFraction)
{
   flowFraction_ = flowFraction;
}*/

std::vector<Path> ODT::getPaths()
{
   return paths_;
}

void ODT::setPaths(std::vector<Path> paths)
{
   paths_ = paths;
}

void ODT::addPath(Path path)
{
   if (!isPathIncluded(path)) 
   {
      paths_.push_back(path);
      std::cout << "Path added" << std::endl;
   }
   else 
   {
      std::cout << "Path already exists in ODT object" << std::endl;
   }
}

bool ODT::isPathIncluded(Path path)
{
   std::vector<Path>::iterator iter1;
   for (iter1 = paths_.begin(); iter1 != paths_.end(); iter1++)
   {
      if (iter1->getPathString() == path.getPathString())
      {
         return true;
      }
   }
   return false;
}

bool ODT::isFlowFullyAllocated()
{
   bool result = false;
   double total = 0.0;
   for (std::vector<Path>::iterator iter = paths_.begin(); iter != paths_.end(); iter++)
   {
      total = total + iter->getFlowFraction();
   }
   if (total == 1.0)
   {
      result = true;
   }
   return result;
}
 


