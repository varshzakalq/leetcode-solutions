class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int vol =abs(((height[i]>height[j])?height[j]:height[i])*(i-j));
        while(i<j){
            if(height[i]>=height[j])j--;
            else if(height[j]>height[i])i++;
            int v =abs(((height[i]>height[j])?height[j]:height[i])*(i-j));
            if(v >vol)vol = v;
        }
        return vol;
        
        
    }
};
