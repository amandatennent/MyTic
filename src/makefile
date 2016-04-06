FLAGS=-Wall -pedantic -c

all: TravelPass

TravelPass: travelPassSystem.o journey.o user.o prices.o station.o exceptions.o myTic.o travelPass.o utilities.o adultMyTic.o concessionMyTic.o seniorMyTic.o juniorMyTic.o deletePointers.o
	g++ travelPassSystem.o journey.o user.o prices.o station.o exceptions.o myTic.o travelPass.o utilities.o adultMyTic.o concessionMyTic.o seniorMyTic.o juniorMyTic.o deletePointers.o -o TravelPass

testTravelPass.o : travelPassSystem.h travelPassSystem.h
	g++ $(FLAGS) travelPassSystem.cpp

user.o : user.cpp user.h
	g++ $(FLAGS) user.cpp

journey.o : journey.cpp journey.h
	g++ $(FLAGS) journey.cpp

prices.o : prices.cpp prices.h
	g++ $(FLAGS) prices.cpp

station.o : station.cpp station.h
	g++ $(FLAGS) station.cpp

exceptions.o : exceptions.cpp exceptions.h
	g++ $(FLAGS) exceptions.cpp

myTic.o : myTic.cpp myTic.h
	g++ $(FLAGS) myTic.cpp

travelPass.o : travelPass.cpp travelPass.h
	g++ $(FLAGS) travelPass.cpp

utilities.o : utilities.cpp utilities.h
	g++ $(FLAGS) utilities.cpp

adultMyTic.o : adultMyTic.cpp adultMyTic.h
	g++ $(FLAGS) adultMyTic.cpp

concessionMyTic.o : concessionMyTic.cpp concessionMyTic.h
	g++ $(FLAGS) concessionMyTic.cpp

seniorMyTic.o : seniorMyTic.cpp seniorMyTic.h
	g++ $(FLAGS) seniorMyTic.cpp

juniorMyTic.o : juniorMyTic.cpp juniorMyTic.h
	g++ $(FLAGS) juniorMyTic.cpp

deletePointers.o : deletePointers.cpp
	g++ $(FLAGS) deletePointers.cpp