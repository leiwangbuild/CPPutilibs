#include "Timer.h"

using namespace std;

const char Timer::logLevelMsg[3][12] = { "[ERROR] ", "[WARNING] ", "[INFO] " };

Timer::TimeStamp::TimeStamp( std::clock_t t, const std::string &m )
: time( t ), msg( m )
{
}

Timer::TimeStamp::~TimeStamp()
{
}




Timer::Timer() : timestamps( 1, TimeStamp( clock(), string() ) )
{
}


Timer::~Timer()
{
}

void Timer::reset()
{
    timestamps.clear();
    timestamps.push_back( TimeStamp( clock(), string() ) );
}

void Timer::record( LogLevel level, const std::string &msg )
{
    timestamps.push_back( TimeStamp( clock(), (logLevelMsg[level] + msg) ) );
}

void Timer::recordAndPrint( LogLevel level, const std::string &msg, std::ostream &os )
{
    clock_t lastTime = timestamps.back().time;
    record( level, msg );
    os << "\n\t[duration: " << ((timestamps.back().time - lastTime) / 1000.0) << "s]\n";
    os << "\n[time: " << ((timestamps.back().time - timestamps.front().time) / 1000.0) << "s] " << timestamps.back().msg << endl;
}

void Timer::printAll( ostream &os ) const
{
    for (vector<TimeStamp>::const_iterator iter = (timestamps.begin() + 1); iter != timestamps.end(); iter++) {
        os << "\n\t[duration: " << ((iter->time - (iter - 1)->time) / 1000.0) << "s]\n";
        os << "\n[time: " << ((iter->time - timestamps.front().time) / 1000.0) << "s] " << (iter->msg) << endl;
    }
}