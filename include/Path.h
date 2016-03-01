#ifndef STREUDTA_PATH_H
#define STREUDTA_PATH_H

#include <vector>
#include <sstream> 
#include <iostream>

#include "Link.h"

class Path  //Path needs a name element. also add a static int pathCounter to create unique path names
{
public://not using private for efficiency (not sure if needed)
	Path();
	Path(std::vector<Link> links);
	~Path();
   int getSize();
   double pathCost(int scenario, int timestep);
   double getFlowFraction();
   void setFlowFraction(double flowFraction);
   std::vector<Link> getLinks();
   void setLinks(std::vector<Link> links);
   int getHash();
   void setHash(int hash);
   std::string getPathString();
   void setPathString(); //only used in constructors
   
	
private:
   double flowFraction_;
   std::vector<Link> links_;
   int hash_;
   std::string pathString_;
};

#endif  // STREUDTA_PATH_H
