class Solution {
public:
    int sqrt(int x) {
        if (x < 0){
            return -1;
        }
        if (x == 0 || x == 1){
            return x;
        }
        int l = 1;
        int r = x/2;
        int res;
        while (r >= l){
            res = (r + l) / 2;
            if (res <= x / res && (res+1) > x / (res+1)){
                return res;
            }else if (res > x / res){
                r = res - 1;
            }else{
                l = res + 1;
            }
        }
        return -1;
    }
};