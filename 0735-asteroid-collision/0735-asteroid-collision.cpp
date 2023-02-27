class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int asteroid : asteroids){
            bool isCollision = false;
            while (!st.empty() && st.back() > 0 && asteroid < 0){
                if (st.back() < -asteroid) {
                    st.pop_back();
                    continue;
                }
                else if (st.back() == -asteroid) st.pop_back();
                isCollision = true;
                break;
            }
            if (!isCollision) st.push_back(asteroid);
        }
        
        return st;
    }
};