class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int happy = 0;
        
        for (int i = 0; i < customers.size(); ++i)
            happy += customers[i] * (grumpy[i] ^ 1);
        
        int maxHappy = happy;
        
        for (int i = 0; i < customers.size(); ++i){
            if (i >= minutes && grumpy[i - minutes] == 1)
                happy -= customers[i - minutes];
            
            if (grumpy[i] == 1)
                happy += customers[i];
            
            maxHappy = max(maxHappy, happy);
        }
        
        return maxHappy;
    }
};