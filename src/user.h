//
//  user.h
//  Assignment 2
//
//  Created by Amanda Tennent on 17/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#ifndef __Assignment_2__user__
#define __Assignment_2__user__

#include <stdio.h>
#include <string>
#include "utilities.h"

class User
{
private:
    std::string name, email, type;
public:
    User();
    User(std::string, std::string, std::string);
    std::string getName();
    void setName(std::string);
    std::string getEmail();
    void setEmail(std::string);
    std::string getType();
    void setType(std::string);
    friend std::ostream& operator << (std::ostream&, User*);
};

#endif /* defined(__Assignment_2__user__) */
