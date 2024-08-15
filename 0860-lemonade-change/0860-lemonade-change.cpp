class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> currencies(3);
        unordered_map<int, int> mappingIndexToDollars{{0, 5}, {1, 10}, {2, 20}}, mappingDollarsToIndex{{5, 0}, {10, 1}, {20, 2}};
        
        for (int i = 0; i < bills.size(); ++i){
            int change = bills[i] - 5;
            
            for (int curr = 2; curr >= 0 && change > 0; --curr){
                int units = min(change / mappingIndexToDollars[curr], currencies[curr]);
                change -= mappingIndexToDollars[curr] * units;
                currencies[curr] -= units;
            }
            
            if (change > 0) return false;
            ++currencies[mappingDollarsToIndex[bills[i]]];
            
        }
        
        return true;
    }
};