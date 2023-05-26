class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 0);
        
        for (int pos = n - 1; pos >= 0; --pos){
            int add = min(k - pos, 26);
            ans[pos] = 'a' + add - 1;
            k -= add;
        }
        
        return ans;
    }
};