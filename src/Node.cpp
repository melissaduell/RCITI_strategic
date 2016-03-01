/*
 * Node.cpp
 *
 *  Created on: Jul 10, 2013
 *      Author: gwdu818
 */

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node() {
	//cout << "BLANK NODE CREATED" << endl;
	this->name_ = -1;
	this->numArrivingLinks_ = 0;
	this->numLeavingLinks_ = 0;
}

Node::~Node() {
}

Node::Node(int name, int numTimeSteps){
	this->name_ = name;
	this->numLeavingLinks_ = 0;
	this->numArrivingLinks_ = 0;
}

void Node::addStartingLink(int destination){
	if(numLeavingLinks_ < NUM_LINKS){
		destinationOfLinksFromHere_[numLeavingLinks_] = destination;
		numLeavingLinks_++;
		//cout << "starting link destination " << destination << endl;
	}
}

void Node::addEndingLink(int beginning){
	if(numArrivingLinks_ < NUM_LINKS){
		nodesWithLinksToHere_[numArrivingLinks_] = beginning;
		numArrivingLinks_++;
	}
}

void Node::printNode(){
	/*
	 * Prints out the node in the following way
	 * name, destination of 1st starting link
	 * name, destination of 2nd starting link
	 * ...
	 * name, destination of nth starting link
	 */
	for(int i = 0; i < this->numLeavingLinks_; i++){
		std::cout<<this->name_<<","<<destinationOfLinksFromHere_[i]<<std::endl;
	}
}

std::vector<int> Node::getLeavingLinkList(){
	return this->destinationOfLinksFromHere_;
}

std::vector<int> Node::getArrivingLinkList(){
	return this->nodesWithLinksToHere_;
}

int Node::getName(){
	return this->name_;
}
int Node::getNumArrivingLinks(){
	return this->numArrivingLinks_;
}
int Node::getNumLeavingLinks(){
	return this->numLeavingLinks_;
}



 


