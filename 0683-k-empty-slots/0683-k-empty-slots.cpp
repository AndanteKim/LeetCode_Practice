
class Solution {
public:
    int kEmptySlots(std::vector<int>& bulbs, int k) {
        std::set<int> active;  // keeps the bulb in sorted order
        int n = bulbs.size();

        for (int day = 0; day < n; ++day) {
            int bulb = bulbs[day];
            
            // Insert current bulb
            auto it = active.insert(bulb).first;
            
            // Check the right neighbor
            auto next = std::next(it);
            if (next != active.end() && abs(*next - bulb) - 1 == k) {
                return day + 1;  // day is 0-based in C++, add 1
            }
            
            // Check the left neighbor
            if (it != active.begin()) {
                auto prev = std::prev(it);
                if (abs(*prev - bulb) - 1 == k) {
                    return day + 1;
                }
            }
        }
        
        return -1;
    }
};