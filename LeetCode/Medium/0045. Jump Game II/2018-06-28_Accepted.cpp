#include <map>

using std::map;

class Solution {
public:
    int jump(vector<int>& nums) {
        map<int, int> mymap;
        mymap[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            map<int, int>::iterator it = mymap.begin();
            while (it != mymap.end() && it->second < i) {
                map<int, int>::iterator tmp = it;
                it++;
                mymap.erase(tmp);
            }
            int val = it->first + 1;
            int r = i + nums[i];
            it = mymap.lower_bound(val);
            while (it != mymap.end() && it->second < r) {
                map<int, int>::iterator tmp = it;
                it++;
                mymap.erase(tmp);
            }
            if (mymap.find(val) == mymap.end()) {
                mymap[val] = r;
            }
        }
        map<int, int>::iterator it = mymap.begin();
        while (it != mymap.end() && it->second < nums.size() - 1) {
            map<int, int>::iterator tmp = it;
            it++;
            mymap.erase(tmp);
        }
        return mymap.begin()->first;
    }
};