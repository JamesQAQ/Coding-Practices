class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int firstPointer = nums[0];
        int secondPointer = nums[nums[0]];
        while (firstPointer != secondPointer) {
            firstPointer = nums[firstPointer];
            secondPointer = nums[nums[secondPointer]];
        }
        firstPointer = 0;
        while (firstPointer != secondPointer) {
            firstPointer = nums[firstPointer];
            secondPointer = nums[secondPointer];
        }
        return firstPointer;
    }
};