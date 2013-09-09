#ifndef TWODVEC_H
#define TWODVEC_H

#include <vector>

namespace answer
{
	using namespace std;

	typedef vector<bool> boolVec;

	template <class T>
	struct twoDVec
	{
		// Duoas @ cplusplus.com forums
		typedef vector<T> row_t;
		typedef vector<row_t> sheet_t;
		// endcite
		twoDVec ( unsigned int, unsigned int, T ) {
			sheet.resize( width, init_vec );
		}
		twoDVec ( unsigned int, row_t ) {
			sheet.resize( width, init_vec );
		}

		sheet_t sheet;
	}
}

#endif //TWODVEC_H
