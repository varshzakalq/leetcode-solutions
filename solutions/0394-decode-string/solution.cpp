class Solution {
public:
    string decodeString(string s) {
        stack <string> s1;
        string ans = "";
        for(int i =0; i<s.size();i++){
            if(s[i]!= ']')
                s1.push(std::string()+(s[i]));
           else{
                string temp = "";
                while(s1.top() != "["){
                    
                    temp = s1.top()+ temp;
                    s1.pop();     
                
                }
                
                s1.pop();
                string num ="";
                while(!s1.empty()&&isdigit(s1.top()[0])){
                    num = s1.top()+num;
                    s1.pop();

                }
                int t =  stoi(num);
                
                int i=0;
                string s = "";
                while(i<t){
                    s+=temp;
                    i++;
                }
                s1.push(s);
            }
        }
       while(!s1.empty()){
            ans = s1.top() + ans;
            s1.pop();
        }
        return ans;
        
    }
};
