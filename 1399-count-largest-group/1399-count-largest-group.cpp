class Solution {
public:
    int countLargestGroup(int n) {
        int ans = 0, largest = 0;
        unordered_map<int, int> digitCount;
        
        for (int i = 1; i <= n; ++i){
            int s = 0, curr = i;
            while (curr > 0){
                s += curr % 10;
                curr /= 10;
            }
            ++digitCount[s];
            largest = max(digitCount[s], largest);
        }

        for (const auto& [k, v] : digitCount){
            if (v == largest) ++ans;
        }

        return ans;
    }
};