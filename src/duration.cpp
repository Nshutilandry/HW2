#include "duration.h"
#include <iomanip>

Duration::Duration(int minutes, int seconds) {
    int total = (minutes * 60) + seconds;
    if (total < 0) {
        m_total_seconds = 0;
    } else {
        m_total_seconds = total;
    }
}

int Duration::total_seconds() const {
    return m_total_seconds;
}

Duration Duration::operator+(const Duration& other) const {
    return Duration(0, m_total_seconds + other.m_total_seconds);
}

bool Duration::operator==(const Duration& other) const {
    return m_total_seconds == other.m_total_seconds;
}

std::ostream& operator<<(std::ostream& out, const Duration& d) {
    int total = d.total_seconds();
    int minutes = total / 60;
    int seconds = total % 60;
    out << minutes << ':' << std::setfill('0') << std::setw(2) << seconds;
    return out;
}