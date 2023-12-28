class Solution {
public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    return min(
        _distance(distance, start, destination),
        _distance(distance, destination, start));
  }

private:
  int _distance(vector<int>& distance, int from, int to) {
    if (from > to) {
      to += distance.size();
    }
    int sum = 0;
    for (int i = from; i < to; i++) {
      sum += distance[i % distance.size()];
    }
    return sum;
  }
};
