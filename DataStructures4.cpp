#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidDistance(double distance) {
    return distance >= 0.0;  // Define your validity criteria here
}

int main() {
    vector<double> sonar_distances = { 0.5, 1.2, 3.4, 2.7, 1.0, 4.5, -1.0 };
    double min_distance_threshold = 0.8;

    sonar_distances.erase(remove_if(sonar_distances.begin(), sonar_distances.end(),
        [](double d) { return !isValidDistance(d); }), sonar_distances.end());

    // Debugging: Check if the vector is empty after filtering
    if (sonar_distances.empty()) {
        cout << "Debug: All distances were invalid." << endl;
    }
    else {
        // Find the minimum distance using min_element
        auto min_distance_it = min_element(sonar_distances.begin(), sonar_distances.end());

        if (min_distance_it != sonar_distances.end()) {
            double min_distance = *min_distance_it;

            if (min_distance >= min_distance_threshold) {
                cout << "Minimum valid distance: " << min_distance << endl;
            }
            else {
                cout << "No valid distance found within the threshold range." << endl;