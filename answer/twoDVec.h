#ifndef TWODVEC_H
#define TWODVEC_H

#include <precision.h>

namespace storage
{
	class twoDVec
	{
	public:
		typedef std::vector<y_vec> sheet_t;

		twoDVec ( unsigned int length=1, unsigned int height=1, user_prec init_fill=filler) 
		{
			sheet.resize( length, y_vec( length, init_fill) );
		}

		twoDVec ( unsigned int length, y_vec init_vec ) 
		{
			sheet.resize( length, init_vec );
		}

		twoDVec ( const twoDVec& original )
		{
			sheet = original.sheet;
		}

		sheet_t sheet;
	};
}

#endif //TWODVEC_H
