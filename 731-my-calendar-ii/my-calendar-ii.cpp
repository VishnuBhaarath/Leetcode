class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> doubleBookings;

public:
    MyCalendarTwo() {
    }

    bool book(int startTime, int endTime) {

        // Check if this booking creates a triple booking
        for (auto interval : doubleBookings) {
            int start = interval.first;
            int end = interval.second;

            if (startTime < end && start < endTime) {
                return false;
            }
        }

        // Find newly created double bookings
        for (auto interval : bookings) {
            int start = interval.first;
            int end = interval.second;

            if (startTime < end && start < endTime) {
                int overlapStart = max(startTime, start);
                int overlapEnd = min(endTime, end);

                doubleBookings.push_back(
                    {overlapStart, overlapEnd}
                );
            }
        }

        // Add the new booking
        bookings.push_back({startTime, endTime});

        return true;
    }
};