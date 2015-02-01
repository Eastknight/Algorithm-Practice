/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/



class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0;
        int r = n - 1;
        int mid;
        vector<int> res;
        while (r >= l){
            mid = (l + r) / 2;
            if (A[mid] == target){
                int st = mid - 1;
                int ed = mid + 1;
                while (st >= 0 && A[st] == target){
                    st--;
                }
                while (ed <= n - 1 && A[ed] == target){
                    ed++;
                }
                res.push_back(st + 1);
                res.push_back(ed - 1);
                return res;
            }else if (A[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};