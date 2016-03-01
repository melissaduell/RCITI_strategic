#ifndef STREUDTA_SCENARIO_H
#define STREUDTA_SCENARIO_H

#include <vector>

class Scenario  
{
public:
   Scenario();
   std::vector<std::vector<int> > getScenarioLinkCost();
   void setScenarioLinkCost(std::vector<std::vector<int> > scenarioLinkCost);
   int getName();

private:
   //also need vehicles
   std::vector<std::vector<int> > scenarioLinkCost_;
   int name_;
};

#endif // STREUDTA_SCENARIO_H
