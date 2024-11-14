class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        
        // Create a list of tuples (-ratio quantity, stores_assigned)
        priority_queue<tuple<double, int, int>> typeStorePairs;
        for (int quantity : quantities){
            typeStorePairs.push({(double)quantity, quantity, 1});
        }
        
        // Iterate over the remaining n - m stores
        for (int i = 0; i < n - m; ++i){
            // Pop the element with the maximum ratio
            auto [ratio, totalQuantitiesOfType, storesAssignedToType] = typeStorePairs.top();
            typeStorePairs.pop();
            
            // Calculate the new ratio after assigning one more store
            int newStoresAssignedToType = storesAssignedToType + 1;
            double newRatio = (double)totalQuantitiesOfType / newStoresAssignedToType;
            
            // Push the updated pair back into the heap
            typeStorePairs.push({newRatio, totalQuantitiesOfType, newStoresAssignedToType});
        }
        
        // Select the first element to get the final ratio
        auto [_, totalQuantities, storeAssigned] = typeStorePairs.top();
        
        // Return the maximum minimum ratio
        return ceil((double)totalQuantities / storeAssigned);
    }
};