class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000, mid = 0b11000011, right = 0b00001111;
        unordered_map<int, int> occupied;

        for (const auto& seats : reservedSeats) {
            if (2 <= seats[1] && seats[1] <= 9) {
                occupied[seats[0]] |= (1 << (seats[1] - 2));
            }
        }

        int ans = (n - occupied.size()) * 2;

        for (const auto& [row, bitmask] : occupied) {
            if (((bitmask | left) == left) || ((bitmask | mid) == mid) || ((bitmask | right) == right)) ++ans;
        }
        
        return ans;
    }
};