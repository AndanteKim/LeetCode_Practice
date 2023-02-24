class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> possible;
        for (int i = 0; i < n; ++i){
            if (nums[i] % 2 == 0) {
                int temp = nums[i];
                possible.push_back({temp, i});
                while (temp % 2 == 0){
                    temp /= 2;
                    possible.push_back({temp, i});
                }
            }
            else{
                possible.push_back({nums[i], i});
                possible.push_back({nums[i] * 2 , i});
            }
        }
        sort(possible.begin(), possible.end());
        
        int min_deviation = INT_MAX, not_included = n, current_start = 0;
        vector<int> need_include(n, 1);
        
        for (auto &it : possible){
            --need_include[it.second];
            if (need_include[it.second] == 0) --not_included;
            
            if (not_included == 0){
                while (need_include[possible[current_start].second] < 0){
                    ++need_include[possible[current_start].second];
                    ++current_start;
                }
                if (min_deviation > it.first - possible[current_start].first)
                    min_deviation = it.first - possible[current_start].first;
                
                ++need_include[possible[current_start].second];
                ++current_start;
                ++not_included;
            }
        }
        
        return min_deviation;
    }
};