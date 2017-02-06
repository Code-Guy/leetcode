class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {}
 
	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		index[val].insert(output.size());
		output.push_back(val);
		return index[val].size() == 1;
	}
 
	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (index.find(val) == index.end()) {
		    return false;
		}
		
		int last = output.back(); 
		output.pop_back();
	
		index[last].erase(output.size());
		if (last != val) {
			int id = *index[val].begin(); 
			index[val].erase(id);
			index[last].insert(id);
			output[id] = last;
		}
		if (index[val].empty()) {
		    index.erase(val);
		}
		
		return true;
	}
 
	/** Get a random element from the collection. */
	int getRandom() {
		return output[rand() % output.size()];
	}
	
private:
	unordered_map<int, unordered_set<int>> index;
	vector<int> output;
};
  
/** 
 * Your RandomizedCollection object will be instantiated and called as such: 
 * RandomizedCollection obj = new RandomizedCollection(); 
 * bool param_1 = obj.insert(val); 
 * bool param_2 = obj.remove(val); 
 * int param_3 = obj.getRandom(); 
 */ 

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
