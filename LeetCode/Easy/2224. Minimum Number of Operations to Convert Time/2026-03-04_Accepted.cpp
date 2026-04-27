class Solution {
public:
  int convertTime(string current, string correct) {
    int curMins = getMins(current);
    int corMins = getMins(correct);
    if (corMins < curMins) {
      corMins += 1440;
    }
    int remain = corMins - curMins;

    int operations[4] = {60, 15, 5, 1};
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      ans += adjust(remain, operations[i]);
    }
    return ans;
  }

private:
  int getMins(string& s) {
    return ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
  }

  int adjust(int& remain, int mins) {
    int times = remain / mins;
    remain -= times * mins;
    return times;
  }
};
