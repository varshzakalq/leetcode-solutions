class SmallestInfiniteSet {
public:
    int curr; 
    priority_queue<int, vector<int>, greater<int>> minheap;
    set <int> s;
    SmallestInfiniteSet() {
        curr = 1;
        
    }
    
    int popSmallest() {
        if(!minheap.empty()){
            int a = minheap.top();
            minheap.pop();
            s.erase(a);
            return a;
        }
        else{
            int ans = curr;
            curr++;
            return ans;
        }
    }
    
    void addBack(int num) {
        if(curr> num && s.find(num)== s.end()){
            minheap.push(num);
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
