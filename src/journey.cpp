#include "journey.h"



Journey::Journey()
{
    // Default Constructor
}

Journey::Journey(Station* newStartStation, Station* newEndStation, struct tm
                 newStartTime, struct tm newEndTime, std::string newZone,
                 std::string newUserID)
{
    startStation = newStartStation;
    endStation = newEndStation;
    startTime = newStartTime;
    endTime = newEndTime;
    zone = newZone;
    userID = newUserID;
}

Journey::~Journey()
{
    // Default Desconstructor
}

struct tm Journey::getStartTime()
{
    return startTime;
}

struct tm Journey::getEndTime()
{
    return endTime;
}

std::string Journey::getZone()
{
    return zone;
}

std::string Journey::getStartStation()
{
    return startStation->getName();
}
std::string Journey::getEndStation()
{
    return endStation->getName();
}


std::ostream& operator << (std::ostream& out, Journey* journey)
{
    std::string output = convertToSentenceCase(journey->getStartStation());
    output = output + " to " + convertToSentenceCase(journey->getEndStation());
    output = output + " at " + get24HourTime(journey->getStartTime());
 
    out << output;
    return out;
}

Station* Journey::getStartStationObj()
{
    return startStation;
}

Station* Journey::getEndStationObj()
{
    return endStation;
}

