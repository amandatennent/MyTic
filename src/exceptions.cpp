#include "exceptions.h"

InvalidInputFile::InvalidInputFile() { }
InvalidInputFile::InvalidInputFile(std::string message) : errorMessage(message)
{ }
std::string InvalidInputFile::getErrorMessage() { return errorMessage; }
InvalidOutputFile::InvalidOutputFile() { }
InvalidOutputFile::InvalidOutputFile(std::string){ }
std::string InvalidOutputFile::getErrorMessage() { return errorMessage; }
PriceError::PriceError() { }
MyTicNotFound::MyTicNotFound() { }
InvalidInput::InvalidInput(){ }
InsufficientFunds::InsufficientFunds() { }
UserNotFound::UserNotFound() { }
