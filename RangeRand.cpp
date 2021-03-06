#include "RangeRand.h"

using namespace std;

RangeRand::RangeRand( int lb, int ub ) : lowerBound( lb ), upperBound( ub ), range( ub - lb + 1 )
{
    srand( time( NULL ) );
}


RangeRand::~RangeRand()
{
}


int RangeRand::operator() ()
{
    return ((rand() % range) + lowerBound);
}