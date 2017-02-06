class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int d[][2] = {{-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int r = i + d[k][0];
                    int c = j + d[k][1];
                    if (r < 0 || r > board.size() - 1 || c < 0 || c > board[i].size() - 1) {
                        continue;
                    }
                    live += board[r][c] & 1;
                }
                
                if (board[i][j] & 1) {
                    if (live != 2 && live != 3) {
                        board[i][j] = 1;
                    }
                    else {
                        board[i][j] = 3;
                    }
                }
                else {
                    if (live != 3) {
                        board[i][j] = 0;
                    }
                    else {
                        board[i][j] = 2;    
                    }
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
};

// int can store more information than 0/1 bit
