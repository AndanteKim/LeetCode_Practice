class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size(), curr = k;
        vector<int> ans;
        int i = n;
        
        while (--i >= 0 || curr > 0){
            if (i >= 0) curr += num[i];
            ans.push_back(curr % 10);
            curr /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};