#include <algorithm>
using std::stable_sort;

#define MAX 2147483647
#define MIN -2147483648

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int all = nums1.size() + nums2.size();
        /*
        if (nums2.size() == 0) {
            if (all % 2 == 0) {
                return (nums1[all / 2 - 1] + nums1[all / 2]) * 0.5;
            } else {
                return nums1[all / 2];
            }
        }
        */
        if (all % 2 == 0) {
            // even case
            int target = all / 2;
            int l = -1;
            int r = min(nums1.size() - 1, target - 1);
            while (l <= r) {
                int mid = (l + r) / 2;
                int x1 = (mid >= 0) ? nums1[mid] : MIN;
                int x2 = (mid + 1 < nums1.size()) ? nums1[mid + 1] : MAX;
                int mid2 = target - mid - 2;
                // printf("mid2 %d\n", mid2);
                if (mid2 >= (int)nums2.size()) {
                    l = mid + 1;
                    continue;
                }
                int y1 = (mid2 >= 0) ? nums2[mid2] : MIN;
                int y2 = (mid2 + 1 < nums2.size()) ? nums2[mid2 + 1] : MAX;
                /*
                    printf("l %d, r %d\n", l, r);
                    printf("%d %d %d\n", mid, mid2, target);
                    printf("%d %d, %d %d\n", x1, x2, y1, y2);
                */
                if (x1 <= y2 && y1 <= x2) {
                    // matched
                    vector<int> arr;
                    arr.push_back(x1);
                    arr.push_back(x2);
                    arr.push_back(y1);
                    arr.push_back(y2);
                    stable_sort(arr.begin(), arr.end());
                    return (arr[1] + arr[2]) * 0.5;
                } else if (x1 > y2) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        } else {
            // odd case
            int target = all / 2;
            int l = -1;
            int r = min(nums1.size() - 1, target - 1);
            while (l <= r) {
                int mid = (l + r) / 2;
                int x1 = (mid >= 0) ? nums1[mid] : MIN;
                int x2 = (mid + 1 < nums1.size()) ? nums1[mid + 1] : MAX;
                int mid2 = target - mid - 2;
                if (mid2 >= (int)nums2.size()) {
                    l = mid + 1;
                    continue;
                }
                int y1 = (mid2 >= 0) ? nums2[mid2] : MIN;
                int y2 = (mid2 + 1 < nums2.size()) ? nums2[mid2 + 1] : MAX;
                int minx2y2 = min(x2, y2);
                if (x1 <= minx2y2 && y1 <= minx2y2) {
                    return minx2y2;
                } else if (x1 > minx2y2) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return 0.0;
    }
private:
    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};