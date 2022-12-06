#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <tuple>
#include <vector>
#include <regex>

const std::regex rgx("^move ([0-9]+) from ([0-9]) to ([0-9])$");

void moveDatCrate(std::map<int,std::vector<char>>& boxStack, std::string line){
    std::smatch matches;
    std::regex_search(line,matches,rgx);

    for (int i=0;i<stoi(matches[1].str());i++){

        boxStack[stoi(matches[3].str())-1].push_back(boxStack[stoi(matches[2].str())-1].back());
        boxStack[stoi(matches[2].str())-1].pop_back();
    }
} 

int main() {
    std::map<int, std::vector<char>> boxStack;
    std::vector<char> stackOne;

    std::vector<int> stackPos = {1,5,9,13,17,21,25,29,33};


    std::ifstream inputFile("input.list");
    std::string inputLine;

    while(getline(inputFile, inputLine)) {

        if (inputLine[0] != '[') {break;};

        for (int i=0 ; i <stackPos.size() ; i++ ) {
            if (inputLine[stackPos[i]] != ' '){
                boxStack[i].push_back(inputLine[stackPos[i]]);
            }    
        }
    }

    for(int n=0; n < boxStack.size(); n++){
        std::reverse(boxStack[n].begin(), boxStack[n].end());
    }

    while(getline(inputFile, inputLine)) {
        
        if (inputLine[0] != 'm') {continue;};
        std::cout << inputLine << std::endl;
        moveDatCrate(boxStack, inputLine);
    }


    for(int n=0; n < boxStack.size(); n++){
        for(int i=0; i < boxStack[n].size(); i++){
            std::cout << boxStack[n].at(i) << ' ';
        }
        std::cout << std::endl;
    }

    std::cin.get();
}