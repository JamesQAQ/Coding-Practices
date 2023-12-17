struct MyChar {
  char c;
  bool star;

  MyChar(char _c, bool _star) {
    c = _c;
    star = _star;
  }
};

class Solution {
public:
  bool isMatch(string _s, string _p) {
    vector<MyChar> s = process(_s);
    vector<MyChar> p = process(_p);
    bool dp[2][s.size() + 1];
    bool* pre = dp[0];
    bool* now = dp[1];
    now[0] = true;
    for (int i = 1; i < s.size() + 1; i++) {
      now[i] = false;
    }
    for (int i = 1; i < p.size() + 1; i++) {
      swap(pre, now);
      char c = p[i - 1].c;
      bool star = p[i - 1].star;
      now[0] = (star) ? pre[0] : false;
      for (int j = 1; j < s.size() + 1; j++) {
        if (star) {
          now[j] = pre[j] || (compare(s[j - 1].c, c) && (pre[j - 1] || now[j - 1]));
        } else {
          now[j] = compare(s[j - 1].c, c) && pre[j - 1];
        }
      }
    }
    return now[_s.size()];
  }

private:
  vector<MyChar> process(string s) {
    vector<MyChar> result;
    int len = s.length();
    for (int i = 0; i < len - 1; i++) {
      if (s[i + 1] == '*') {
        MyChar mc = MyChar(s[i], true);
        result.push_back(mc);
        i++;
      } else {
        MyChar mc = MyChar(s[i], false);
        result.push_back(mc);
      }
    }
    if (len - 1 >= 0) {
      if (s[len - 1] != '*') {
        MyChar mc = MyChar(s[len - 1], false);
        result.push_back(mc);
      }
    }
    return result;
  }

  bool compare(char a, char b) {
    return (b == '.') || (a == b);
  }
};