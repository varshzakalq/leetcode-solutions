class Solution {
public:
    int sgn(int a){
        if(a<0)
            return 0;
        return 1;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> s1;
        int i =1;
        s1.push(asteroids[0]);
        while(i <asteroids.size()){
            int a  = asteroids[i];
            bool flag =false;
            if(!s1.empty()&&s1.top()>0 && a<0){
               while(!s1.empty()&&s1.top()>0 && a<0){
                    if(abs(a)>abs(s1.top())){
                        s1.pop();
                    }
                    else if(abs(a)==abs(s1.top())){
                        s1.pop();
                        flag = true;
                        break;
                    }
                    else{
                        flag = true;
                        break;
                    }
               }
               if(flag == false)s1.push(asteroids[i]);
                  
            }
            else{
                s1.push(asteroids[i]);
            }
            i++;
        }
        vector <int> ans;
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
