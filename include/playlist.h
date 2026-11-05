#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "track.h"
#include "duration.h"

class Playlist {
public:
    Playlist();
    ~Playlist();

    void add_track(const std::string& title, const Duration& length);
    int size() const;
    Duration total_length() const;
    Track* find_track(const std::string& title);
    const Track* find_track(const std::string& title) const;

    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

private:
    Track* m_tracks;
    int m_count;
    int m_capacity;
    void resize(int new_capacity);
};

#endif