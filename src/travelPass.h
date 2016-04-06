//
// travelPass.h
//
// Parent TravelPass class
//

#ifndef __TRAVELPASS_H__
#define __TRAVELPASS_H__


#include <string>
#include <iostream>
#include "utilities.h"
#include <iomanip>
#include <ctime>
#include <vector>
#include "journey.h"
#include "prices.h"
#include "exceptions.h"
#include "deletePointers.cpp"

class TravelPass
{
protected:
    std::string length;
    std::string zones;
    float cost;
    struct tm startTime;
    struct tm endTime;
    std::vector<Journey*> journeys;
    bool concession;
  
public:
    TravelPass();
    TravelPass(std::string, std::string, float, struct tm, struct tm, bool);
    ~TravelPass() ;
    void input() ;   // Data input for a TravelPass object
    void print() ;  // Data output for a TravelPass object

    std::string getLength() const;   // Note the use of const
    std::string getZones() const;
    float getCost() const;
    struct tm getStartTime() const;
    struct tm getEndTime() const;
    void setLength(std::string newLength);
    void setZones(std::string newZones);
    void setCost( float  newCost);
    double upgradeToAllDay(double) throw (InsufficientFunds);
    void addJourney(Journey* journey);
    double upgradeZones(double userBalance) throw (InsufficientFunds);
    double upgradeZonesAndDuration(double userBalance) throw (InsufficientFunds);
    std::string getOutput();
    std::string getLengthStr();
    std::vector<Journey*> getJourneys();
    bool getConcession();
    friend std::ostream& operator << (std::ostream& , TravelPass*);
};

#endif
