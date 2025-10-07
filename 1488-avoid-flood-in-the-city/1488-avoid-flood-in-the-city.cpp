class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> sunnyDay;
        unordered_map<int, int> fullLake;

        for (int day = 0; day < rains.size(); ++day){
            int rain = rains[day];
            if (rain == 0){
                sunnyDay.insert(day);
            }
            else{
                ans[day] = -1;
                if (fullLake.find(rain) != fullLake.end()){
                    auto it = sunnyDay.lower_bound(fullLake[rains[day]]);
                    if (it == sunnyDay.end()) return vector<int>{};
                    ans[*it] = rains[day];
                    sunnyDay.erase(it);
                }
                fullLake[rain] = day;
            }
        }

        return ans;
    }
};