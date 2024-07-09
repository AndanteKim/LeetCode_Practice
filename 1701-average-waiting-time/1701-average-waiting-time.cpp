class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), finishTime = 0;
        double total = 0.0;
        
        for (auto& customer : customers){
            int currArr = customer[0], currRequired = customer[1];
            if (currArr < finishTime)
                total += finishTime - currArr;
                
            int currTime = max(currArr, finishTime);
            total += currRequired;
            
            finishTime = currTime + currRequired;
        }
        
        return total / n;
    }
};