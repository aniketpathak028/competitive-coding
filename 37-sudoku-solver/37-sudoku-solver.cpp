class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(board[row][i]==c) return false;
            
            if(board[i][col]==c) return false;
            
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }
        
    bool solution(vector<vector<char>>& board){
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9'; c++){
                        if(isSafe(board, i, j, c)){
                            board[i][j]=c;
                            if(solution(board)) return true;
                            board[i][j]= '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solution(board);
    }
};