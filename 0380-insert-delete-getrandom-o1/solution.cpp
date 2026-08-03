class RandomizedSet {
    
public:
    unordered_map<int,int> mp;
    vector<int> container;
    mt19937 gen;

    RandomizedSet() :gen(random_device{}()) {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)>0)return false;
        container.push_back(val);
        mp[val] = container.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)<=0) return false;
        mp[container[container.size()-1]] = mp[val];
        swap(container[mp[val]],container[container.size()-1]);
        container.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution <int> distrib(0,container.size()-1);
        return container[distrib(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
