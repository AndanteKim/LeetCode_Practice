class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        vector<int> active; // Sorted array of bulbs
        int n = bulbs.size();

        for (int day = 0; day < n; ++day){
            int bulb = bulbs[day];

            // Find insertion point using lower_bound
            auto it = lower_bound(active.begin(), active.end(), bulb);

            // Check the right neighbor
            if (it != active.end() && abs(*it - bulb) - 1 == k) return day + 1;
        
            // Check left neighbor
            if (it != active.begin()){
                auto prev = std::prev(it);
                if (abs(*prev - bulb) - 1 == k) return day + 1;
            }

            // Insert at position
            active.insert(it, bulb);
        }

        return -1;
    }
};