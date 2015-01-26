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