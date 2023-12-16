class Solution {
public:
    bool canCross(vector<int>& stones) {
        // Especially use `unordered_set` instead of `set` to speed up.
        unordered_set<int> stone_set;
        for (auto stone: stones) {
            stone_set.insert(stone);
        }

        // Use BFS method to do Dynamic Programming, `added_pair_set`
        // is used to avoid adding the same pair into the queue.
        unordered_set<long long> added_pair_set;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto[stone, k] = q.front();
            q.pop();
            if (stone == stones.back()) {
                return true;
            }
            for (int i = -1; i <= 1; i++) {
                if (k + i > 0) {
                    int next = stone + k + i;
                    if (stone_set.count(next)) {
                        if (added_pair_set.count(hash_pair(next, k + i)) == 0) {
                            q.push({next, k + i});
                            added_pair_set.insert(hash_pair(next, k + i));
                        }
                    }
                }
            }
        }
        return false;
    }

private:
    long long hash_pair(int stone, int k) {
        return (long long)stone * 2001 + k;
    }
};
