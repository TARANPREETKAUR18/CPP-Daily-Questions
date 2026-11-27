class Solution {
public:
    bool isSafe(int row, int columns, int n, const vector<bool> &column, const vector<bool> &upperDiagonal, const vector<bool> &lowerDiagonal){
        if(column[columns]) return false;
        if(upperDiagonal[row - columns + n - 1]) return false;
        if(lowerDiagonal[row + columns]) return false;
        return true;
    }

    void nQueens(int row, int n, vector<string> &board, vector<vector<string>> &ans, vector<bool> &column, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(row, j, n, column, upperDiagonal, lowerDiagonal)){
                board[row][j] = 'Q';
                column[j] = upperDiagonal[row - j + n - 1] = lowerDiagonal[row + j] = true;
                nQueens(row + 1, n, board, ans, column, upperDiagonal, lowerDiagonal);
                board[row][j] = '.'; //Backtracking
                column[j] = upperDiagonal[row - j + n - 1] = lowerDiagonal[row + j] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<bool> column(n, false);
        vector<bool> upperDiagonal(2 * n - 1, false);
        vector<bool> lowerDiagonal(2 * n - 1, false);

        nQueens(0, n, board, ans, column, upperDiagonal, lowerDiagonal);
        return ans;
    }
};