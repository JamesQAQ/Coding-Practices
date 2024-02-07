class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int pos = 0;
    while (pos < gas.size()) {
      int ret = check(pos, gas, cost);
      if (ret == -1) {
        return pos;
      }
      pos = ret + 1;
    }
    return -1;
  }

private:
  int check(int start, vector<int>& gas, vector<int>& cost) {
    int tank = 0;
    for (int i = 0; i < gas.size(); i++) {
      int idx = (start + i) % gas.size();
      tank += gas[idx] - cost[idx];
      if (tank < 0) {
        return start + i;
      }
    }
    return -1;
  }
};
