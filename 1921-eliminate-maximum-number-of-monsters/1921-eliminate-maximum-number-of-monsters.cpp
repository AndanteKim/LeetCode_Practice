class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> arrival;
        int ans = 0;
        for (int i = 0; i < dist.size(); ++i)
            arrival.push_back((float)dist[i] / speed[i]);
        
        sort(arrival.begin(), arrival.end());
        
        for (int day = 0; day < arrival.size(); ++day){
            if (arrival[day] <= day)
                break;
            ++ans;
        }
        
        return ans;
    }
};