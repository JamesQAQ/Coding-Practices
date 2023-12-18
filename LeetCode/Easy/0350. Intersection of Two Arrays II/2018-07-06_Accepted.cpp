class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> times;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            if (times.find(nums1[i]) != times.end()) {
                times[nums1[i]]++;
            } else {
                times[nums1[i]] = 1;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (times.find(nums2[i]) != times.end()) {
                ans.push_back(nums2[i]);
                times[nums2[i]]--;
                if (times[nums2[i]] == 0) {
                    times.erase(nums2[i]);
                }
            }
        }
        return ans;
    }
};