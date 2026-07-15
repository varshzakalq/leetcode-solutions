class Solution {
public:
    string simplifyPath(string path) {
        stack <string> s;
        for(int i =0; i<path.size();i++){
            string dir = "";
            while( i<path.size()&&path[i]!= '/'){
                dir  += path[i];
                i++;
            }
            if(dir ==".." && !s.empty()){
                s.pop();
                continue;
            }
            if(dir !="" && dir != ".."&& dir != "."){
                s.push(dir);
            }
        }
        string ans = "";
 
        while(!s.empty()){
            string top = s.top();
            s.pop();
            ans ="/"+ top +ans;
        }

        if(ans == ""){
            return "/";
        }
        return ans;

    }
};