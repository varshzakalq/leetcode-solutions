class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            map <int,bool> m;
            for(int j =0; j<board.size();j++){
                if(board[i][j] == '.')continue;
                if(m[int((board[i][j])-'0')] ==true)return false;
                else{
                    m[int((board[i][j])-'0')] =true;

                }
            }
        }
        for(int i = 0;i<board.size();i++){
            map <int,bool> m;
            for(int j =0; j<board.size();j++){
                if(board[j][i] == '.')continue;
                if(m[int((board[j][i])-'0')] ==true)return false;
                else{
                    m[int((board[j][i])-'0')] =true;

                }
            }
        }
        for(int c =0;c<=6;c +=3){
            for(int c2 =0; c2<=6;c2+=3){
                map <int,bool> m;
                for(int i =0+c;i<3+c;i++){
                    
                    for(int j = 0+c2; j<3+c2;j++){
                        if(board[i][j] =='.')continue;
                        if(m[int((board[i][j])-'0')] ==true)return false;
                        else{
                            m[int((board[i][j])-'0')] =true;

                        }
                    
                }
            }

            }
        }
        return true;
           
    }
};
