class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int asteroid : asteroids){
            bool isDestroyed = false;
            while (!ans.empty() && ans.back() > 0 && asteroid < 0){
                if (abs(asteroid) > ans.back()) ans.pop_back();
                else{
                    isDestroyed = true;
                    if (asteroid + ans.back() == 0) ans.pop_back();
                    break;
                }
            }
            
            if (!isDestroyed) ans.push_back(asteroid);
        }
        
        return ans;
    }
};