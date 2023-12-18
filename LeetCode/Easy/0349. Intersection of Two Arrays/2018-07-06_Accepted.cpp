class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> appeared;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            appeared.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (appeared.find(nums2[i]) != appeared.end()) {
                ans.push_back(nums2[i]);
                appeared.erase(nums2[i]);
            }
        }
        return ans;
    }
};