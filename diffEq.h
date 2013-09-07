#ifndef DIFFEQ_H
#define DIFFEQ_H

#include <vector>
#include "precision.h"

namespace problem
{
	typedef std::vector<user_prec> y_vec;

class diffEq
{
public:

    virtual void derivative( y_vec& y, y_vec& y_dot ) { };

    const unsigned int varCount;
    const unsigned int derivePower;

protected:
	
};
}
#endif // DIFFEQ_H
