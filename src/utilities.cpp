//
//  Utilities.cpp
//  Week06_Tute01
//
//  Created by Amanda Tennent on 2/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#include "Utilities.h"

int getInt()
{
    // Should add some testing to ensure that only one value is entered
    std::string strNumber;
    float fNumber;
    int iNumber = 0;
    bool correct = false;
    
    do
    {
        // Get the user's input
        std::getline(std::cin, strNumber);
        
        // Convert the string to a float, and correct = false if conversion fails
        std::stringstream convert(strNumber);
        if (!(convert >> fNumber))
        {
            correct = false;
            std::cout << "Incorrect input detected. Please try again: ";
            continue;
        }
        
        // Check to make sure that the number has no fractional part (ie: 0.5)
        iNumber = fNumber;
        if (iNumber != fNumber)
        {
            correct = false;
            std::cout << "Incorrect input detected. Please try again: ";
            continue;
        }
        
        correct = true;
        
    } while (correct == false);
    
    return iNumber;
}

bool isInt(std::string strNumber)
{
    float fNumber;
    int iNumber;
    
    // Convert the string to a float, and return false if conversion fails
    std::stringstream convert(strNumber);
    if (!(convert >> fNumber))
        return false;
    
    // Check to make sure that the number has no fractional part (ie: 0.5)
    iNumber = fNumber;
    if (iNumber != fNumber)
        return false;
    
    return true;
}

int convertToInt(std::string strNumber)
{
    // Converts string to int - assumes that the string parameter has already
    // been tested to ensure it's a string
    
    int iNumber;
    
    // Convert the string to an int
    std::stringstream convert(strNumber);
    convert >> iNumber;
    
    return iNumber;
}

void cpp_strtok(std::vector<std::string>& words, std::string str, char delim)
{
    // Seperates the words values within the string using a char delimiter,
    // adds them to the references string vector.
    
    std::istringstream iss(str);
    std::string token;
    
    while (std::getline(iss, token, delim))
    {
        words.push_back(token);
    }
}

std::string convertToUpper(std::string str)
{
    // function to convert given string to uppercase
    std::string newStr = "";
    
    for (unsigned int i = 0; i < str.length(); i++)
        newStr += toupper(str[i]);
    
    return newStr;
}

std::string convertToLower(std::string str)
{
    // function to convert given string to lowercase
    std::string newStr = "";
    
    for (unsigned int i = 0; i < str.length(); i++)
        newStr += tolower(str[i]);
    
    return newStr;
}

bool isDouble(std::string strNumber)
{
    // Checks if strNumber is a double
    double dNumber;
    
    // Convert the string to a double, and return false if conversion fails
    std::stringstream convert(strNumber);
    if (!(convert >> dNumber))
        return false;
    
    return true;
}

double convertToDouble(std::string strNumber)
{
    // Converts string to int - assumes that the string parameter has already
    // been tested to ensure it's a string
    
    double dNumber;
    
    // Convert the string to a double
    std::stringstream convert(strNumber);
    convert >> dNumber;
    
    return dNumber;
}

void setNumberFormatting()
{
    // Sets the required flags to display numbers correctly
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}

void clearInputBuffer()
{
    // function to clear the input buffer
    char symbol;
    do
    {
        std::cin.get(symbol);
    }
    while(symbol != '\n');
}

void ignore_line ( std::istream& in )
{
    char ch;
    while ( in.get ( ch ) && ch != '\n' );
}

int dateDiff(int day, int month, int year)
{
    // Returns a difference in seconds of a given date to the current date.
    // Negative means that the date is in the past.
    
    // Create a time_t variable and set it to the current date/time
    time_t currentTime;
    time(&currentTime);
    
    // Create a time struct for the time to test against the current time
    // Set it to the current time, and adjust with the parameters.
    struct tm testTime = *localtime(&currentTime);
    testTime.tm_year = year - 1900;
    testTime.tm_mon = month - 1;
    testTime.tm_mday = day;
    
    int seconds = difftime(mktime(&testTime), currentTime);

    return seconds;
}

bool isOneBeforeTwo(struct tm one, struct tm two)
{
    one.tm_sec = 0;
    two.tm_sec = 0;
    
    if (difftime(mktime(&two), mktime(&one)) <= 0)
        return false;
    else
        return true;
}

bool isSameDay(struct tm one, struct tm two)
{
    if (one.tm_mday == two.tm_mday && one.tm_mon == two.tm_mon && one.tm_year == two.tm_year)
        return true;
    else
        return false;
}

std::string getDayOfWeek(struct tm date)
{
    int dayOfWeek = date.tm_wday;
    std::string day = "";
    
    switch (dayOfWeek)
    {
        case 0 : day = "Sunday";
            break;
        case 1 : day = "Monday";
            break;
        case 2 : day = "Tuesday";
            break;
        case 3 : day = "Wednesday";
            break;
        case 4 : day = "Thursday";
            break;
        case 5 : day = "Friday";
            break;
        case 6 : day = "Saturday";
            break;
    }
    
    return day;
}

std::string get24HourTime(struct tm date)
{
    std::string hours, minutes;
    
    std::stringstream ss;
    ss << date.tm_hour;
    hours = ss.str();
    ss.str(std::string());
    ss << date.tm_min;
    minutes = ss.str();
    
    // If minutes is 1 character, add a leading 0
    if (minutes.length() == 1)
        minutes = "0" + minutes;
    
    std::string output = hours + ":" + minutes;
    return output;
}

std::string convertToSentenceCase(std::string str)
{
    // Capitalises the first letter of str
    
    std::string newStr = "";
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (i == 0)
            newStr += toupper(str[i]);
        else
            newStr += str[i];
    }
    
    return newStr;
}
