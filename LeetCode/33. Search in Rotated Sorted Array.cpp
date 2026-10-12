class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left<=right){
            int pivot = left + (right - left)/2;
            if(nums[pivot]==target) return pivot;

            if(nums[left] <= nums[pivot]) {
                if(nums[left] <= target && target <= nums[pivot]) right = pivot - 1;
                else left = pivot + 1;
            } else {
                if(nums[pivot] <= target && target <= nums[right]) left = pivot + 1;
                else right = pivot - 1;
            }
        }

        return -1;
    }
};