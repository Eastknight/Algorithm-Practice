/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Write a function to determine if a given target is in the array.
*/


class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0;
        int r = n - 1;
        int m;
        while (l <= r){
            m = (l + r) / 2;
            if (A[m] == target){
                return true;
            }
          //  4 5 6 7 4 1 4 4 4 4
            if (A[m] < A[r]){
                if (target <= A[r] && target > A[m]){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else if (A[m] > A[r]){
                if (target >= A[l] && target < A[m]){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }else{
                r--;
            }
        }
        return false;
    }
};