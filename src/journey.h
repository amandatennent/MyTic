#ifndef __Assignment_2__journey__
#define __Assignment_2__journey__

#include <stdio.h>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "station.h"
#include "utilities.h"
#include "prices.h"

class Journey
{
private:
    struct tm startTime;
    struct tm endTime;
    Station* startStation;
    Station* endStation;
    std::string userID;
    std::string zone;
public:
    Journey(); // Default Constructor
    ~Journey(); // Default Desconstructor
    Journey(Station*, Station*, struct tm, struct tm, std::string, std::string);
    //Journey* createJourney(std::map<std::string, Station*> &stations);
    void getStation(std::map<std::string, Station*> &stations, Station* &station);
    struct tm getDate();
    std::string getStartStation();
    std::string getEndStation();
    Station* getStartStationObj();
    Station* getEndStationObj();
    struct tm getStartTime();
    struct tm getEndTime();
    std::string getZone();
    friend std::ostream& operator << (std::ostream& , Journey*);
};

#endif /* defined(__Assignment_2__journey__) */
