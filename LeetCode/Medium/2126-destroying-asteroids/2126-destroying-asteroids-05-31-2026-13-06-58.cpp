class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long curr = mass;

        for (int a : asteroids) {
            if (curr < a) return false;
            curr += a;
        }

        return true;
    }
};