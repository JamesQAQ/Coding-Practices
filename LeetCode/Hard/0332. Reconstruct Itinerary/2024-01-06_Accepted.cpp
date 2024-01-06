class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    map<string, map<string, int>> paths;
    for (int i = 0; i < tickets.size(); i++) {
      string from = tickets[i][0];
      string to = tickets[i][1];
      if (paths.find(from) == paths.end()) {
        paths[from] = map<string, int>();
      }
      if (paths[from].find(to) == paths[from].end()) {
        paths[from][to] = 0;
      }
      paths[from][to]++;
    }

    vector<string> result;
    result.push_back("JFK");
    dfs("JFK", paths, result, tickets.size());
    return result;
  }

private:
  void dfs(
      string airport,
      map<string, map<string, int>>& paths,
      vector<string>& result,
      int len) {
    if (result.size() - 1 == len) {
      return;
    }
    for (auto it = paths[airport].begin(); it != paths[airport].end(); it++) {
      if (it->second > 0) {
        it->second--;
        result.push_back(it->first);
        dfs(it->first, paths, result, len);
        if (result.size() - 1 == len) {
          return;
        }
        result.pop_back();
        it->second++;
      }
    }
  }
};
