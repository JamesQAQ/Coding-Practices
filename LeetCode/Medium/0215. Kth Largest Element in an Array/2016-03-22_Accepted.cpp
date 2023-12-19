int mid(vector<int>& nums, int l, int r, int k){
    if (l == r)
        return nums[l];
    int pivot = nums[l], ptr = r;
    for (int i = l; i <= ptr; i++)
        if (nums[i] < pivot)
            swap(nums[i--], nums[ptr--]);
    swap(nums[l], nums[ptr]);
    if (ptr - l + 1 == k)
        return nums[ptr];
    else if (k <= ptr - l)
        return mid(nums, l, ptr - 1, k);
    else
        return mid(nums, ptr + 1, r, k - (ptr - l + 1));
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return mid(nums, 0, nums.size() - 1, k);
    }
};
