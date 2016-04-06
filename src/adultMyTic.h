//
//  adultMyTic.h
//  Assignment 2
//
//  Created by Amanda Tennent on 19/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#ifndef __Assignment_2__adultMyTic__
#define __Assignment_2__adultMyTic__

#include <stdio.h>
#include "myTic.h"

class AdultMyTic : public MyTic
{
public:
    AdultMyTic(); // Default Constructor
    AdultMyTic(float, std::string);
    ~AdultMyTic(); // Destructor
};

#endif /* defined(__Assignment_2__adultMyTic__) */
