class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        cout<<n+m;
            vector <int>ans(n+m,0);
        int j=0;
        int k =0;
        while (i<m&& j <n){
            
            if(nums1[i]<=nums2[j]){
                ans[k++] = nums1[i++];
            }
            else
                ans[k++] = nums2[j++];
        }
        while(j<n){
            ans[k++] = nums2[j++];
        }
        while(i<m){
             ans[k++] = nums1[i++];
        }
           
       
        nums1.resize(n+m);
        nums1 = ans;
        

    }       
};