#ifndef STORAGE_H
#define STORAGE_H
#include <vector>
//#include "fUNroll.h"

namespace storage
{
	class dataArray
	{
	public:
		dataArray( long unsigned int _limit, std::vector<bool> _orders )
		{
			limit = _limit;
			iterator = 0;
			orders = _orders;
			
		}
		~dataArray()
		{
			delete orders;
			delete storage;
		}
		
		void clear()
		{
			iterator = 0;
		}

		virtual void pack( std::vector<system::precDef> y )
		{
		}

	private:
		std::vector<bool> orders;
        //storage vector of vectors
		long unsigned int limit;
		long unsigned int iterator;
	};
}
#endif // STORAGE_H
