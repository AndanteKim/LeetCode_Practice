class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int openPenalty = 0, closePenalty = 0;

        for (const int c : customers) {
            if (c == 'Y') ++closePenalty;
        }

        int ans = 0, currPenalty = openPenalty + closePenalty;

        for (int i = 0; i < n; ++i) {
            if (customers[i] == 'N') ++openPenalty;
            else --closePenalty;

            if (currPenalty > openPenalty + closePenalty) {
                ans = i + 1;
                currPenalty = openPenalty + closePenalty;
            }
        }
        
        return ans;
    }
};