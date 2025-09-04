class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row , int col,int j){
        for(int i =0; i<9; i++){
            if(board[row][i] == '0' +j){
                return false;
            }
            
        }
        for(int i= 0; i<9; i++){
        if(board[i][col] == '0' +j){
                return false;
            }}
        int sr = (row/3)*3;
        int sc = (col /3)*3;
        for(int i = sr; i<= sr+2;i++){
            for(int k = sc ; k<=sc+2; k++){
                if(board[i][k] == '0' +j){
                    return false;
                }
            }
        }
        return true;
        
    }
   
    bool helper(int row , int col , vector<vector<char>>& board){
       
        if(col == 9){
            return helper(row+1,0, board );
        }
        
        if(row == 9){
            return true ;
        }
        if(board [row][col] != '.'){
            return helper(row,col+1, board );
        }
        for(int i =1 ; i<=9;i++){
            if(issafe(board, row , col , i)){
                board[row][col] = '0' +i;
                if(helper(row,col+1, board ))
                   {
                     return true;
                     }
                board[row][col] = '.';
            }
        
        
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row =0;
        int col =0;
        helper(row, col , board);

    }

};
