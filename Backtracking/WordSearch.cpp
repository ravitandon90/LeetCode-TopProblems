#include<iostream>

using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.at(0).size(); ++j) {
                bool used[6][6];
                memset(used, false, sizeof(used));
                int word_index = 0;
                if (dfs(board, i, j, used, word, word_index)) return true;
            }
        }
        return false;        
    }
    
private:
    bool dfs(const vector<vector<char>>& board, int r, int c, bool used[][6], const string& word, int& word_i) {
        const int max_r = board.size();
        const int max_c = board.at(0).size();
        if (r < 0 || c < 0 || r >= max_r || c >= max_c) return false;
        if (used[r][c]) return false;
        if (board[r][c] != word.at(word_i)) return false;
        
        used[r][c] = true;
        ++word_i;
        if (word_i == word.size()) return true;        
        
        // Check up
        if (dfs(board, r - 1, c, used, word, word_i)) return true;
        // Check down
        if (dfs(board, r + 1, c, used, word, word_i)) return true;        
        // Check left
        if (dfs(board, r, c - 1, used, word, word_i)) return true;
        // Check right
        if (dfs(board, r, c + 1, used, word, word_i)) return true;
        
        // Backtracking.
        used[r][c] = false;
        --word_i;
        
        // No valid path found
        return false;
    }
};