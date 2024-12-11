#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> sonar_distances = { 0.5, 1.2, 3.4, 2.7, 1.0, 4.5, -1.0 }; // Simulated sensor readings (including an invalid reading)
    double min_distance_threshold = 0.8;

    auto min_distance_it = min_element(sonar_distances.begin(), sonar_distances.end());

    if (min_distance_it != sonar_distances.end()) {
        double min_distance = *min_distance_it;

        if (min_distance >= min_distance_threshold) {
            cout << "Minimum valid distance: " << min_distance << endl;
        }
        else {
            cout << "No valid distance found within the threshold range." << endl;
        }
    }
    else {
        cout << "No distances found." << endl;
    }
    return 0;
}