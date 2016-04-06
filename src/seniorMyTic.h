//
//  seniorMyTic.h
//  Assignment 2
//
//  Created by Amanda Tennent on 19/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#ifndef __Assignment_2__seniorMyTic__
#define __Assignment_2__seniorMyTic__

#include <stdio.h>
#include "concessionMyTic.h"

class SeniorMyTic : public ConcessionMyTic
{
public:
    SeniorMyTic();
    SeniorMyTic(float, std::string);
    ~SeniorMyTic();
};

#endif /* defined(__Assignment_2__seniorMyTic__) */
