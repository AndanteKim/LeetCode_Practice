class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int unrealizedCustomer = 0;
        
        // Calculate initial number of unrealized customers in the first 'minutes'
        // window
        for (int i = 0; i < minutes; ++i)
            unrealizedCustomer += customers[i] * grumpy[i];
        
        int maxUnrealizedCustomer = unrealizedCustomer;
        
        // Slide the 'minutes' window across the rest of the customers array 
        for (int i = minutes; i < customers.size(); ++i){
            // Add the current 'minute's unsatisfied customers if the owner is
            // grumpy and remove the customers that are out of the current
            // window
            unrealizedCustomer += customers[i] * grumpy[i];
            unrealizedCustomer -= customers[i - minutes] * grumpy[i - minutes];
            
            // Update the maximum unrealized customers
            maxUnrealizedCustomer = max(maxUnrealizedCustomer, unrealizedCustomer);
        }
        
        // Start with the maximum possible satisfied customers due to the secret
        // technique
        int ans = maxUnrealizedCustomer;
        
        // Add the satisfied customers during non-grumpy minutes
        for (int i = 0; i < customers.size(); ++i)
            ans += customers[i] * (1 - grumpy[i]);
        
        // Return the maximum nuumber of satisfied customers
        return ans;
    }
};