# Class Design Sketch

## Duration
- **Private Data Members:**
  - `int m_total_seconds`: Stores the accumulated time in seconds.
- **Invariants:**
  - The stored total seconds is never negative (always $\ge 0$).
- **Public Functions:**
  - `Duration(int minutes = 0, int seconds = 0)`: Constructs a duration, normalizing minutes/seconds into total seconds and clamping negative values to zero.
  - `int total_seconds() const`: Returns the total duration in seconds.
  - `Duration operator+(const Duration& other) const`: Returns a new Duration summing this object and another without modifying operands.
  - `bool operator==(const Duration& other) const`: Returns true if both durations share identical total seconds.
  - `std::ostream& operator<<(std::ostream& out, const Duration& d)`: Free function formatting duration as `m:ss` (with zero-padded seconds).

## Playlist
- **Private Data Members:**
  - `Track* m_tracks`: Pointer to dynamically allocated array of tracks.
  - `int m_count`: Current number of active tracks stored.
  - `int m_capacity`: Maximum capacity of the track array.
- **Invariants:**
  - $0 \le \text{m\_count} \le \text{m\_capacity}$.
  - $\text{m\_capacity} \ge 1$.
  - `m_tracks` points to a valid dynamically allocated array of `m_capacity` tracks.
  - No stored track has an empty title.
- **Public Functions:**
  - `explicit Playlist(int capacity)`: Allocates dynamic array of size `m_capacity` (clamping values below 1 to 1) and sets count to 0.
  - `~Playlist()`: Releases dynamic memory using `delete[]`.
  - `bool add_track(const Track& track)`: Appends track if space permits and title is valid; returns true or false.
  - `int size() const`: Returns current track count.
  - `Duration total_length() const`: Sums track lengths via `operator+`.
  - `const Track* find_track(const std::string& title) const`: Finds first matching track or returns `nullptr`.
