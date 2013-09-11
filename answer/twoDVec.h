#ifndef TWODVEC_H
#define TWODVEC_H

#include <precision.h>

namespace storage
{
	class twoDVec
	{
	public:
		typedef std::vector<user_prec> row_t;
		typedef std::vector<row_t> sheet_t;

		twoDVec ( unsigned int width=1, unsigned int height=1, user_prec init_fill=filler) 
		{
			sheet.resize( width, row_t( height, init_fill) );
		}

		twoDVec ( unsigned int width, row_t init_vec ) 
		{
			sheet.resize( width, init_vec );
		}

		twoDVec ( const twoDVec& original )
		{
			sheet = original.sheet;
		}

		//virtual void pack ( row_t ) = 0;

		sheet_t sheet;
	};
}

#endif //TWODVEC_H
