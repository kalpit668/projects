//cust.cpp file
//Sharma, Kalpit
//ksharma12
#include <iostream>
#include <string>
#include "cust.h"
using namespace std; 

// Add class contructor here...
Cust::Cust(string name, bool is_robber, int arrival_time, int item_count){
    this->setName=name;
    this->setIsRobber=is_robber;
    this->setArrivalTime=arrival_time;
    this->setItemCount=item_count;
    
}

void Cust::print(ostream &os)
{
    if (getIsRobber())
    {
        os<<getName()<<" robber "<<getArrivalTime()<<" "<<getItemCount()<<endl;
    }
    else
    {
         os<<getName()<<" shopper "<<getArrivalTime()<<" "<<getItemCount()<<endl;
    }
}
string Cust::getName(){
    return setName;
}
bool Cust::getIsRobber(){
    return setIsRobber;
}
int Cust::getArrivalTime(){
    return setArrivalTime;
}
int Cust::getItemCount(){
    return setItemCount;
}
void Cust::outputEnteredStore(ostream &os, int clock) {

os << clock << ": " << this->getName() << " entered store" << endl;
}
void Cust::outputCustomerDone(ostream &os,int clock) {
    os << clock << ": " << this->getName() << " done shopping" << endl;
}
void Cust::OutputShopperPaying(ostream &os,int payment, int i, int clock){
    os << clock << ": " << this->getName() << " paid $" << payment
                       << " for " << this->getItemCount() << (this->getItemCount() == 1 ? " item" : " items")
                       << " to checker " << i << endl;
}
void Cust::OutputRobberStole(ostream &os, int m_cash, int i, int clock){
    os << clock << ": " << this->getName() << " stole $" 
                       <<  m_cash << " and "
                       << this->getItemCount() << (this->getItemCount() == 1 ? " item" : " items")
                       << " from checker " << i << endl;
}
void Cust::OutputCustomerCheckout(ostream &os, int clock, int i){
    os << clock << ": " << this->getName() << " started checkout with checker " << i << endl;
}