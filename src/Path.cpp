#include "Path.h"

using namespace std;

Path::Path() {

}

Path::Path(std::vector<Link> links) {
	links_ = links;
   setPathString();
}

Path::~Path() {

}

int Path::getSize()
{
   return links_.size();
}

double Path::pathCost(int scenario, int timestep) {
	double cost = 0;
	for (std::vector<Link>::iterator iter = links_.begin(); iter != links_.end(); ++iter) {
		cost = cost + iter->getCost(scenario, timestep);
	}
	return cost;
}

double Path::getFlowFraction()
{
   return flowFraction_;
}

void Path::setFlowFraction(double flowFraction)
{
   flowFraction_ = flowFraction;
}

std::vector<Link> Path::getLinks()
{
   return links_;
}

void Path::setLinks(std::vector<Link> links)
{
   links_ = links;
   setPathString();
}

int Path::getHash()
{
   return hash_;
}

void Path::setHash(int hash)
{
   hash_ = hash;
} 

std::string Path::getPathString()
{
   return pathString_;
}

void Path::setPathString()
{
   //std::cout << "Setting path string" << std::endl;
   std::string pathString;
   std::ostringstream convert;
   std::vector<Link>::iterator iter1;
   for (iter1 = links_.begin(); iter1 != links_.end(); iter1++)
   {
      convert.str("");
      convert.clear();
      if (iter1 != links_.begin())
      {
         pathString = pathString + '_';
      }
      convert << iter1->getName();
      //std::cout << "iter1's name: " << convert.str() << std::endl;
      pathString = pathString + convert.str();
   }
   pathString_ = pathString;
}





