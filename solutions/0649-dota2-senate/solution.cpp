class Solution {
public:
    string predictPartyVictory(string senate) {

        queue <int>r;
        queue <int>d;

        for(auto i =0; i<senate.size();i++){
            if(senate[i]== 'R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }
        int n = senate.size();
        while(!r.empty()&&!d.empty()){
           
            if(r.front()<d.front()){
                d.pop();
                int temp = r.front();
                r.push(temp+n);
                r.pop();
            }
            else{
                r.pop();
                d.push(d.front()+n);
                d.pop();
            }
            
        }
        if(!r.empty())return "Radiant";
        return "Dire";

       
    }
};
