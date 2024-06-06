class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();
        if (handSize % groupSize != 0) return false;
        
        // Map to store the count of each card value
        map<int, int> cardCount;
        for (int h:hand) ++cardCount[h];
        
        // Process the cards until the map is empty
        while (!cardCount.empty()){
            // Get the smallest card value
            int currCard = cardCount.begin() -> first;
            
            // Check each consecutive sequence of groupSize cards            
            for (int i = 0; i < groupSize; ++i){
                // If a card is missing or has exhausted its occurrences                
                if (cardCount[currCard + i] == 0)
                    return false;
                
                --cardCount[currCard + i];
                if (cardCount[currCard + i] < 1){
                    // Remove the card value if its occurrences are exhausted
                    cardCount.erase(currCard + i);
                }
            }
        }
        
        return true;
    }
};