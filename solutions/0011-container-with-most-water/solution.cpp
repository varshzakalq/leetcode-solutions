class Solution {
public:
    int maxArea(vector<int>& height) {
    int i = 0;
    
    int j = height.size()-1;
    int mv=0;
    while (i<=j)
    {
        int cv = min(height[i],height[j])*(j-i);
          
        mv = max(cv,mv);
        if(height[i]>=height[j]){
            j--;
        }
        else if (height[j]>height[i]){
            i++;
        }
       
    }
    return mv;    
    }
    
};
