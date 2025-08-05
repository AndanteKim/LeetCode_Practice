class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = n;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (fruits[i] <= baskets[j]){
                    --ans;
                    baskets[j] = 0;
                    break;
                }
            }
        }

        return ans;
    }
};