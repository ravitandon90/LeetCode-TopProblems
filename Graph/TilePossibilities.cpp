// Problem: https://leetcode.com/problems/letter-tile-possibilities/

#include <string>
#include <unordered_set>

using namespace std;

class TilePossibilities {
public:
    int numTilePossibilities(const string& tiles) {
        unordered_set<string> combinations;
        combinations.insert("");
        string tile;
        generateNext(tiles, 0, combinations);
        return combinations.size() - 1;
    }

    void generateNext(
        const string& tiles, int index, unordered_set<string>& combinations) {
        if (index == tiles.size()) return;
        generateNext(tiles, index + 1, combinations);
        char ch = tiles[index];
        unordered_set<string>::iterator it;
        unordered_set<string> tmp = combinations;
        for (it = combinations.begin(); it != combinations.end(); ++it) stringCombinations(*it, ch, tmp);
        combinations = tmp;
    }

    void stringCombinations(const string& st, char ch, unordered_set<string>& combinations) {
        for (int i = 0; i <= st.size(); ++i) {
            string new_st = st;
            new_st.insert(new_st.begin() + i, ch);
            combinations.insert(new_st);
        }
    }
};