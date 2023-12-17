class Solution {
public:
    int trap(vector<int>& height) {
        int max_height_pos = 0;
        for (int i = 1; i < height.size(); i++) {
          if (height[i] > height[max_height_pos]) {
            max_height_pos = i;
          }
        }

        int ans = 0;
        // From left to the position of maximum height.
        int current_max_height = 0;
        for (int i = 0; i < max_height_pos; i++) {
          current_max_height = max(current_max_height, height[i]);
          ans += current_max_height - height[i];
        }

        // From right to the position of maximum height.
        current_max_height = 0;
        for (int i = height.size() - 1; i > max_height_pos; i--) {
          current_max_height = max(current_max_height, height[i]);
          ans += current_max_height - height[i];
        }
        return ans;
    }
};
