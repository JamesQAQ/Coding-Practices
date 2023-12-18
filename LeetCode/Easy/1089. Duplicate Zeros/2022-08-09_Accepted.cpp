class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int r = arr.size() - 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) r++;
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                if (r < arr.size()) {
                    arr[r] = 0;
                }
                r--;
                if (r < arr.size()) {
                    arr[r] = 0;
                }
                r--;
            } else {
                if (r < arr.size()) {
                    arr[r] = arr[i];
                }
                r--;
            }
        }
    }
};
