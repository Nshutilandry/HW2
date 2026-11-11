#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "track.h"
#include "duration.h"

@brief A class representing a playlist of tracks.
@param capacity The maximum number of tracks the playlist can hold.
@param track The track to be added to the playlist.
@ param title The title of the track to be found in the playlist.
@param m_tracks A pointer to the array of tracks in the playlist.
@param m_count The current number of tracks in the playlist.
@param m_capacity The maximum number of tracks the playlist can hold.
@param size The current number of tracks in the playlist.
@param total_length The total length of all tracks in the playlist.
@param find_track A pointer to the track with the specified title, or nullptr if not found.
@param Playlist A pointer to the newly created Playlist object.
@return A pointer to the newly created Playlist object.

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