class Solution {
public:
    bool issame(int f1[] , int f2[]){
        for(int i =0 ; i<26; i++){
            if (f1[i] != f2[i]){
                return false;
            }
            
        }
        return true;

    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] ={0};
        for(int i = 0; i<s1.length();i++){
            freq[s1[i]-'a']++;

        }
        int st = 0;
        int end = s1.length()-1;
        while(end < s2.length()){
            int tarFreq[26] = {0};
            for(int i = st; i<=end;i++){
                tarFreq[s2[i]-'a']++;
            }
            if (issame(tarFreq,freq)){
                return true;

            }
            end++;
            st++;

        }

         return false;
    

    }
};
