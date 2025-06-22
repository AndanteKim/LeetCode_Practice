
class Solution {
public:
    int kEmptySlots(std::vector<int>& flowers, int k) {
        std::set<int> active;  // keeps the flowers in sorted order
        
        for (int day = 0; day < flowers.size(); ++day) {
            int flower = flowers[day];
            
            // Insert current flower
            auto it = active.insert(flower).first;
            
            // Check the right neighbor
            auto next = std::next(it);
            if (next != active.end() && abs(*next - flower) - 1 == k) {
                return day + 1;  // day is 0-based in C++, add 1
            }
            
            // Check the left neighbor
            if (it != active.begin()) {
                auto prev = std::prev(it);
                if (abs(*prev - flower) - 1 == k) {
                    return day + 1;
                }
            }
        }
        
        return -1;
    }
};