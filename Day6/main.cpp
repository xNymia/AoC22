#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

bool anyDupe(std::vector<char>& window) {
    for (int i=0; i<window.size();i++){
        if (std::count(window.begin(),window.end(),window[i])>1){
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream inputFile("input.list");
    std::string inputLine;

    getline(inputFile, inputLine);
    
    // Part 1
    for (int i=3; i<inputLine.size() ; i++) {
        std::vector<char> window = {inputLine[i-3],inputLine[i-2],inputLine[i-1],inputLine[i]};
        
        if (!anyDupe(window)) {
            std::cout<<i+1<<std::endl;
            break;
        }
    }
    
    // Part 2
    for (int i=13; i<inputLine.size() ; i++) {
        std::vector<char> window2;
        
        for (int y=13;y>0;y--){            
            window2.push_back(inputLine[i-y]);
        }
        window2.push_back(inputLine[i]);

        if (!anyDupe(window2)) {
            std::cout<<i+1<<std::endl;
            break;
        }
    }
}