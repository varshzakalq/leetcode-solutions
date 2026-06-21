class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int size = costs.size();
        int maxVal = *max_element(costs.begin(),costs.end());
        vector<int> cntArray(maxVal+1,0);
        
        for(int i =0;i<costs.size();i++){
            cntArray[costs[i]]++;
        }
        for(int i =1;i<cntArray.size();i++){
            cntArray[i] += cntArray[i-1];
        }
        // for(auto i:cntArray){
        //     cout<<i<<" ";
        // }cout<<endl;
        vector<int>sorted(costs.size(),0);
        int i = costs.size()-1;
        while(i>=0){
            int v = costs[i];
            int place = (cntArray[v]--)-1;
            sorted[place] = v;
            i--;
        }
        // for(auto i:sorted){
        //     cout<<i<<" ";
        // }
        int count = 0;
        int j =0;
        while(coins>0 && j<size){
            if(coins - sorted[j]>=0){
                 coins -=sorted[j++] ;
                count++;
            }
            else{break;}
               
        }
        return count++;

    }
};
