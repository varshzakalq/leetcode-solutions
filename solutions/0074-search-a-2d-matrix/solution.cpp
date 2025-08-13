class Solution {
public:
    bool search(vector <int> m,int cols,int target){
            int st = 0;
            int end = cols -1;
            while(st<= end){
                int mid =  st +(end-st)/2;
                if(m[mid] == target ){
                    return true;
                }
                else if(m[mid]> target){
                    end = mid-1;
                }
                else if(m[mid]< target){
                    st= mid+1;
                }
            }
            return false;
        }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int st = 0;
        int end = rows-1;
        while (st<= end){
            int mid = st +(end-st)/2;
            if (matrix[mid][0]<=target&& matrix[mid][cols-1]>=target){
                return search(matrix[mid],cols,target);
                
            }
            else if (matrix[mid][cols-1]<target){
                st = mid+1;

            }
            else if (matrix[mid][0]>target){
                end = mid -1;

            }


        }
        return false;
        
    }
};
