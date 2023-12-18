class Solution {
    int val[10001];
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int n = nums2[i];
            while (!st.empty() && n > st.top()) {
                st.pop();
            }
            val[n] = st.empty() ? -1 : st.top();
            st.push(n);
        }
        
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(val[nums1[i]]);
        }
        return ans;
    }
};