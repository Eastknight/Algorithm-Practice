class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0;
        int r = n - 1;
        int res;
        while (l <= r){
            res = (l + r) / 2;
            if (A[res] == target){
                return res;
            }
            if (A[res] < A[r]){
                if (target > A[res] && target <= A[r]){
                    l = res + 1;
                }else{
                    r = res - 1;
                }
            }else{
                if (target < A[res] && target >= A[l]){
                    r = res - 1;
                }else{
                    l = res + 1;
                }
            }
        }
        return -1;
    }
};