class Solution {
public:
  int maximumGain(string s, int x, int y) {
    return max(tryGain(s, "ab", x, y), tryGain(s, "ba", y, x));
  }

private:
  int tryGain(string& s, string pattern, int x, int y) {
    int gain = 0;
    vector<char> st;
    for (auto ch : s) {
      if (ch == pattern[1] && !st.empty() && st[st.size() - 1] == pattern[0]) {
        st.pop_back();
        gain += x;
      } else {
        st.push_back(ch);
      }
    }

    stack<char> st2;
    for (int i = 0; i < st.size(); i++) {
      if (st[i] == pattern[0] && !st2.empty() && st2.top() == pattern[1]) {
        st2.pop();
        gain += y;
      } else {
        st2.push(st[i]);
      }
    }

    return gain;
  }
};
