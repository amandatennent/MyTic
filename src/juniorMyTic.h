//
//  juniorMyTic.h
//  Assignment 2
//
//  Created by Amanda Tennent on 19/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#ifndef __Assignment_2__juniorMyTic__
#define __Assignment_2__juniorMyTic__

#include <stdio.h>
#include "concessionMyTic.h"

class JuniorMyTic : public ConcessionMyTic
{
public:
    JuniorMyTic();
    JuniorMyTic(float, std::string);
    ~JuniorMyTic();
};

#endif /* defined(__Assignment_2__juniorMyTic__) */
