class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        N, skip = len(deck), False
        result = [0] * N
        index_in_deck, index_in_result = 0, 0
        deck.sort()
        
        while index_in_deck < N:
            # There is an available gap in result
            if result[index_in_result] == 0:
                
                # Add a card to result
                if not skip:
                    result[index_in_result] = deck[index_in_deck]
                    index_in_deck += 1
                    
                # Toggle skip to alternate between adding and skipping cars
                skip = not skip
                
            # Progress to the next index of result array
            index_in_result = (index_in_result + 1) % N
        
        return result
                