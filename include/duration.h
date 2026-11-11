#ifndef DURATION_H
#define DURATION_H

#include <ostream>

@brief A class representing a duration of time in minutes and seconds.
@param minutes The number of minutes in the duration.
@param seconds The number of seconds in the duration.
@param total_seconds The total duration in seconds.
@returns The total duration in seconds.
// invariant guarantees: total_seconds is always non-negative.
class Duration {
public:
    Duration(int minutes = 0, int seconds = 0);
    int total_seconds() const;
    Duration operator+(const Duration& other) const;
    bool operator==(const Duration& other) const;

private:
    int m_total_seconds;
};

std::ostream& operator<<(std::ostream& out, const Duration& d);

#endif