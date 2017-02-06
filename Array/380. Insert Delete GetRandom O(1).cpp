class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (umap.find(val) != umap.end()) {
            return false;
        }
        
        umap[val] = nums.size();
        nums.push_back(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (umap.find(val) == umap.end()) {
            return false;
        }
        
        int last = nums.back();
        nums.pop_back();
        
        int id = umap[val];
        umap.erase(val);
        if (last != val) {
            umap[last] = id;
            nums[id] = last;
        }

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
	unordered_map<int, int> umap;
	vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
