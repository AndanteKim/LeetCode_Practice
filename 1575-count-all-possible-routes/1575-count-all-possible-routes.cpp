class Solution {
private:
    int n;
    int solve(vector<int>& locations, int currCity, int finish, int remainingFuel, vector<vector<int>>& memo){
        if (remainingFuel < 0) return 0;
        if (memo[currCity][remainingFuel] != -1) return memo[currCity][remainingFuel];
        
        int ans = currCity == finish? 1: 0;
        for (int nextCity = 0; nextCity < n; ++nextCity){
            if (nextCity != currCity){
                ans = (ans + solve(locations, nextCity, finish, remainingFuel - abs(locations[currCity] - locations[nextCity]), memo)) % 1'000'000'007;
            }
        }
        
        return memo[currCity][remainingFuel] = ans;
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        this -> n = locations.size();
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));
        
        return solve(locations, start, finish, fuel, memo);
    }
};