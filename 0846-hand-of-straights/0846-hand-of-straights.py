class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand_size = len(hand)
        
        if hand_size % groupSize != 0:
            return False
        
        # Counter to store the count of each card value
        card_count = Counter(hand)
        
        # Min-heap to process the cards in sorted order
        min_heap = list(card_count.keys())
        heapify(min_heap)
        
        # Process the cards until the heap is empty
        while min_heap:
            curr_card = min_heap[0] # Get the smallest card value
            # Check each consecutive sequence of groupSize cards
            for i in range(groupSize):
                if card_count[curr_card + i] == 0:
                    return False
                card_count[curr_card + i] -= 1
                if card_count[curr_card + i] == 0:
                    if curr_card + i != heappop(min_heap):
                        return False
        
        return True