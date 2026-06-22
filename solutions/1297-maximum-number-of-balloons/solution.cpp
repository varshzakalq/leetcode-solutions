class Solution {
public:
    int maxNumberOfBalloons(string text) {
        array <int,26>m1;
        string req = "balloon";
        for(auto i: text){
            m1[i-'a']++;
        }
        int j = text.size();
        int count =0;
        while(j>0){
            for(auto i :req){
            if(m1[i-'a'] ==0)return count;
            else{
                m1[i-'a']--;
                j--;
            }
        }
        count++;
        }
        return count;
        


    }
};
