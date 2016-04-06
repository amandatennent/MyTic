//
//myTic.h
//
// MyTic class
//

#ifndef __MYTIC_H__
#define __MYTIC_H__

#define MAX_TRAVELPASSES 100

#include <cstdlib>
#include <vector>
#include "travelPass.h"
#include "utilities.h"
#include "user.h"
#include "prices.h"
#include "deletePointers.cpp"

class MyTic
{
private:
    float credit;
    static float limit;
    bool doPurchase(TravelPass*);
    int convertToCharge(std::string str);
    std::vector<TravelPass*> passes;
    std::string primaryUser;
  
public:
    MyTic();
    MyTic(float theCredit, std::string thePrimaryUser);
    virtual ~MyTic() = 0;
    void input() ;  // Data input for a MyTic object
    void print() ;  // Data output for a MyTic object
    float getCredit() const;   //Note the use of const
    float getLimit() const;
    void chargeMyTic();
    std::string getPrimaryUser() const;
    void setPrimaryUser(std::string thePrimaryUser);
    std::vector<TravelPass*> getPasses();
    void reduceBalance(double) throw (InsufficientFunds);
    void addTravelPass(TravelPass* pass);
};

#endif
