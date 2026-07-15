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
        int count = 0;
        cout<<s.size()<<"hhh";
        while(!s.empty()){
            count++;
            string top = s.top();
            cout<<top<<" ";
            s.pop();
            ans ="/"+ top +ans;
        }
        cout<<count;
        if(ans == ""){
            return "/";
        }
        return ans;

    }
};