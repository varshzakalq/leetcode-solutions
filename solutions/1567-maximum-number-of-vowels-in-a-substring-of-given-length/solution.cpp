class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c =='a'|| c =='e'|| c == 'i' || c == 'o'|| c == 'u'){return true;}
        return false;
    }
    int maxVowels(string s, int k) {
        int i =0;
        int j =0;
    
        int count =0;
        while (j<k){
            if(isVowel(s[j]))count++;
            j++;
        }
        int max = count;
        while(j<s.size()){
            if(isVowel(s[i++])) count--;
            if(isVowel(s[j++])) count++;
            if(count >max) max = count;
            
        }
        return max;
    }
};
