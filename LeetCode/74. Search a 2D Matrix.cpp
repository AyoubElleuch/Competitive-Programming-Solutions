class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // step 1: binary search to find the array 
        int left = 0;
        int right = matrix.size() -1;

        while(left<right){
            int pivot = left + (right - left + 1) / 2;
            
            if(matrix[pivot][0] <= target){
                left = pivot;
            }else{
                right = pivot - 1;
            }
        }

        // left == right, perform binary search in the array

        int arr = left;
        left = 0;
        right = matrix[arr].size() - 1;

        while(left<=right){
            int pivot = left + (right - left) /2;
            if(matrix[arr][pivot] == target) return true;

            if(matrix[arr][left] <= target && target <= matrix[arr][pivot]){
                right = pivot - 1;
            }else{
                left = pivot + 1;
            }
        }
        return false;
    }
};