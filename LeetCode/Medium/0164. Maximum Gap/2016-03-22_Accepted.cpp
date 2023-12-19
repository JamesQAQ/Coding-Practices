class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int mini = nums[0], maxx = nums[0];
        for (int i = 1; i < n; i++){
            mini = min(mini, nums[i]);
            maxx = max(maxx, nums[i]);
        }
        if (mini == maxx)
            return 0;
        double d = (double)(maxx + 1e-4 - mini) / (n + 1);
        int bmin[n + 1], bmax[n + 1], bexist[n + 1] = {};
        for (int i = 0; i < n; i++){
            int pos = (int)((nums[i] - mini) / d);
            if (!bexist[pos]){
                bexist[pos] = true;
                bmin[pos] = bmax[pos] = nums[i];
            }
            else{
                bmin[pos] = min(bmin[pos], nums[i]);
                bmax[pos] = max(bmax[pos], nums[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!bexist[i])
                continue;
            int next = i + 1;
            while (!bexist[next])
                next++;
            if (next > n)
                continue;
            ans = max(ans, bmin[next] - bmax[i]);
        }
        return ans;
    }
};
