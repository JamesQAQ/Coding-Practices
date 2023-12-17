#include <algorithm>

struct Node {
    int pos, id;
    bool insert;
    Node (int _pos, int _id, bool _insert) {
        pos = _pos;
        id = _id;
        insert = _insert;
    }
} ;

bool cmp(Node i, Node j) {
    return i.pos < j.pos;
}

struct Heap {
    int num, a[100000];

    void init() {
        num = 0;
    }

    void push(int x, vector<vector<int>>& buildings) {
        a[++num] = x;
        up(num, buildings);
    }

    int pop(vector<vector<int>>& buildings) {
        int val = a[1];
        swap(a[1], a[num--]);
        down(1, buildings);
        return val;
    }

    void up(int x, vector<vector<int>>& buildings) {
        int f = x >> 1;
        while (f >= 1 && buildings[a[x]][2] > buildings[a[f]][2]) {
            swap(a[x], a[f]);
            x = f;
            f >>= 1;
        }
    }

    void down(int x, vector<vector<int>>& buildings) {
        int s = x << 1;
        while (s <= num) {
            if (s < num && buildings[a[s + 1]][2] > buildings[a[s]][2])
                s++;
            if (buildings[a[x]][2] >= buildings[a[s]][2])
                break;
            swap(a[x], a[s]);
            x = s;
            s <<= 1;
        }
    }

    bool empty() {
        return num == 0;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Node> a;
        vector<bool> leave;
        for (int i = 0; i < buildings.size(); i++) {
            Node b(buildings[i][0], i, true);
            a.push_back(b);
            Node c(buildings[i][1], i, false);
            a.push_back(c);
            leave.push_back(false);
        }
        stable_sort(a.begin(), a.end(), cmp);
        Heap heap;
        heap.init();
        vector<pair<int, int>> ans;
        for (int i = 0; i < a.size(); i++) {
            int now = a[i].pos;
            while (i < a.size() && a[i].pos == now) {
                if (a[i].insert)
                    heap.push(a[i].id, buildings);
                else
                    leave[a[i].id] = true;
                i++;
            }
            while (!heap.empty() && leave[heap.a[1]])
                heap.pop(buildings);
            if (heap.empty()) {
                if (ans.size() == 0 || ans[ans.size() - 1].second != 0)
                    ans.push_back(make_pair(now, 0));
            }
            else {
                if (ans.size() == 0 || ans[ans.size() - 1].second != buildings[heap.a[1]][2])
                    ans.push_back(make_pair(now, buildings[heap.a[1]][2]));
            }
            i--;
        }
        return ans;
    }
};
