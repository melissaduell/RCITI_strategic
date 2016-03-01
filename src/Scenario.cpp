#include "Scenario.h"

Scenario::Scenario()
{

}

std::vector<std::vector<int> > Scenario::getScenarioLinkCost()
{
   return scenarioLinkCost_; 
}

void Scenario::setScenarioLinkCost(std::vector<std::vector<int> > scenarioLinkCost)
{
   scenarioLinkCost_ = scenarioLinkCost;
}

int Scenario::getName()
{
   return name_; 
} 


