class Solution {     
    int mod = 1000000007;
    long long inv[4] = {0, 1, 500000004, 166666668};
    
public:
    int threeSumMulti(vector<int>& arr, int target) {   
        
        int count[301] = {};
        for (int i = 0; i < arr.size(); i++) {
            count[arr[i]]++;
        }
        long long ans = 0;
        for (int i = 0; 3 * i <= target; i++) {
            for (int j = i; 2 * j <= target - i; j++) {
                int k = target - i - j;
                if (i == j && j == k) {
                    if (count[i] >= 3) {
                        ans = (ans + C(count[i], 3)) % mod;
                    }
                } else if (i == j) {
                    if (count[i] >= 2) {
                        ans = (ans + C(count[i], 2) * count[k]) % mod;
                    }
                } else if (j == k) {
                    if (count[j] >= 2) {
                        ans = (ans + C(count[j], 2) * count[i]) % mod;
                    }
                } else {
                    ans = (ans + count[i] * count[j] * count[k]) % mod;
                }
            }
        }
        return ans;
    }
    
private:
    long long C(int n, int m) {
        long long res = 1;
        for (int i = 0; i < m; i++) {
            res = (res * (n - i)) % mod;
        }
        return (res * inv[m]) % mod;
    }
};