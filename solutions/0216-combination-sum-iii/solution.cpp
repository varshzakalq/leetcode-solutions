class Solution {
public:
    void help(int i,int n,int k,int curr_sum,vector<int>sub ,vector<vector<int>>&ans ){
        
            if(curr_sum == n){
                if(k ==0){
                ans.push_back(sub);
                }
                return;
            }
            
        
        if(i==10)return;

        //acccept
        curr_sum += i;
        sub.push_back(i);
        help(i+1,n,k-1,curr_sum,sub,ans);
        //reject
        sub.pop_back();
        curr_sum-= i;
        help(i+1,n,k,curr_sum ,sub ,ans);



    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>a;
        help(1,n,k,0,a,ans);
        return ans;
    }
};
