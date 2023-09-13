class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, n = ratings.size();
        vector<int> left2right(n, 1), right2left(n, 1);
        
        for (int i = 1; i < n; ++i){
            if (ratings[i] > ratings[i - 1]) left2right[i] = left2right[i - 1] + 1;
        }
        
        for (int i = n - 2; i >= 0; --i){
            if (ratings[i] > ratings[i + 1]) right2left[i] = right2left[i + 1] + 1;
        }
        
        for (int i = 0; i < n; ++i){
            sum += max(left2right[i], right2left[i]);
        }
        return sum;
    }
};