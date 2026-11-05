#ifndef DURATION_H
#define DURATION_H

#include <ostream>

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