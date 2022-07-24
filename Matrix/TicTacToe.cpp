// Problem: https://leetcode.com/problems/design-tic-tac-toe/

#include <vector>

using namespace std;

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
class TicTacToe {
public:
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size_ = n;        
        for (int i = 0; i < size_; ++i) {
            board_.push_back({});
            board_.back().resize(size_, 0);            
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board_[row][col] = player;
        int count;
        int r, c;
        /************************************************************************************/
        // 1. Horizontal Check.
        count = 1;
        r = row;
        // 1.1 Horizontal Forward.
        for (c = col + 1; c < size_; c++) {
            if (board_[r][c] == player) ++count;
            else break;            
        }
        // 1.2 Horizontal Backward.
        for (c = col - 1; c >= 0; c--) {
            if (board_[r][c] == player) ++count;            
            else break;            
        }
        if (count >= size_) return player;
        /************************************************************************************/
        // Vertical Check.
        count = 1;
        c = col;
        // Vertical Check Down.
        for (r = row + 1; r < size_; r++) {
            if (board_[r][c] == player) ++count;
            else break;            
        }
        // Vertical Check Up.
        for (r = row - 1; r >= 0; r--) {
            if (board_[r][c] == player) ++count;
            else break;            
        }
        if (count >= size_) return player;
        /************************************************************************************/
        // Diagonal Check.
        // Right Diagonal.
        count = 1;
        // Right Diagonal Down.
        r = row + 1; c = col + 1;
        while (r < size_ && c < size_) {
            if (board_[r][c] == player) ++count;
            else break;
            ++r; ++c;
        }
        // Right Diagonal Up.
        r = row - 1; c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board_[r][c] == player) ++count;
            else break;
            --r; --c;
        }
        if (count >= size_) return player;
        /************************************************************************************/
        // Left Diagonal. 
        count = 1;
        // Left Diagonal Down.
        r = row + 1; c = col - 1;
        while (r < size_ && c >= 0) {
            if (board_[r][c] == player) ++count;
            else break;
            ++r; --c;
        }
        // Left Diagonal Up.
        r = row - 1; c = col + 1;
        while (r >= 0 && c < size_) {
            if (board_[r][c] == player) ++count;
            else break;
            --r; ++c;
        }
        if (count >= size_) return player;
        /************************************************************************************/
        return 0;
    }
    
    private:
    vector<vector<int>> board_;
    int size_;
};