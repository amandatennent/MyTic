#include "Prices.h"

// Initialise variables
double Pricing::allDayZone1 = -1;
double Pricing::allDayZone1and2 = -1;
double Pricing::twoHoursZone1 = -1;
double Pricing::twoHoursZone1and2 = -1;
double Pricing::weekly = -1;
double Pricing::concDisc = 0.5;
const std::string Pricing::TWO_HOUR = "2Hour";
const std::string Pricing::ALL_DAY = "AllDay";
const std::string Pricing::WEEKLY = "Weekly";
const std::string Pricing::ZONE_ONE = "Zone1";
const std::string Pricing::ZONE_ONE_TWO = "Zone12";
const int Pricing::TWO_HOURS_SECONDS = 7200;

double Pricing::getPrice(std::string duration, std::string zone)
    throw (InvalidInput)
{
    if (duration == TWO_HOUR)
    {
        if (zone == ZONE_ONE)
        {
            // Two Hour Zone 1
            return twoHoursZone1;
        }
        else if (zone == ZONE_ONE_TWO)
        {
            // Two Hour Zone 1 & 2
            return twoHoursZone1and2;
        }
        else
            throw InvalidInput();
    }
    else if (duration == ALL_DAY)
    {
        if (zone == ZONE_ONE)
        {
            // All Day Zone 1
            return twoHoursZone1;
        }
        else if (zone == ZONE_ONE_TWO)
        {
            // All Day Zone 1 & 2
            return twoHoursZone1and2;
        }
        else
            throw InvalidInput();
    }
    else
        throw InvalidInput();
}

bool Pricing::checkAnyPricesDefined()
{
    // Checks the pricing information to see if any have been defined
    if (getAllDayZone1() == -1)
        return true;
    
    if (getAllDayZone1and2() == -1)
        return true;
    
    if (getTwoHoursZone1() == -1)
        return true;
    
    if (getTwoHoursZone1and2() == -1)
        return true;
    
    if (getWeekly() == -1)
        return true;
    
    return false;
}

bool Pricing::checkAnyPricesUndefined()
{
    // Checks the pricing information is see if any haven't been defined
    if (getAllDayZone1() == -1)
        return true;
    
    if (getAllDayZone1and2() == -1)
        return true;
    
    if (getTwoHoursZone1() == -1)
        return true;
    
    if (getTwoHoursZone1and2() == -1)
        return true;
    
    if (getWeekly() == -1)
        return true;
    
    return false;
}

void Pricing::updatePrice(std::string name) throw (PriceError)
{
    // This function will prompt the user to update the price of the Travel
    // Pass name
    
    std::cout << "What is the new price? ";
    
    bool correct = false;
    std::string strPrice;
    double price = 0;
    
    do
    {
        std::getline(std::cin, strPrice);
        
        // Check to make sure the entered value is a double
        if (!isDouble(strPrice))
        {
            correct = false;
            std::cout << "Invalid price entered. Please try again: ";
        }
        else
        {
            price = convertToDouble(strPrice);
            
            // Make sure price is 0 or greater
            if (price < 0)
            {
                correct = false;
                std::cout << "Invalid price entered. Please try again: ";
            }
            else
            {
                correct = true;
            }
        }
    } while (correct == false);
    
    
    if (name == "allDayZone1")
        allDayZone1 = price;
    
    else if (name == "allDayZone1and2")
        allDayZone1and2 = price;
    
    else if (name == "twoHoursZone1")
        twoHoursZone1 = price;
    
    else if (name == "twoHoursZone1and2")
        twoHoursZone1and2 = price;
    
    else if (name == "weekly")
        weekly = price;
        
    else
        throw PriceError();
    
    setNumberFormatting();
    std::cout << "The new price is: $" << price << std::endl;
}

std::string Pricing::getPriceOutput()
{
    // returns a string to be used in the output file
    std::stringstream line;
    // 2 Hour Zone 1
    line << "2Hour:Zone1:" << std::fixed << std::showpoint
        << std::setprecision(2) << twoHoursZone1 << std::endl;
    
    // 2 Hour Zone 1 & 2
    line << "2Hour:Zone12:" << std::fixed << std::showpoint
        << std::setprecision(2) << twoHoursZone1and2 << std::endl;
    
    // All Day Zone 1
    line << "AllDay:Zone1:" << std::fixed << std::showpoint
        << std::setprecision(2) << allDayZone1 << std::endl;
    
    // All Day Zone 1 & 2
    line << "AllDay:Zone12:" << std::fixed << std::showpoint
        << std::setprecision(2) << allDayZone1and2 << std::endl;
    
    // Weekly
    line << "Weekly:Zone12:" << std::fixed << std::showpoint
        << std::setprecision(2) << weekly;

    return line.str();
}
