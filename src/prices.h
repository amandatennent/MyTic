#ifndef __Assignment_2__Prices__
#define __Assignment_2__Prices__


#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "utilities.h"
#include "exceptions.h"

class Pricing
{
private:
    static double allDayZone1, allDayZone1and2, twoHoursZone1,
        twoHoursZone1and2, weekly, concDisc;

public:
    // Constructors
    Pricing() {  } // Default Constructor - nothing to occur
    double getPrice(std::string duration, std::string zone) throw (InvalidInput);
    // Get & Set Functions
    static void setAllDayZone1(double newPrice) { allDayZone1 = newPrice; }
    static double getAllDayZone1() { return allDayZone1; }
    static void setAllDayZone1and2(double newPrice)
        { allDayZone1and2 = newPrice; }
    static double getAllDayZone1and2() { return allDayZone1and2; }
    static void setTwoHoursZone1(double newPrice) { twoHoursZone1 = newPrice; }
    static double getTwoHoursZone1() { return twoHoursZone1; }
    static void setTwoHoursZone1and2(double newPrice)
        { twoHoursZone1and2 = newPrice; }
    static double getTwoHoursZone1and2() { return twoHoursZone1and2; }
    static void setWeekly(double newWeekly) { weekly = newWeekly; }
    static double getWeekly() { return weekly; }
    static void setConcession(double newConcession) { concDisc = newConcession; }
    static double getConcession() { return concDisc; }
    static bool checkAnyPricesDefined();
    static bool checkAnyPricesUndefined();
    static void updatePrice(std::string name) throw (PriceError);
    static std::string getPriceOutput();
    static std::string getZONE_ONE() { return ZONE_ONE; }
    
    static const std::string TWO_HOUR, ALL_DAY, WEEKLY, ZONE_ONE, ZONE_ONE_TWO;
    static const int TWO_HOURS_SECONDS;
};


#endif /* defined(__Assignment_2__Prices__) */
