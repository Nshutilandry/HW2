#ifndef DURATION_H
#define DURATION_H

#include <ostream>
@brief A class representing a duration of time in minutes and seconds.
@param minutes The number of minutes in the duration.
@returns The total duration in seconds.
class Duration {
public:
@param other Another Duration object to add to this one.
@returns A new Duration object representing the sum of the two durations.
    Duration(int minutes = 0, int seconds = 0);
    int total_seconds() const;
    Duration operator+(const Duration& other) const;
    bool operator==(const Duration& other) const;

private:
    int m_total_seconds;
};

std::ostream& operator<<(std::ostream& out, const Duration& d);

#endif