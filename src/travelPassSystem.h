//
// testPropertyA.h
//
// header file for the driver program
//

#ifndef __TESTTRAVELPASS_H__
#define __TESTTRAVELPASS_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>
#include <cmath>

#include "myTic.h"
#include "adultMyTic.h"
#include "juniorMyTic.h"
#include "seniorMyTic.h"
#include "concessionMyTic.h"
#include "user.h"
#include "station.h"
#include "travelPass.h"
#include "utilities.h"
#include "exceptions.h"
#include "prices.h"
#include "journey.h"
#include "deletePointers.cpp"

class TravelSystem
{
private:
    // Create a vector of MyTic pointer objects
    static std::vector<MyTic*> myTics;

    // Create a map of User pointer objects
    static std::map<std::string, User*> users;

    // Create a map of Station objects
    static std::map<std::string, Station*> stations;

    static std::string stationsFileName;
    static std::string dataFileName;
    static std::string dataOutputFile;

public:
    static void setStationFile(std::string name) { stationsFileName = name; }
    static void setDataFile(std::string name) { dataFileName = name; }
    static void setDataOutputFile(std::string name) { dataOutputFile = name; }
    static void showMenu();
    static void buyJourney();
    static Journey* createJourney(std::string);
    static struct tm getTime(struct tm date);
    static bool checkDay(int day, int month, int year);
    static struct tm getDate();
    static void getStation(Station* &station);
    static std::string calculateZone(Station* start, Station* end);
    static void rechargeMyTic();
    static void showCredit();
    static void printReports();
    static void updatePrices();
    static std::string getDuration();
    static std::string getZone();
    static void showStationStats();
    static void addNewUser();
    static void saveAndQuit();
    static std::string selectUser();
    static MyTic* getMyTic(std::string userID) throw (MyTicNotFound);
    static void readStations() throw (InvalidInputFile);
    static void readMyTicData() throw (InvalidInputFile);
    static void addPricingInfo(std::vector<std::string> &prices) throw
        (InvalidInputFile);
    static void addUsers(std::vector<std::string> &userStrings) throw
        (InvalidInputFile);
    static void createMyTic(double, std::string, std::string) throw
        (InvalidInputFile);
    static void saveData() throw (InvalidOutputFile);
    static std::string getUserInput();
    static double getCredit(std::string) throw (MyTicNotFound);
    static bool isConcession(std::string) throw (UserNotFound);
    static User* getUser(std::string) throw (UserNotFound);
    static double calculateCost(std::string, std::string);
    static bool purchaseTravelPass(Journey*, std::string, MyTic*, User*);
    static bool useOtherPass(Journey*, std::vector<TravelPass*>, struct tm,
        struct tm, MyTic*);
};



#endif
