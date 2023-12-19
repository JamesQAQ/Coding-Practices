class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> cnt;
        for (int i = 0; i < arr.size(); i++) {
            if (cnt.find(arr[i]) == cnt.end()) {
                cnt[arr[i]] = 0;
            }
            cnt[arr[i]]++;
        }
        vector<int> a;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            a.push_back(-it->second);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (sum < arr.size() / 2) {
                ans++;
                sum -= a[i];
            }
        }
        return ans;
    }
};