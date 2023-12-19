struct Data {
    int num;
    int count;
    
    bool operator<(const Data& i) const {
        return count > i.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++) {
            if (countMap.find(nums[i]) == countMap.end()) {
                countMap[nums[i]] = 0;
            }
            countMap[nums[i]]++;
        }
        priority_queue<Data> keeper;
        for (auto it = countMap.begin(); it != countMap.end(); it++) {
            if (keeper.size() < k) {
                keeper.push({it->first, it->second});
            } else if (it->second > keeper.top().count) {
                keeper.pop();
                keeper.push({it->first, it->second});
            }
        }
        vector<int> ans;
        while (!keeper.empty()) {
            ans.push_back(keeper.top().num);
            keeper.pop();
        }
        return ans;
    }
};