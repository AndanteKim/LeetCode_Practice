class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 0);
        
        for (int posL = 0; posL < n; ++posL){
            int posR = n - posL - 1;
            if (k > posR * 26){
                int add = k - (posR * 26);
                ans[posL] = ('a' + add - 1);
                k -= add;
            }
            else{
                ans[posL] = 'a';
                --k;
            }
        }
        
        return ans;
    }
};