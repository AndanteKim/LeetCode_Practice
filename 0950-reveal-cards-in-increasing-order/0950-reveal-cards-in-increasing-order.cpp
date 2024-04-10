class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        vector<int> result(N);
        int indexInResult = 0, indexInDeck = 0;
        bool skip = false;
        sort(deck.begin(), deck.end());
        
        // 
        while (indexInDeck < N){
            // There is an available gap in result
            if (result[indexInResult] == 0){
                // Add a card to result
                if (!skip){
                    result[indexInResult] = deck[indexInDeck++];
                }
                
                // Toggle skip to alternate between adding and skipping cards
                skip = !skip;
            }
            
            // Progress to the next index of the result array
            indexInResult = (indexInResult + 1) % N;
        }
        
        return result;
    }
};