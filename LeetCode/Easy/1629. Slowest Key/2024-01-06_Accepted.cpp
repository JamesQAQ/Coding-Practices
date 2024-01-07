class Solution {
public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int maxDuration = releaseTimes[0];
    char ans = keysPressed[0];
    for (int i = 1; i < releaseTimes.size(); i++) {
      int duration = releaseTimes[i] - releaseTimes[i - 1];
      if (duration > maxDuration) {
        maxDuration = duration;
        ans = keysPressed[i];
      } else if (duration == maxDuration) {
        ans = max(ans, keysPressed[i]);
      }
    }
    return ans;
  }
};
