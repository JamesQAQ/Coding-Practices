struct Job {
  int startTime;
  int endTime;
  int profit;

  bool operator<(const Job& other) const {
    return startTime < other.startTime;
  }
};

class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<int> times;
    times.insert(times.end(), startTime.begin(), startTime.end());
    times.insert(times.end(), endTime.begin(), endTime.end());
    sort(times.begin(), times.end());
    map<int, int> mapping;
    int pre = 0;
    int count = 0;
    for (auto time : times) {
      if (time != pre) {
        pre = time;
        mapping[time] = count++;
      }
    }
    vector<Job> jobs;
    for (int i = 0; i < startTime.size(); i++) {
      jobs.push_back({mapping[startTime[i]], mapping[endTime[i]], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(count + 1, 0);
    int ans = 0;
    int ptr = 0;
    for (auto job : jobs) {
      while (ptr < job.startTime) {
        dp[ptr] = max(dp[ptr + 1], dp[ptr++]);
      }
      dp[job.endTime] = max(dp[job.endTime], dp[job.startTime] + job.profit);
      ans = max(ans, dp[job.endTime]);
    }
    return ans;
  }
};
