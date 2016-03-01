/*
 * Link.cpp
 *
 *  Created on: Jul 10, 2013
 *      Author: gwdu818
 */

#include <iostream>
#include <stdlib.h>

#include "Link.h"

Link::Link() { 
   //cout << "Empty link created" << endl;
   name_ = -1;
	beginning_ = Node();
	destination_ = Node();
}

Link::Link(int name, Node start, Node end, std::map<int, std::map<int, double> > costs) {
   name_ = name;
	beginning_ = start;
	destination_ = end;
	scenarioTimeCost_ = costs;
}

Link::~Link() {
}

int Link::getName()
{
   return name_;
}

void Link::setName(int name)
{
   name_ = name;
}

Node Link::getBeginning(){
	return beginning_;
}

Node Link::getDestination(){
	return destination_;
}

void Link::setCost(std::map<int, std::map<int, double> > costs){
	scenarioTimeCost_ = costs;
}

double Link::getCost(int scenario, int timestep) {
	return scenarioTimeCost_[scenario][timestep];
}


void Link::printLink(){
   std::cout << getBeginning().getName() << " -> " << getDestination().getName() << std::endl;
} 



