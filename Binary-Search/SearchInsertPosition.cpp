/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int r = n - 1;
        int l = 0;
        int res;
        while (r >= l){
            if (A[l] >= target){
                return l;
            }
            if (A[r] < target){
                return r + 1;
            }
            res = (r + l) / 2;
            if (A[res] == target){
                return res;
            }else if (A[res] < target && A[res + 1] > target){
                return res + 1;
            }else if(A[res] < target){
                l = res + 1;
            }else{
                r = res - 1;
            }
            
        }
        return -1;
    }
};