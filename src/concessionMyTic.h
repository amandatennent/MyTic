#ifndef __Assignment_2__concessionMyTic__
#define __Assignment_2__concessionMyTic__

#include <stdio.h>
#include "myTic.h"

class ConcessionMyTic : public MyTic
{
public:
    ConcessionMyTic(); // Default Constructor
    ConcessionMyTic(float, std::string);
    virtual ~ConcessionMyTic() = 0; // Destructor
};

#endif /* defined(__Assignment_2__concessionMyTic__) */
