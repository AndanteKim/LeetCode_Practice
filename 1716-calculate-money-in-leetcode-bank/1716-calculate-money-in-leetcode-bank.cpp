class Solution {
public:
    int totalMoney(int n) {
        int i = 0, ans = 0, start = 1, end = 7;
        
        while (i < n){
            if (i + 7 < n)
                ans += 7 * (start + end) / 2;
            else{
                ans += (n - i) * (2 * start + (n - i - 1)) / 2;
                break;
            }
            i += 7;
            ++start;
            ++end;
        }
        return ans;
    }
};