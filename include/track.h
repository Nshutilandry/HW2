#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "duration.h"

struct Track {
    std::string title;
    Duration length;
};

#endif