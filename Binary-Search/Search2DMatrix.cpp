/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int up = 0;
        int down = rows - 1;
        int left = 0;
        int right = cols - 1;
        int mid_row;
        int mid_col;
        while (up <= down){
            mid_row = (up + down) / 2;
            if (matrix[mid_row][0] <= target && matrix[mid_row][cols - 1] >= target){
                break;
            }else if (matrix[mid_row][0] > target){
                down = mid_row - 1;
            }else{
                up = mid_row + 1;
            }
        }
        if (up > rows - 1 || down < 0){
            return false;
        }
        while (left <= right){
            mid_col = (left + right) / 2;
            if (matrix[mid_row][mid_col] == target){
                return true;
            }else if (matrix[mid_row][mid_col] > target){
                right = mid_col - 1;
            }else{
                left = mid_col + 1;
            }
        }
        return false;
    }
};