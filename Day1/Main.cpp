#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::vector<int> calorieArray;
    std::string currentCalorie;
    int weightWatcher = 0;

    std::ifstream calorieFile("calories.list");

    while(getline(calorieFile, currentCalorie)) {
        if (!currentCalorie.empty()) {
            weightWatcher += stoi(currentCalorie);
        } else {
            calorieArray.push_back(weightWatcher);
            weightWatcher = 0;    
        }
    }
    std::sort(calorieArray.begin(), calorieArray.end());
    
    // Part 1
    std::cout << calorieArray.back() << std::endl;
    // Part 2
    int topThreeTotal = 0;
    // Null terminated structure tableflip.gif
    for (int i = (calorieArray.size()-1) ; i > (calorieArray.size()-4) ; i--) {
        topThreeTotal += calorieArray.at(i);
    }
    std::cout << std::to_string(topThreeTotal) << std::endl;
}