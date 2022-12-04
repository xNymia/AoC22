#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <tuple>

typedef std::pair<int, int> pair;
typedef std::tuple<pair,pair> tuple;

int main() {

    std::ifstream cleaningList("input.list");
    std::string cleaningArea;

    int ptOneTotal = 0;
    int ptTwoTotal = 0;

    while(getline(cleaningList, cleaningArea)) {

        std::string firstElfInter = cleaningArea.substr(0,cleaningArea.find(','));
        std::string secondElfInter = cleaningArea.substr(cleaningArea.find(',')+1, cleaningArea.length());

        pair firstElf = std::make_pair(std::stoi(firstElfInter.substr(0,firstElfInter.find('-'))),std::stoi(firstElfInter.substr(firstElfInter.find('-')+1,firstElfInter.length())));
        pair secondElf = std::make_pair(std::stoi(secondElfInter.substr(0,secondElfInter.find('-'))),std::stoi(secondElfInter.substr(secondElfInter.find('-')+1,secondElfInter.length())));

        if ((firstElf.first <= secondElf.first) && (firstElf.second >= secondElf.second)) {
            ptOneTotal++;
        } else if ((secondElf.first <= firstElf.first) && (secondElf.second >= firstElf.second)) {
            ptOneTotal++;
        }

        if (firstElf.first <= secondElf.second && secondElf.first <= firstElf.second){
            ptTwoTotal++;
        }
    }
    std::cout << ptOneTotal << std::endl;
    std::cout << ptTwoTotal << std::endl;   
}