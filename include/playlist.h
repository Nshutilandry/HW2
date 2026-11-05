#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "track.h"
#include "duration.h"

class Playlist {
public:
    explicit Playlist(int capacity);
    ~Playlist();

    bool add_track(const Track& track);
    int size() const;
    Duration total_length() const;
    const Track* find_track(const std::string& title) const;

    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

private:
    Track* m_tracks;
    int m_count;
    int m_capacity;
};

#endif