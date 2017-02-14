// classical backtracking 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (exist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool exist(vector<vector<char>>& board, const string &word, int i, int j, int p) {
        if (p == word.size())  return true;
        if (i < 0 || j <0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[p]) return false;
        char t = board[i][j];
        board[i][j] = '\0'; // 防止原路回溯
        bool ret = exist(board, word, i - 1, j, p + 1) ||
            exist(board, word, i, j - 1, p + 1) ||
            exist(board, word, i, j + 1, p + 1) ||
            exist(board, word, i + 1, j, p + 1);
        board[i][j] = t;
        return ret;
    }
};
