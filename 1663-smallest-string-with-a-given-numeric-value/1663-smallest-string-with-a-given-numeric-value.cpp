class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        
        for (int pos = n - 1; pos >= 0 && k > 0; --pos){
            int add = min(k, 25);
            ans[pos] = ans[pos] + add;
            k -= add;
        }
        
        return ans;
    }
};