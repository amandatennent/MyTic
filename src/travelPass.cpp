#include "travelPass.h"

TravelPass::TravelPass()
{
    // Default Constructor
}

TravelPass::TravelPass(std::string theLength, std::string theZones, float
                    theCost, struct tm start, struct tm end, bool theConcession)
{
    // Constructor with parameters
    length = theLength;
    zones = theZones;
    cost = theCost;
    startTime = start;
    endTime = end;
    concession = theConcession;
}

TravelPass::~TravelPass()
{
    // Destructor
    // Delete Journey's in vector
    Delete_Pointers(journeys.begin(), journeys.end());
    journeys.clear();
}

void TravelPass::input()
{
    // Data input for a TravelPass object
}

void TravelPass::print()
{
    // Data output for a TravelPass object
    std::cout << length << " pass for " << zones << ", costing $"
    << std::fixed << std::setprecision(2) << cost << std::endl;
}

std::string TravelPass::getLength() const
{
    // Gets the Travel Pass' length
    
    return length;
}

std::string TravelPass::getZones() const
{
    // Sets the Travel Pass' zone
    
    return zones;
}

float TravelPass::getCost() const
{
    // Return's the Travel Pass' cost
    
    return cost;
}

void TravelPass::setLength(std::string newLength)
{
    // Sets the Travel Pass' length
    length = newLength;
}

void TravelPass::setZones(std::string newZones)
{
    // Sets the Travel Pass' zone
    zones = newZones;
}

void TravelPass::setCost(float newCost)
{
    // Sets the Travel Pass' cost
    cost = newCost;
}

struct tm TravelPass::getStartTime() const
{
    return startTime;
}

struct tm TravelPass::getEndTime() const
{
    return endTime;
}

void TravelPass::addJourney(Journey* journey)
{
    journeys.push_back(journey);
}

double TravelPass::upgradeToAllDay(double userBalance) throw (InsufficientFunds)
{
    // Changes the travel pass to an all day pass, and returns the difference
    // in cost

    double newCost;
    
    // Get the cost of the new pass
    if (zones == Pricing::ZONE_ONE)
        newCost = Pricing::getAllDayZone1();
    else
        newCost = Pricing::getAllDayZone1and2();
    
    // Calculate concession discount
    if (concession == true)
        newCost = newCost * (1 - Pricing::getConcession());
    
    // Calculate how much user needs to pay and make sure there's enough to
    // cover it
    double charge = newCost - cost;
    
    if (cost > userBalance)
        throw InsufficientFunds();
    
    // Update variables
    cost = newCost;
    length = Pricing::ALL_DAY;
    startTime.tm_hour = 0;
    startTime.tm_min = 0;
    startTime.tm_sec = 0;
    endTime.tm_hour = 23;
    endTime.tm_min = 59;
    endTime.tm_sec = 0;
    
    return charge;
}

double TravelPass::upgradeZones(double userBalance) throw (InsufficientFunds)
{
    // Changes the travel pass to a Zone 1 and 2 pass, and returns the
    // difference in cost
    
    double newCost;
    
    // Get the cost of the new pass
    if (length == Pricing::ALL_DAY)
        newCost = Pricing::getAllDayZone1and2();
    else
        newCost = Pricing::getTwoHoursZone1and2();
    
    // Calculate Concession Discount
    if (concession == true)
        newCost = newCost * (1 - Pricing::getConcession());
    
    // Calculate how much user needs to pay and make sure there's enough to
    // cover it
    double charge = newCost - cost;
    
    if (cost > userBalance)
        throw InsufficientFunds();
    
    // Update variables
    cost = newCost;
    zones = Pricing::ZONE_ONE_TWO;
    
    return charge;
}

double TravelPass::upgradeZonesAndDuration(double userBalance)
    throw (InsufficientFunds)
{
    // Changes the travel pass to an All day zone 1 and 2 pass, and returns the
    // difference in cost
    
    // Get the cost of the new pass
    double newCost = Pricing::getAllDayZone1and2();
    
    // Calculate concession discount
    if (concession == true)
        newCost = newCost * (1 - Pricing::getConcession());
        
    // Calculate how much user needs to be and make sure there's enough to
    // cover it
    double charge = newCost - cost;
    
    if (cost > userBalance)
        throw InsufficientFunds();
    
    // Update variables
    cost = newCost;
    zones = Pricing::ZONE_ONE_TWO;
    length = Pricing::ALL_DAY;
    startTime.tm_hour = 0;
    startTime.tm_min = 0;
    startTime.tm_sec = 0;
    endTime.tm_hour = 23;
    endTime.tm_min = 59;
    endTime.tm_sec = 0;
    
    return charge;
}

std::string TravelPass::getOutput()
{
    std::string output;
    
    if (length == Pricing::ALL_DAY)
        output = "All day ";
    else
        output = "2 hour ";
    
    if (zones == Pricing::ZONE_ONE)
        output = output + "Zone 1 ";
    else
        output = output + "Zone 1 & 2 ";
    
    if (concession == true)
        output = output + "(concession) ";
    
    output = output + "travel pass purchased for $";
    
    std::stringstream costOutput;
    costOutput.setf(std::ios::fixed);
    costOutput.setf(std::ios::showpoint);
    costOutput.precision(2);
    costOutput << cost;
    
    output = output + costOutput.str() + ". Valid until " +
        get24HourTime(endTime) + ".";
    
    return output;
}

std::string TravelPass::getLengthStr()
{
    if (length == Pricing::ALL_DAY)
        return "All Day";
    else // 2 hour
        return "2 Hour";
}

std::vector<Journey*> TravelPass::getJourneys()
{
    return journeys;
}

bool TravelPass::getConcession()
{
    return concession;
}

std::ostream& operator << (std::ostream& out, TravelPass* pass)
{
    std::string output;
    
    if (pass->getLength() == Pricing::ALL_DAY)
        output = "All day ";
    else
        output = "2 hour ";
    
    if (pass->getZones() == Pricing::ZONE_ONE)
        output = output + "Zone 1 ";
    else
        output = output + "Zone 1 & 2 ";
    
    if (pass->getConcession() == true)
        output = output + "Concession ";
    

    
    output = output + "Travel Pass purchased on "
        + getDayOfWeek(pass->startTime);
    
    if (pass->getLength() == Pricing::TWO_HOUR)
        output = output + " at " + get24HourTime(pass->startTime);
    
    output = output + " for $";
    
    std::stringstream costOutput;
    costOutput.setf(std::ios::fixed);
    costOutput.setf(std::ios::showpoint);
    costOutput.precision(2);
    costOutput << pass->getCost();
    
    output = output + costOutput.str();
    
    out << output;
    
    return out;
}
