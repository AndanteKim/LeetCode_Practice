class Solution {
private:
    int n;
    int countIncreasing(int currIndex, int teamSize, const vector<int>& rating, vector<vector<int>>& increasingCache){
        // Base case: reached end of array
        if (currIndex == n)
            return 0;
        
        // Base case: found a valid team of size 3
        if (teamSize == 3)
            return 1;
        
        // Return cached result if available
        if (increasingCache[currIndex][teamSize] != -1)
            return increasingCache[currIndex][teamSize];
        
        int validTeams = 0;
        // Recursively count teams with increasing ratings
        for (int nextIndex = currIndex + 1; nextIndex < n; ++nextIndex){
            if (rating[currIndex] < rating[nextIndex])
                validTeams += countIncreasing(nextIndex, teamSize + 1, rating, increasingCache);
        }
        
        // Cache and return the result
        return increasingCache[currIndex][teamSize] = validTeams;
    }
    
    int countDecreasing(int currIndex, int teamSize, const vector<int>& rating, vector<vector<int>>& decreasingCache){
        // Base case: reached end of array
        if (currIndex == n) return 0;
        
        // Base case: found a valid team size 3
        if (teamSize == 3) return 1;
        
        // Return cached result if available
        if (decreasingCache[currIndex][teamSize] != -1)
            return decreasingCache[currIndex][teamSize];
        
        int validTeams = 0;
        // Recursively count teams with decreasing ratings
        for (int nextIndex = currIndex + 1; nextIndex < n; ++nextIndex){
            if (rating[currIndex] > rating[nextIndex])
                validTeams += countDecreasing(nextIndex, teamSize + 1, rating, decreasingCache);
        }
        
        return decreasingCache[currIndex][teamSize] = validTeams;
    }
    
public:
    int numTeams(vector<int>& rating) {
        this -> n = rating.size();
        vector increasingCache(n, vector<int>(4, -1)), decreasingCache(n, vector<int>(4, -1));
        
        int teams = 0;
        for (int startIndex = 0; startIndex < n; ++startIndex){
            teams += countIncreasing(startIndex, 1, rating, increasingCache) + countDecreasing(startIndex, 1, rating, decreasingCache);
        }
        
        return teams;
    }
};