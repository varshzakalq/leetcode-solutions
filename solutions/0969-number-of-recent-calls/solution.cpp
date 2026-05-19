class RecentCounter {
public:
    queue<int> q1;
    int count;
    int time ;
    RecentCounter() {
        count =0;
        time =0;
        
        q1 ={};
    }
    
    int ping(int t) {
        count++;
        time =t-3000;
        q1.push(t);
        while(time>q1.front()){
            q1.pop();
            count--;
        }
        return q1.size();

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
