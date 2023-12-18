class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> a = convertString(num1);
        vector<int> b = convertString(num2);
        if (a.size() < b.size()) {
            swap(a, b);
        }
        for (int i = 0; i < b.size(); i++) {
            a[i] += b[i];
        }
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] >= 10) {
                a[i] -= 10;
                a[i + 1]++;
            }
        }
        if (a[a.size() - 1] >= 10) {
            a[a.size() - 1] -= 10;
            a.push_back(1);
        }
        string ans = "";
        for (int i = a.size() - 1; i >= 0; i--) {
            ans += a[i] + '0';
        }
        return ans;
    }

private:
    vector<int> convertString(string s) {
        vector<int> num;
        for (int i = s.length() - 1; i >= 0; i--) {
            num.push_back(s[i] - '0');
        }
        return num;
    }
};