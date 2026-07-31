class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_tank =0;
        int total_tank =0;
        int starting_station =0;
        for(int i =0;i<gas.size();i++){
            int net = gas[i]-cost[i];
            curr_tank += net;
            total_tank += net;
            if(curr_tank <0){
                starting_station = i+1;
                curr_tank =0;
            }
        }
        return (total_tank>=0)? starting_station:-1;
    }
};
