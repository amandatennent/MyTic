//
//  Utilities.h
//  Week06_Tute01
//
//  Created by Amanda Tennent on 2/11/2014.
//  Copyright (c) 2014 Amanda Tennent. All rights reserved.
//

#ifndef __Week06_Tute01__Utilities__
#define __Week06_Tute01__Utilities__

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>

int getInt();
bool isInt(std::string);
int convertToInt(std::string);
void cpp_strtok(std::vector<std::string>&, std::string, char);
std::string convertToUpper(std::string);
std::string convertToLower(std::string);
bool isDouble(std::string);
double convertToDouble(std::string);
void setNumberFormatting();
void clearInputBuffer();
void ignore_line (std::istream& in);
int dateDiff(int day, int month, int year);
bool isOneBeforeTwo(struct tm one, struct tm two);
bool isSameDay(struct tm one, struct tm two);
std::string getDayOfWeek(struct tm date);
std::string get24HourTime(struct tm date);
std::string convertToSentenceCase(std::string str);

#endif /* defined(__Week06_Tute01__Utilities__) */
