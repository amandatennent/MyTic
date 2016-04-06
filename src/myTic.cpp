#include "myTic.h"
float MyTic::limit = 100;


MyTic::MyTic()
{
    // Default constructor
    credit = 0;
}

MyTic::MyTic(float theCredit, std::string thePrimaryUser)
{
    // Constructor with parameters
    credit = theCredit;
    primaryUser = thePrimaryUser;
}

MyTic::~MyTic()
{
    // Destructor
    // Delete passes vector
    Delete_Pointers(passes.begin(), passes.end());
    passes.clear();
}

void MyTic::input()
{
    // Data input for a MyTic object
}

void MyTic::print()
{
    // Data output for a MyTic object
}

float MyTic::getCredit() const
{
    // Note the use of const -> changes aren't allowed to made to
    // class variables
    
    return credit;
}

float MyTic::getLimit() const
{
    // Returns the MyTic object's limit
    return limit;
}

bool MyTic::doPurchase(TravelPass* newPass)
{
    // This function will check if the purchase of the newPass is able to take
    // place. It will check the balance of the MyTik, and complete the purchase
    // if possible.
    
    // Check if the MyTic has enough balance to pay for the travel pass and
    // enough room in the TravelPass passes vector -> maximum = MAX_TRAVELPASSES
    if (credit >= newPass->getCost())
    {
        if (passes.size() < MAX_TRAVELPASSES)
        {
            // Yes - proceed with purchase
            
            // Add the new pass to the MyTic
            passes.push_back(dynamic_cast<TravelPass*>(newPass));
            
            // Reduce the available credit on MyTic
            credit = credit - newPass->getCost();
            
            // Display the purchase confirmation / information to user
            std::cout << "\nYou purchased ";
            newPass->print();
            std::cout << "Your remaining credit is $" << std::fixed
            << std::setprecision(2) << credit << std::endl;
            
            return true;
        }
        else
        {
            // MyTic has to many travel passes
            std::cout << "Sorry, no more travel passes can be added to this "
            << "MyTic." << std::endl;
            
            return false;
        }
    }
    else
    {
        // No - return to menu (will happen automatically on completion
        // of current function).
        std::cout << "Sorry, you don't have enough credit for that ";
        std::cout << "selection" << std::endl;
        
        return false;
    }
}
void MyTic::chargeMyTic()
{
    std::string strChargeAmount = "";
    int chargeAmount = 0;
    bool correct = true;
    
    // Ask the user how much they want to charge their MyTic
    std::cout << "\nHow much do you want to add: ";
    
    do
    {
        // Get the user's input
        std::getline(std::cin, strChargeAmount);
        
        // Convert the input to int
        chargeAmount = convertToCharge(strChargeAmount);
        
        if (chargeAmount == -1)
        {
            // A number wasn't entered
            correct = false;
            std::cout << "Incorrect input detected. Please try again: ";
        }
        else if (chargeAmount == -2)
        {
            // Number entered was not a multiple of 5
            correct = false;
            std::cout << "Sorry, you can only add multiples of 5. Please try "
                << "again: ";
        }
        else if(credit + chargeAmount > limit)
        {
            // Charge amount will put credit over the allowed limit.
            correct = false;
            std::cout << "Sorry, the max amount of credit allowed is $"
                << std::fixed << std::setprecision(2) << limit << ". Please "
                << "try again: ";
        }
        else if (chargeAmount < 0)
        {
            // Charge amount can't be negative
            correct = false;
            std::cout << "Charge amount can't be a negative number. Please "
                << "try again.";
        }
        else
        {
            // Value entered is valid.
            correct = true;
        }
    } while (correct == false);
    
    // Add the charge amount to the MyTic, and display the current credit.
    credit = credit + chargeAmount;
    setNumberFormatting();
    std::cout << "\nNew credit = $" << credit << std::endl;
}

int MyTic::convertToCharge(std::string str)
{
    // This function will attempt to convert str to an int. Will return -1
    // if the string is not an int. Will return -2 if it is not a multiple
    // of 5.
    
    float fNumber;
    int iNumber;
    
    // Convert the string to a float, and return -1 if conversion fails
    std::stringstream convert(str);
    if (!(convert >> fNumber))
        return -1;
    
    // Check to make sure that the number has no fractional part (ie: 0.5)
    iNumber = fNumber;
    if (iNumber != fNumber)
    {
        // Number contains a fractional part
        return -2;
    }
    
    // Check to make sure that the number is a multiple of 5
    if (iNumber % 5 != 0)
    {
        // Number is not a multiple of 5
        return -2;
    }
    
    return iNumber;
}

std::string MyTic::getPrimaryUser() const
{
    return primaryUser;
}

void MyTic::setPrimaryUser(std::string thePrimaryUser)
{
    primaryUser = thePrimaryUser;
}

std::vector<TravelPass*> MyTic::getPasses()
{
    return passes;
}

void MyTic::reduceBalance(double charge) throw (InsufficientFunds)
{
    if (credit - charge < 0)
        throw InsufficientFunds();
    else
        credit = credit - charge;
}

void MyTic::addTravelPass(TravelPass* pass)
{
    passes.push_back(pass);
}
