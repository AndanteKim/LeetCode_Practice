class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), cnt = 0, prev = -1;
        
        for (int i = 0; i < n; ++i){
            if (prev == -1 || arr[i] == prev)
                ++cnt;
            else
                cnt = 1;
            prev = arr[i];
            if ((double)cnt / n > 0.25)
                return arr[i];
        }
        
        return -1;
    }
};