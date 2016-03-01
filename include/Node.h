/*
 * Node.h
 *
 *  Created on: Jul 10, 2013
 *      Author: gwdu818
 */

#ifndef STREUDTA_NODE_H_
#define STREUDTA_NODE_H_

#include <vector>

#define NUM_LINKS 4

class Node {
public:
	Node();
	Node(int name, int numTimeSteps);
	virtual ~Node();
	//bool canTravel(int toNode);
	void addStartingLink(int destination);
	void addEndingLink(int beginning);
   std::vector<int> getLeavingLinkList();//vector of node names
   std::vector<int> getArrivingLinkList();///vector of node names
    int getNumArrivingLinks();
    int getNumLeavingLinks();
    int getName();
    void printNode();

private:
   int name_;
   std::vector<int> nodesWithLinksToHere_; 
   int numArrivingLinks_;
   std::vector<int> destinationOfLinksFromHere_; 
   int numLeavingLinks_;
};



#endif // STREUDTA_NODE_H_ 
