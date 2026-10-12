class Solution {
public:
    int trap(vector<int>& height) {
        int trapped_water = 0;
        int maxLeft = 0, maxRight = 0;
        int left = 0, right = height.size()-1;

        while(left < right){
            if(height[left] < height[right]){
                if(height[left] < maxLeft){
                    trapped_water += maxLeft-height[left];
                }else{
                    maxLeft = height[left];
                }
                left++;
            }else{
                if(height[right] < maxRight){
                    trapped_water += maxRight-height[right];
                }else{
                    maxRight = height[right];
                }
                right--;
            }
        }

        return trapped_water;
    }
};