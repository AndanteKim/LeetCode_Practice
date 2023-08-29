class Solution {
public:
    int bestClosingTime(string customers) {
        int currPenalty = 0, n = customers.size();
        int minPenalty = currPenalty, earliestHour = currPenalty;
        
        for (int i = 0; i < n; ++i){
            if (customers[i] == 'Y') --currPenalty;
            else ++currPenalty;
            
            if (currPenalty < minPenalty){
                earliestHour = i + 1;
                currPenalty = minPenalty;
            }
        }
        
        return earliestHour;
    }
};