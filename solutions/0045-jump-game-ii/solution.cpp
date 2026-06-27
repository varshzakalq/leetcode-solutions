class Solution {
public:
    
    int jump(vector<int>& nums) {
    int farthest =0; 
    int jump = 0; 
    int current_end =0;
    for(int i =0; i<nums.size()-1;i++){
        farthest = max(farthest, i+nums[i]);
        if(i == current_end){
            jump++;
            current_end  = farthest;
        }
    
    }
    return jump;
    }

};
