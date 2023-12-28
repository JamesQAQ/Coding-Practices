struct Placeholder {
  int pos;
  int k;
  int endChar;
  int repeat;

  int toStateValue(int len, int _k, int max_char) {
    return max_char * (len + 1) * (_k + 1) * pos + max_char * (len + 1) * k +
        (len + 1) * endChar + repeat;
  }
};

class Solution {
private:
  int MAX = 101;

public:
  int getLengthOfOptimalCompression(string s, int k) {
    int max_char = 0;
    for (auto ch : s) {
      max_char = max(max_char, ch - 'a' + 2);
    }
    vector<int> dp(
        (s.length() + 1) * (k + 1) * max_char * (s.length() + 1), MAX);
    vector<bool> visited(
        (s.length() + 1) * (k + 1) * max_char * (s.length() + 1), false);
    int ans = MAX;
    Placeholder start = {0, k, 0, 1};
    dp[start.toStateValue(s.length(), k, max_char)] = 0;
    queue<Placeholder> q;
    q.push(start);
    while (!q.empty()) {
      Placeholder cur = q.front();
      q.pop();
      int curState = cur.toStateValue(s.length(), k, max_char);
      if (!visited[curState]) {
        visited[curState] = true;
      } else {
        continue;
      }

      if (cur.pos == s.length()) {
        ans = min(ans, dp[curState]);
        continue;
      }
      if (cur.k > 0) {
        Placeholder next = {cur.pos + 1, cur.k - 1, cur.endChar, cur.repeat};
        int nextState = next.toStateValue(s.length(), k, max_char);
        dp[nextState] = min(dp[nextState], dp[curState]);
        q.push(next);
      }
      if (s[cur.pos] - 'a' + 1 == cur.endChar) {
        Placeholder next = {
            cur.pos + 1, cur.k, s[cur.pos] - 'a' + 1, cur.repeat + 1};
        int nextState = next.toStateValue(s.length(), k, max_char);
        dp[nextState] = min(
            dp[nextState],
            dp[curState] + (
                cur.repeat == 1 || cur.repeat == 9 || cur.repeat == 99));
        q.push(next);
      } else {
        Placeholder next = {cur.pos + 1, cur.k, s[cur.pos] - 'a' + 1, 1};
        int nextState = next.toStateValue(s.length(), k, max_char);
        dp[nextState] = min(dp[nextState], dp[curState] + 1);
        q.push(next);
      }
    }
    return ans;
  }
};
