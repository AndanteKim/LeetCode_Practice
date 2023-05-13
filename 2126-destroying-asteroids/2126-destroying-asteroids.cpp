class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long planet = mass;
        sort(asteroids.begin(), asteroids.end());
        
        for (int i = 0; i < asteroids.size(); ++i){
            if (planet < asteroids[i]) return false;
            planet += asteroids[i];
        }
        
        return true;
    }
};