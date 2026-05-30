class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        vector <int>prev;
        vector <int> curr(n+1,0);
        
        for(int i =0; i<=word1.size();i++){
            prev.push_back(i);
        }
        for(int i =1; i<=word2.size();i++){
            curr[0] =i;
            for(int j=1;j<=n;j++){
                if(word1[j-1] == word2[i-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1+min(min(curr[j-1],prev[j]),prev[j-1]);
                }
            }
            prev = curr;
           
        }
        return prev[n];
    }
};
