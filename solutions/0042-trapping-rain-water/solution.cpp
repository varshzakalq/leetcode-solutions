class Solution {
public:
    int findnext(int &tosub, vector<int>&height,int i){
        int j = i+2;
        int max= i+1;
        if(height [max]>= height[i])return max;
        while(j<height.size()){
            if(height[max] >= height[i])break;
            if(height[max]<height[j]){
                max =j;
            }
            j++;
        }
        int k = i+1;
        while(k<max){
            tosub += height[k];
            k++;
        }
        return max;
    }
    int trap(vector<int>& height) {
        if(height.empty())return 0;
        int left = 0; int right = height.size()-1;
        int left_max = 0; int right_max = 0;
        int vol =0;
        while(left <right){
            if(height[left]<height[right]){
                if(left_max <=height[left]){
                    left_max = height[left];
                }
                else{
                    vol += left_max-height[left];
                }
                left++;
            }
            else{
                if(right_max <=height[right])right_max = height[right];
                else{
                    vol+=  right_max -height[right];
                }
                right--;
            }
        }
        return vol;
    }
};
