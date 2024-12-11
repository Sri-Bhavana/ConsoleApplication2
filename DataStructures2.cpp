#include <iostream>
#include <vector>

int main() {
    // Simulated distance measurements from the sonar sensor
    std::vector<double> distances = { 0.5, 1.2, 2.3, 3.7, 4.0, 0.8, 5.6, 3.2 };

    // Filter the distances to consider only values within the range (1.0 to 4.5 meters)
    std::vector<double> valid_distances;
    for (const double& distance : distances) {
        if (distance >= 1.0 && distance <= 4.5) {
            valid_distances.push_back(distance);
        }
    }

    // Find the maximum distance within the valid range
    double max_distance = 0.0;
    if (!valid_distances.empty()) {
        auto it = std::max_element(valid_distances.begin(), valid_distances.end());
        max_distance = *it;
    }

    std::cout << "Maximum valid distance: " << max_distance << std::endl;
    return 0;
}