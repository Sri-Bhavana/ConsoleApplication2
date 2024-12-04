#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    // Debugging technique: Use breakpoints and inspect variables
    std::sort(numbers.begin(), numbers.end());

    // Breakpoint here to inspect the sorted vector
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Debugging technique: Print debugging information
    std::vector<int>::iterator it = numbers.begin();
    while (it != numbers.end()) {
        std::cout << "Iterator value: " << *it << ", Iterator address: " << &(*it) << std::endl;
        ++it;
    }

    // Debugging technique: Check for bounds errors
    size_t index = numbers.size();
    try {
        int outOfBoundsValue = numbers[index];
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}