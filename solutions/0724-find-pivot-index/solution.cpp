class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*
        int i =0;
        int j = nums.size()-1;
        int ls =0;
        int rs = 0;
        while(i<j){
            if(ls>rs){  
                rs += nums[j];
                j--;
            }
            else if(ls <rs){
                ls += nums[i];
                 i++;
            }
            else{
                ls += nums[i];
                rs += nums[j];
                j--;
                i++;
            }
        }
        if(ls == rs) return j;
        else return -1;
    }*/
    int s = 0;
    for(int i =0; i<nums.size();i++){
        s+= nums[i];
    }
    int i =0;
    int ls = 0;
    while(i<nums.size()){
        if(ls == s-ls-nums[i]) return i;
        else{
            ls += nums[i];
            i++;
        }
    
    }
    return -1;
    }
};
