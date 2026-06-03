class Solution {
private:
    int solve(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2) {
        int f1 = std::numeric_limits<int>::max();
        for (int i = 0; i < s1.size(); ++i)
            f1 = min(f1, s1[i] + d1[i]);

        int f2 = std::numeric_limits<int>::max();
        for (int i = 0; i < s2.size(); ++i)
            f2 = min(f2, max(f1, s2[i]) + d2[i]);

        return f2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landToWater = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterToLand = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landToWater, waterToLand);
    }
};