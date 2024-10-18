//cust.h file
//Sharma, Kalpit
//ksharma12
#ifndef CUST_H
#define CUST_H
#include <iostream>
#include <string>
using namespace std;

class Cust
{
 public:
  // public member functions go here
  void print(ostream &os);
  Cust(string name, bool is_robber, int arrival_time, int item_count);
  string getName();
    bool getIsRobber();
    int getArrivalTime();
    int getItemCount();
    // string setName;
    // bool setIsRobber;
    // int setArrivalTime;
    // int setItemCount;

    void outputEnteredStore(ostream &os, int clock);
    void outputCustomerDone(ostream &os,int clock);
    void OutputShopperPaying(ostream &os,int payment, int i, int clock);
    void OutputRobberStole(ostream &os,int m_cash, int i, int clock);
    void OutputCustomerCheckout(ostream &os, int clock, int i);
 private:
  // member variables go here
  string setName;
    bool setIsRobber;
    int setArrivalTime;
    int setItemCount;
    // string getName();
    // bool getIsRobber();
    // int getArrivalTime();
    // int getItemCount();
  // member function used only by other member functions go here

}; // don't forget this ;

#endif
