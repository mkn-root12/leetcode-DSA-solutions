class Solution {
public:
    bool findWord(vector<vector<char>>& board, string& word, int i, int j, int pos, int& rows, int& cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return false;
        }
        
        if (pos == word.size() - 1) return true;
        
        char tempChar = board[i][j];
        board[i][j] = '$';
        
        bool found = false;
        if (i + 1 < rows && board[i + 1][j] == word[pos + 1]) {
            found = found || findWord(board, word, i + 1, j, pos + 1, rows, cols);
        }
        if (i - 1 >= 0 && board[i - 1][j] == word[pos + 1]) {
            found = found || findWord(board, word, i - 1, j, pos + 1, rows, cols);
        }
        if (j + 1 < cols && board[i][j + 1] == word[pos + 1]) {
            found = found || findWord(board, word, i, j + 1, pos + 1, rows, cols);
        }
        if (j - 1 >= 0 && board[i][j - 1] == word[pos + 1]) {
            found = found || findWord(board, word, i, j - 1, pos + 1, rows, cols);
        }
        
        board[i][j] = tempChar;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        int pos = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[pos]) {
                    if (word.size() == 1) return true;
                    bool found = findWord(board, word, i, j, pos, rows, cols);
                    if (found) return true;
                }
            }
        }
        return false;
    }
};
