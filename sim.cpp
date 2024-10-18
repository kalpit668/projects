//sim.cpp file
//Sharma, Kalpit
//ksharma12
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "cust.h"
#include "pqueue.h"

//constants for calculations
const int COST_PER_ITEM = 3;
const int SHOP_TIME_PER_ITEM = 2;
const int CHECKOUT_TIME_PER_ITEM = 1;
const int ROB_TIME = 7;
const int STARTING_CHECKER_CASH = 250;

// function for validating the input
bool is_valid_integer(const char* str) {
    int start = 0;
    // Allow negative sign for the first character
    if (str[0] == '-') {
        start = 1; // Start checking digits from the next character
    }
    if (str[start] == '\0') {
        return false; // Empty or only '-' is not valid
    }
    // Check if every character in the string after the sign (if present) is a digit
    for (int i = start; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// function for reading input
void read_input(ifstream &ifile, PQueue &arrivalPQueue){
    string name;
    int arrival_time;
    string role;
    int item_count;

    while (ifile >> name >> role >> arrival_time >> item_count){
        bool is_robber = (role == "robber"); // checking for the role to return true / false
        Cust* new_customer = new Cust(name, is_robber, arrival_time, item_count);
        arrivalPQueue.enqueue(new_customer, arrival_time);
    }
}

// function for simulation
void run_simulation(int checker_count, PQueue &arrivalPQueue, int checker_break_duration, ostream &os) {
    struct Checker {
        int m_cash;        // Current cash in this checker's register
        int m_done_time;   // Clock when the checker will finish checking out current customer or will finish a break
        Cust* m_cust;      // Pointer to the current customer being checked out, or nullptr if no customer is being helped
    };
    //initializing checkers array 
    Checker* checkers = new Checker[checker_count];
    for (int i = 0; i < checker_count; i++) {
        checkers[i].m_done_time = 0;
        checkers[i].m_cash = STARTING_CHECKER_CASH;
        checkers[i].m_cust = nullptr;
    }
    //initializing shopping queue and checker queue
    PQueue Shopping_queue;
    PQueue Checker_queue;
    
    int customer_count = arrivalPQueue.getSize();
    int clock;

    // for loop to run the simulation clock
    for (clock = 1; 0 < customer_count; clock++) {

        // Check customers arriving at the store
        while (true) {
            Cust* arriving_customer = nullptr;
            int priority;
            //customer on the arrival queue with a priority equal to the current clock
            if (arrivalPQueue.getFirstPriority(priority) && priority == clock) {
                arrivalPQueue.dequeue(arriving_customer);
                // Output customer entering the store
                arriving_customer->outputEnteredStore(os,clock);
                //Update shopping duration
                int shopping_duration = arriving_customer->getItemCount() * SHOP_TIME_PER_ITEM;
                int done_shopping_time = clock + shopping_duration;
                Shopping_queue.enqueue(arriving_customer, done_shopping_time);
            } else {
                break;
            }
        }

        // Check customers done shopping
        while (true) {
            Cust* finished_shopping_customer = nullptr;
            int shopping_priority;
            //customer on the shopping queue that is done shopping has a priority equal to the current clock
            if (Shopping_queue.getFirstPriority(shopping_priority) && shopping_priority == clock) {
                Shopping_queue.dequeue(finished_shopping_customer);
                // Output customer done shopping
                finished_shopping_customer->outputCustomerDone(os,clock);
                Checker_queue.enqueue(finished_shopping_customer, 0);  // Priority for the checker queue is always 0
            } else {
                break;
            }
        }

        // Handle checkers who are done with a customer
        for (int i = 0; i < checker_count; ++i) {
            Checker& checker = checkers[i];
            //For each checker in the checker array that is done checking out a customer 
            if (checker.m_cust != nullptr && checker.m_done_time == clock) {
                Cust* customer = checker.m_cust;
                //check for robber or shopper
                if (!customer->getIsRobber()) {
                    // Shopper paid
                    int payment = customer->getItemCount() * COST_PER_ITEM;
                    checker.m_cash += payment;
                    // Output shopper paying
                    customer->OutputShopperPaying(os, payment, i, clock);
                } else {
                    // Robber stole
                    customer->OutputRobberStole(os,checker.m_cash, i, clock);
                    //update m_done_time
                    checker.m_done_time = clock + checker_break_duration; 
                    checker.m_cash = 0; // Set break time for robbers
                }
                //decrease customer count
                customer_count--;
                delete customer;
                checker.m_cust = nullptr;
            }
        }

        // Assign new customers to available checkers
        for (int i = 0; i < checker_count; ++i) {
            Checker& checker = checkers[i];
            //For each checker in the checkers array that is available
            if (checker.m_done_time <= clock && checker.m_cust == nullptr) {
                if (!Checker_queue.isEmpty()) {
                    Cust* customer;
                    Checker_queue.dequeue(customer);
                    checker.m_cust = customer;
                    //check for robber or shopper
                    if (!customer->getIsRobber()) {
                        checker.m_done_time = clock + customer->getItemCount() * CHECKOUT_TIME_PER_ITEM;
                    } else {
                        checker.m_done_time = clock + ROB_TIME;
                    }
                    // Output customer starting checkout
                    customer->OutputCustomerCheckout(os, clock,i);
                    
                }
            }
        }
    }

    // After the simulation loop, output final cash in each register and the final clock time
    for (int i = 0; i < checker_count; ++i) {
        os << "registers[" << i << "] = $" << checkers[i].m_cash << endl;
    }
    os << "time = " << clock << endl;
    delete[] checkers;
}

int main(int argc, char *argv[])
{
    
    PQueue arrivalPQueue;
    if (argc < 5)
    {   
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }

    if (argc > 5)
    {   
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }

    int checker_Count;
    if (is_valid_integer(argv[1]))
    {   
        checker_Count = atoi(argv[1]);
        if (checker_Count < 1)
        {   
            cerr << "Error: invalid number of checkers specified." << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "Error: invalid number of checkers specified." << endl;
        exit(1);
    }

    int checker_break_length;
    if (is_valid_integer(argv[2]))
    {
        checker_break_length = atoi(argv[2]);
        if (checker_break_length < 0)
        {
            cerr << "Error: invalid checker break duration specified." << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "Error: invalid checker break duration specified." << endl;
        exit(1);
    }

    ifstream input_file(argv[3]);
    if (!input_file)
    {   
        cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
        exit(1);
    }

    ofstream output_file(argv[4]);
    if (!output_file)
    {
        cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
        exit(1);
    }

    read_input(input_file, arrivalPQueue);

    run_simulation(checker_Count, arrivalPQueue,checker_break_length, output_file);
    return 0;
}
