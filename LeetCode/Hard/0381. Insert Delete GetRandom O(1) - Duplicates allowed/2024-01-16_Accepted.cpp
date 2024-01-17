class RandomizedCollection {
private:
  unordered_map<int, vector<int>> uMap;
  vector<int> arr;

public:
  RandomizedCollection() {
    uMap.clear();
    arr.clear();
  }

  bool insert(int val) {
    bool existing = (uMap.find(val) != uMap.end());
    if (!existing) {
      uMap[val] = vector<int>();
    }
    arr.push_back(val);
    uMap[val].push_back(arr.size() - 1);
    return !existing;
  }

  bool remove(int val) {
    if (uMap.find(val) == uMap.end()) {
      return false;
    }
    int last = arr[arr.size() - 1];
    uMap[last][uMap[last].size() - 1] = uMap[val][uMap[val].size() - 1];
    swap(arr[uMap[val][uMap[val].size() - 1]], arr[arr.size() - 1]);
    sort(uMap[last].begin(), uMap[last].end());
    arr.pop_back();
    uMap[val].pop_back();
    if (uMap[val].size() == 0) {
      uMap.erase(val);
    } else {
      sort(uMap[val].begin(), uMap[val].end());
    }
    return true;
  }

  int getRandom() {
    return arr[rand() % arr.size()];
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
