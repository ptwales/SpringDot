#ifndef PRECISION_H
#define	PRECISION_H

#include <vector>

namespace storage
{
	typedef double user_prec;
	typedef std::vector<user_prec> y_vec;	//If vectors don't apply this should somehow change to not a vector
	const static user_prec filler = 0;  // value used to initialize vectors and sheets
}

#endif //PRECISION_H
