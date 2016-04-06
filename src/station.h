//
//  Station.h
//  Assignment 2
//
//  Created by Amanda Tennent on 17/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#ifndef __Assignment_2__Station__
#define __Assignment_2__Station__

#include <stdio.h>
#include <string>
#include "utilities.h"

class Station
{
private:
    std::string name;
    int zone;
    int visitsTo, visitsFrom;
public:
    Station();
    Station(std::string, int);
    std::string getName();
    void setName(std::string);
    int getZone();
    void setZone(int);
    int getNoVisitsTo();
    int getNoVisitsFrom();
    void addVisitTo();
    void addVisitFrom();
    friend std::ostream& operator << (std::ostream&, Station*);
};

#endif /* defined(__Assignment_2__Station__) */
