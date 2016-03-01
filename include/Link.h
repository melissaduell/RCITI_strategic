/*
 * Link.h
 *
 *  Created on: Jul 10, 2013
 *      Author: gwdu818
 */

#ifndef STREUDTA_LINK_H_
#define STREUDTA_LINK_H_

#include <vector>
#include <map>

#include "Node.h"



class Link {
public:
	Link();
	Link(int name, Node start, Node end, std::map<int, std::map<int, double> > costs);
	~Link();
   int getName();//unique (from database)
   void setName(int name); // only used in constructor - keep?
	Node getDestination();
	Node getBeginning();
	void setCost(std::map<int, std::map<int, double> > costs);
	double getCost(int scenario, int timestep);
	void printLink();

private:
   int name_;
   Node destination_;
   Node beginning_;
   std::map<int,std::map<int,double> > scenarioTimeCost_; //[scenario][timestep]
};


#endif // STREUDTA_LINK_H_ 
