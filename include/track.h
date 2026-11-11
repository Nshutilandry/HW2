#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "duration.h"

@brief A struct representing a track with a title and length.
@param title The title of the track.
@param length The length of the track in seconds.
@param duration The duration of the track in seconds.
@returns A Track struct with the specified title and length.

struct Track {
    std::string title;
    Duration length;
};

#endif