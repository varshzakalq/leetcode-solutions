class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() ==0){
            return {-1,-1};
        }
        if(nums.size()==1 && nums[0] == target){

            return{0,0};
        }
        else if(nums.size()==1){
            
            return {-1,-1};
        }
        
        //finding start
        int st= 0;
        int end = nums.size()-1;
        while(st<end){
            int mid = st +(end -st)/2;
            if(nums[mid]>=target){
                end = mid;
            }
            else{
                st = mid+1;
            }
        }
        int num1 = end;

        if(num1<0 ||num1>=nums.size()||nums[num1]!= target){
            return {-1,-1};
        }
        end = nums.size()-1;
        st = 0;
        //finding end;
        while(st<end){
            int mid = st+(end-st+1)/2;
            if(nums[mid]<=target){
                st = mid;
            }
            else{
                end = mid-1;
            }
        }
        int num2 = st;
        return {num1,num2};
    }
};
