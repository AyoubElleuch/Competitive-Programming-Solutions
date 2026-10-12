class Solution {
public:
    int maxArea(vector<int>& height) {
        int MAX = 0;

        int i=0, j=height.size()-1;

        while(i<j){
            int width = j-i;
            int area = height[i] < height[j] ? height[i]*width : height[j]*width;
            MAX = area > MAX ? area : MAX;

            height[i] < height[j] ? i++ : j--;
        }

        return MAX;
    }
};