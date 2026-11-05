#include <iostream>
#include "playlist.h"
#include "track.h"
#include "duration.h"

int main() {
    Playlist playlist(4);

    Track tracks[5] = {
        {"Midnight Drive", Duration(3, 42)},
        {"Neon Rain", Duration(4, 5)},
        {"Static", Duration(2, 58)},
        {"Low Tide", Duration(5, 11)},
        {"Overflow", Duration(3, 30)}
    };

    for (int i = 0; i < 5; ++i) {
        bool added = playlist.add_track(tracks[i]);
        if (added) {
            std::cout << "Added: " << tracks[i].title << "\n";
        } else {
            std::cout << "Refused: " << tracks[i].title << "\n";
        }
    }

    std::cout << "Track count: " << playlist.size() << "\n";
    std::cout << "Total length: " << playlist.total_length() << "\n";

    const Track* found = playlist.find_track("Static");
    if (found != nullptr) {
        std::cout << "Found track: " << found->title << " (" << found->length << ")\n";
    } else {
        std::cout << "Track 'Static' not found.\n";
    }

    const Track* missing = playlist.find_track("Nonexistent Song");
    if (missing != nullptr) {
        std::cout << "Found track: " << missing->title << "\n";
    } else {
        std::cout << "Track 'Nonexistent Song' not found.\n";
    }

    return 0;
}