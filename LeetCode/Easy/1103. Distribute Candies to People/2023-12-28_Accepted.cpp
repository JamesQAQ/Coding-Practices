class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> result(num_people, 0);
    int distributed_candy = 1;
    while (candies > 0) {
      for (int i = 0; i < num_people; i++) {
        if (candies == 0) {
          break;
        }
        int actually_distributed_candy = min(candies, distributed_candy++);
        result[i] += actually_distributed_candy;
        candies -= actually_distributed_candy;
      }
    }
    return result;
  }
};
