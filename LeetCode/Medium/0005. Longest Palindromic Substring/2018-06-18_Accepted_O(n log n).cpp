#define COE 53
#define MOD 1000000007

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";

        // Initialize for hash vector
        lhash.clear();
        rhash.clear();
        for (int i = 0; i < s.length(); i++) {
            lhash.push_back(0);
            rhash.push_back(0);
        }

        int l = 1, r = s.length();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (hasPalindrome(mid, s)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = "";
        hasPalindrome(r, s);
        return ans;
    }
private:
    vector<long long> lhash;
    vector<long long> rhash;
    string ans;

    bool hasPalindrome(int length, string& s) {
        int n1, n2;
        if (length % 2 == 1) {
            n1 = length / 2 + 1;
            n2 = (length + 1) / 2;
        } else {
            n1 = length / 2;
            n2 = length / 2 + 1;
        }
        return check(n1, 1, s) || check(n2, 0, s);
    }

    bool check(int n, int offset, string& s) {
        int s_len = s.length();
        
        // create left hash
        long long cur_val = 0;
        long long power = 1;
        for (int i = 0; i < n; i++) {
            power = (power * COE) % MOD;
            cur_val = (cur_val * COE + s[i]) % MOD;
        }
        lhash[n - 1] = cur_val;
        for (int i = n; i < s_len; i++) {
            cur_val = (cur_val * COE + s[i]) % MOD;
            cur_val = ((cur_val - power * s[i - n]) % MOD + MOD) % MOD;
            lhash[i] = cur_val;
        }

        // create right hash
        cur_val = 0;
        for (int i = s_len - 1; i >= s_len - n; i--) {
            cur_val = (cur_val * COE + s[i]) % MOD;
        }
        rhash[s_len - n] = cur_val;
        for (int i = s_len- n - 1; i >= 0; i--) {
            cur_val = (cur_val * COE + s[i]) % MOD;
            cur_val = ((cur_val - power * s[i + n]) % MOD + MOD) % MOD;
            rhash[i] = cur_val;
        }

        for (int i = n - 1; i <= s_len - n - offset; i++) {
            if (lhash[i] == rhash[i + offset]) {
                ans = s.substr(i - n + 1, 2 * n - 1 + offset);
                return true;
            }
        }

        return false;
    }
};