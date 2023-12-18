class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        for (int i = 0; i < ops.size(); i++) {
            string op = ops[i];
            if (op == "+") arr.push_back(arr[arr.size() - 2] + arr[arr.size() - 1]);
            else if (op == "D") arr.push_back(arr[arr.size() - 1] * 2);
            else if (op == "C") arr.pop_back();
            else arr.push_back(stoi(op));
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans += arr[i];
        }
        return ans;
    }
};