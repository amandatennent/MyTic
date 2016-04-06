#include "station.h"

Station::Station()
{
    // Default constructor
}

Station::Station(std::string newName, int newZone)
    : name(newName), zone(newZone)
{
    visitsTo = 0;
    visitsFrom = 0;
}

std::string Station::getName()
{
    return name;
}

void Station::setName(std::string newName)
{
    name = newName;
}

int Station::getZone()
{
    return zone;
}

void Station::setZone(int newZone)
{
    zone = newZone;
}

int Station::getNoVisitsTo()
{
    return visitsTo;
}

int Station::getNoVisitsFrom()
{
    return visitsFrom;
}

void Station::addVisitTo()
{
    visitsTo++;
}

void Station::addVisitFrom()
{
    visitsFrom++;
}
std::ostream& operator << (std::ostream& out, Station* station)
{
    std::stringstream strVisitsFrom;
    strVisitsFrom << station->visitsFrom;
    std::stringstream strVisitsTo;
    strVisitsTo << station->visitsTo;
    
    
    std::string output =  convertToSentenceCase(station->name) + ": "
        + strVisitsFrom.str() + " journeys started here, "
        + strVisitsTo.str() + " journeys ended here.";
    
    out << output;
    return out;
}
