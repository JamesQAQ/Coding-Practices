#define MAX 100000

struct Record{
    int h, x;
} _stack[MAX];

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int top = 0;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++){
            int now = heights[i], idx = i;
            while (top > 0 && _stack[top - 1].h > now){
                ans = max(ans, _stack[top - 1].h * (i - _stack[top - 1].x));
                idx = _stack[top - 1].x;
                top--;
            }
            if (top == 0 || _stack[top - 1].h != now){
                Record tmp;
                tmp.h = now;
                tmp.x = idx;
                _stack[top++] = tmp;
            }
        }
        while (top > 0){
            ans = max(ans, _stack[top - 1].h * ((int)heights.size() - _stack[top - 1].x));
            top--;
        }
        return ans;
    }
};
