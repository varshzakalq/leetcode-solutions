class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>n1 = nums;
        sort(n1.begin(),n1.end());
        int i =0; 
        int j = n1.size()-1;
        array <int,2> ans;
        
        while(i<j){
            if(n1[i]+n1[j]<target){
                i++;
               
            }
            else if(n1[i]+n1[j]>target){
                j--;
               
            }
            else if(n1[i]+n1[j]==target){
                ans =  {n1[i],n1[j]};
                break;
            }
        }

        vector <int>result(2,0);
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == ans[0] && result[0] ==0){
                result[0] = i;
                
            }
            if(nums[i] == ans[1] && i != result[0]){
                result[1] = i;
               
                }
        }
        
        return result;
    }
};
