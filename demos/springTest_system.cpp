#include "springTest_system.hpp"

namespace problem
{
    void springTest_system::derivative ( const storage::y_vec& y, storage::y_vec& y_dot, const storage::user_prec& t )
    {
        y_dot[0] = y[1];
        y_dot[1] = -(k*y[0])/m;
    }
}
