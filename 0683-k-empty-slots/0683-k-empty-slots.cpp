class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        int ans = std::numeric_limits<int>::max();
        vector<int> days(n);

        for (int day = 0; day < n; ++day) days[bulbs[day] - 1] = day + 1;

        int left = 0, right = k + 1;
        while (right < n){
            bool found = true;
            for (int i = left + 1; i < right; ++i){
                if (days[i] < days[left] || days[i] < days[right]){
                    left = i; right = i + k + 1;
                    found = false;
                    break;
                }
            }
            
            if (found){
                ans = min(ans, max(days[left], days[right]));
                left = right; right = left + k + 1;
            }
        }

        return ans != std::numeric_limits<int>::max()? ans : -1;
    }
};