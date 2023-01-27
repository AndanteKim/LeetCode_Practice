class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0, run_len = 1;
        
        for (int i = 1; i < arr.size(); ++i){
            if (arr[i-1] != arr[i]){
                if (arr[i-1] + 1 == arr[i]) {
                    cnt += run_len;
                }
                run_len = 0;
            }
            ++run_len;
        }
        return cnt;
    }
};