class Solution {
public:
    int bestClosingTime(string customers) {
        int minPenalty = count(customers.begin(), customers.end(), 'Y'), earliestHours = 0;
        int currPenalty = minPenalty, n = customers.size();
        
        for (int i = 0; i < n; ++i){
            if (customers[i] == 'Y') --currPenalty;
            else ++currPenalty;
            
            if (currPenalty < minPenalty){
                earliestHours = i + 1;
                minPenalty = currPenalty;
            }
        }
        
        return earliestHours;
    }
};