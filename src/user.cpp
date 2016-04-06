//
//  user.cpp
//  Assignment 2
//
//  Created by Amanda Tennent on 17/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#include "user.h"

User::User()
{
    // Default constructor
}

User::User(std::string newName, std::string newEmail, std::string newType)
    : name(newName), email(newEmail), type(newType)
{
    name = newName;
    email = newEmail;
    type = convertToLower(newType);
}

std::string User::getName()
{
    return name;
}

void User::setName(std::string newName)
{
    name = newName;
}

std::string User::getEmail()
{
    return email;
}

void User::setEmail(std::string newEmail)
{
    email = newEmail;
}

std::string User::getType()
{
    return type;
}

void User::setType(std::string newType)
{
    type = newType;
}

std::ostream& operator << (std::ostream& out, User* user)
{
    std::string output = user->getType() + ":" + user->getName() + ":"
        + user->getEmail();
    out << output;
    return out;
}
