#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <tuple>


typedef std::pair<char, char> pair;
typedef std::tuple<char, char, char> tuple;

int jankenCalculatePart1(pair& currentPair, std::map<char, int>& scoreMap) {
    int score = 0;
    char elfPlays = currentPair.first;
    char wePlay = currentPair.second;

    std::map<char, pair> jankenMap; 
        /*
        Rock Draws Rock Loses to Paper
        Paper Draws Paper Loses to Scissors
        Scissors Draws Scissors Loses to Rock
        */
        jankenMap['A'] = std::make_pair('X','Y');
        jankenMap['B'] = std::make_pair('Y','Z');
        jankenMap['C'] = std::make_pair('Z','X');

    if ( jankenMap[elfPlays].first == wePlay ) {
        // std::cout << "Draw" << std::endl;
        score += 3;
    } else if ( jankenMap[elfPlays].second == wePlay ) {
        // std::cout << "We Win!" << std::endl;
        score += 6;
    } else {
        // std::cout << "We Lose!" << std::endl;
        score += 0;
    }

    score += scoreMap[wePlay];
    return score;
}

int jankenCalculatePart2(pair& currentPair, std::map<char, int>& scoreMap) {
    int score = 0;
    char play;
    char elfPlays = currentPair.first;
    char wePlay = currentPair.second;

    // WIN - DRAW - LOSE
    std::map<char, tuple> jankenMap;
        jankenMap['A'] = std::make_tuple('Y','X','Z');
        jankenMap['B'] = std::make_tuple('Z','Y','X');
        jankenMap['C'] = std::make_tuple('X','Z','Y');

    if (wePlay == 'X') {
        play = std::get<2> (jankenMap[elfPlays]);
        score += 0; // Score for Lose
    } else if (wePlay == 'Y') {
        play = std::get<1> (jankenMap[elfPlays]);
        score += 3; // Score for Draw
    } else if (wePlay == 'Z') {
        play = std::get<0> (jankenMap[elfPlays]);
        score += 6; // Score for Win
    }

    score += scoreMap[play];  
    return score;
}

int main() {
    std::string readJanken;
    pair currentJanken;
    int totalScorePt1 = 0;
    int totalScorePt2 = 0;
    
    std::ifstream jankenFile("input.list");

    std::map<char, int> scoreMap; 
        scoreMap['X'] = 1; // Rock
        scoreMap['Y'] = 2; // Paper
        scoreMap['Z'] = 3; // Scissors

    while(getline(jankenFile, readJanken)) {
        currentJanken = std::make_pair(readJanken.front(), readJanken.back());
        totalScorePt1 += jankenCalculatePart1(currentJanken, scoreMap);
        totalScorePt2 += jankenCalculatePart2(currentJanken, scoreMap);
    }

    std::cout << "Part 1 Score: " + std::to_string(totalScorePt1) << std::endl;
    std::cout << "Part 2 Score: " + std::to_string(totalScorePt2) << std::endl;
}