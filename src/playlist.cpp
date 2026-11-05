#include "playlist.h"

Playlist::Playlist() : m_count(0), m_capacity(4) {
    m_tracks = new Track[m_capacity];
}

Playlist::~Playlist() {
    delete[] m_tracks;
}

void Playlist::resize(int new_capacity) {
    if (new_capacity < m_count) return;
    Track* new_tracks = new Track[new_capacity];
    for (int i = 0; i < m_count; ++i) {
        new_tracks[i] = m_tracks[i];
    }
    delete[] m_tracks;
    m_tracks = new_tracks;
    m_capacity = new_capacity;
}

void Playlist::add_track(const std::string& title, const Duration& length) {
    if (title.empty()) {
        return; // Invariant: No stored track has an empty title
    }
    if (m_count >= m_capacity) {
        resize(m_capacity * 2);
    }
    m_tracks[m_count++] = Track{title, length};
}

int Playlist::size() const {
    return m_count;
}

Duration Playlist::total_length() const {
    Duration total(0, 0);
    for (int i = 0; i < m_count; ++i) {
        total = total + m_tracks[i].length;
    }
    return total;
}

Track* Playlist::find_track(const std::string& title) {
    for (int i = 0; i < m_count; ++i) {
        if (m_tracks[i].title == title) {
            return &m_tracks[i];
        }
    }
    return nullptr;
}

const Track* Playlist::find_track(const std::string& title) const {
    for (int i = 0; i < m_count; ++i) {
        if (m_tracks[i].title == title) {
            return &m_tracks[i];
        }
    }
    return nullptr;
}