#ifndef __Queue__Exceptions__
#define __Queue__Exceptions__

#include <stdio.h>
#include <string>

class InvalidInputFile
{
private:
    std::string errorMessage;
public:
    InvalidInputFile();
    InvalidInputFile(std::string);
    std::string getErrorMessage();
};

class InvalidOutputFile
{
private:
    std::string errorMessage;
public:
    InvalidOutputFile();
    InvalidOutputFile(std::string);
    std::string getErrorMessage();
};

class PriceError
{
public:
    PriceError();
};

class MyTicNotFound
{
public:
    MyTicNotFound();
};

class InvalidInput
{
public:
    InvalidInput();
};

class InsufficientFunds
{
public:
    InsufficientFunds();
};

class UserNotFound
{
public:
    UserNotFound();
};

#endif /* defined(__Queue__Exceptions__) */
