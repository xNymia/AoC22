#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <tuple>

typedef std::pair<int, int> pair;

int parseBackpackPt1(std::string& readBackpack, std::map<char, pair> charMap){

    std::string firstHalf = readBackpack.substr(0, (readBackpack.length()/2));
    std::string secondHalf = readBackpack.substr((readBackpack.length()/2), readBackpack.length());

    for (int i = 0; i <= firstHalf.length();i++){
        char letter = firstHalf[i];
        if (charMap[letter].second != 1){
            charMap[letter].second++;
        }
    }

    for (int i = 0; i <= secondHalf.length();i++){
        char letter = secondHalf[i];
        if (charMap[letter].second == (0|1)){
            charMap[letter].second++;
        }
    }
    // Null Char terminated strings
    charMap.erase('\x00');

    int score = 0;

    for (auto const& iter : charMap) {

        if (iter.second.second == 2){
            score+=iter.second.first;
        }
    }
    return score;
}

int parseBackpackPt2(std::tuple<std::string,std::string,std::string>& currentGroup, std::map<char, pair> charMap){

    std::string first = std::get<0>(currentGroup);
    std::string second = std::get<1>(currentGroup);
    std::string third = std::get<2>(currentGroup);

    for (int i = 0; i <= first.length();i++){
        char letter = first[i];
        if (charMap[letter].second == 0){
            charMap[letter].second++;
        }
    }
    for (int i = 0; i <= second.length();i++){
        char letter = second[i];
        if (charMap[letter].second == 1){
            charMap[letter].second++;
        }
    }
    for (int i = 0; i <= third.length();i++){
        char letter = third[i];
        if (charMap[letter].second == 2){
            charMap[letter].second++;
        }
    }

    // Null Char terminated strings
    charMap.erase('\x00');

    int score = 0;

    for (auto const& iter : charMap) {
        if (iter.second.second == 3){
           score+=iter.second.first;
        }
    }
    return score;
}

int main () {

    std::map<char, pair> charMap;
        charMap['a'] = std::make_pair( 1, 0 );
        charMap['b'] = std::make_pair( 2, 0 );
        charMap['c'] = std::make_pair( 3, 0 );
        charMap['d'] = std::make_pair( 4, 0 );
        charMap['e'] = std::make_pair( 5, 0 );
        charMap['f'] = std::make_pair( 6, 0 );
        charMap['g'] = std::make_pair( 7, 0 );
        charMap['h'] = std::make_pair( 8, 0 );
        charMap['i'] = std::make_pair( 9, 0 );
        charMap['j'] = std::make_pair( 10, 0 );
        charMap['k'] = std::make_pair( 11, 0 );
        charMap['l'] = std::make_pair( 12, 0 );
        charMap['m'] = std::make_pair( 13, 0 );
        charMap['n'] = std::make_pair( 14, 0 );
        charMap['o'] = std::make_pair( 15, 0 );
        charMap['p'] = std::make_pair( 16, 0 );
        charMap['q'] = std::make_pair( 17, 0 );
        charMap['r'] = std::make_pair( 18, 0 );
        charMap['s'] = std::make_pair( 19, 0 );
        charMap['t'] = std::make_pair( 20, 0 );
        charMap['u'] = std::make_pair( 21, 0 );
        charMap['v'] = std::make_pair( 22, 0 );
        charMap['w'] = std::make_pair( 23, 0 );
        charMap['x'] = std::make_pair( 24, 0 );
        charMap['y'] = std::make_pair( 25, 0 );
        charMap['z'] = std::make_pair( 26, 0 );
        charMap['A'] = std::make_pair( 27, 0 );
        charMap['B'] = std::make_pair( 28, 0 );
        charMap['C'] = std::make_pair( 29, 0 );
        charMap['D'] = std::make_pair( 30, 0 );
        charMap['E'] = std::make_pair( 31, 0 );
        charMap['F'] = std::make_pair( 32, 0 );
        charMap['G'] = std::make_pair( 33, 0 );
        charMap['H'] = std::make_pair( 34, 0 );
        charMap['I'] = std::make_pair( 35, 0 );
        charMap['J'] = std::make_pair( 36, 0 );
        charMap['K'] = std::make_pair( 37, 0 );
        charMap['L'] = std::make_pair( 38, 0 );
        charMap['M'] = std::make_pair( 39, 0 );
        charMap['N'] = std::make_pair( 40, 0 );
        charMap['O'] = std::make_pair( 41, 0 );
        charMap['P'] = std::make_pair( 42, 0 );
        charMap['Q'] = std::make_pair( 43, 0 );
        charMap['R'] = std::make_pair( 44, 0 );
        charMap['S'] = std::make_pair( 45, 0 );
        charMap['T'] = std::make_pair( 46, 0 );
        charMap['U'] = std::make_pair( 47, 0 );
        charMap['V'] = std::make_pair( 48, 0 );
        charMap['W'] = std::make_pair( 49, 0 );
        charMap['X'] = std::make_pair( 50, 0 );
        charMap['Y'] = std::make_pair( 51, 0 );
        charMap['Z'] = std::make_pair( 52, 0 );


    std::ifstream backpackList("input.list");
    std::string readBackpack;
    int score1 = 0;
    int score2 = 0;
    std::tuple<std::string,std::string,std::string> currentGroup = std::make_tuple("","","");
    int currGroupSize = 0;

    while(getline(backpackList, readBackpack)) {
        score1 += parseBackpackPt1(readBackpack, charMap);

        switch (currGroupSize)
        {
        case 0:
            std::get<0>(currentGroup) = readBackpack;
            currGroupSize++;
            break;
        case 1:
            std::get<1>(currentGroup) = readBackpack;
            currGroupSize++;
            break;
        case 2:
            std::get<2>(currentGroup) = readBackpack;
            score2 += parseBackpackPt2(currentGroup, charMap);
            currGroupSize = 0;
            break;
        default:
            break;
        }
    }
    
    std::cout << score1 << std::endl;
    std::cout << score2 << std::endl;

}