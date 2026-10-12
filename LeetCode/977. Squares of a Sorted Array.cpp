class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int idx = nums.size()-1;
        int p1 = 0, p2 = nums.size()-1;

        while(p1<p2){
            if(abs(nums[p1]) <= abs(nums[p2])){
                result[idx] = nums[p2]*nums[p2];
                p2--;
            }else{
                result[idx] = nums[p1]*nums[p1];
                p1++;
            }
            idx--;
        }

        result[0] = nums[p1]*nums[p1];

        return result;
    }
};