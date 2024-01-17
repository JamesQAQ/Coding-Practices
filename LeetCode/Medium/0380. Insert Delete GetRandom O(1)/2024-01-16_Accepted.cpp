class RandomizedSet {
private:
  unordered_map<int, int> uMap;
  vector<int> arr;

public:
  RandomizedSet() {
    uMap.clear();
    arr.clear();
  }

  bool insert(int val) {
    if (uMap.find(val) == uMap.end()) {
      arr.push_back(val);
      uMap[val] = arr.size() - 1;
      return true;
    }
    return false;
  }

  bool remove(int val) {
    if (uMap.find(val) != uMap.end()) {
      uMap[arr[arr.size() - 1]] = uMap[val];
      swap(arr[uMap[val]], arr[arr.size() - 1]);
      arr.pop_back();
      uMap.erase(val);
      return true;
    }
    return false;
  }

  int getRandom() {
    return arr[rand() % arr.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
