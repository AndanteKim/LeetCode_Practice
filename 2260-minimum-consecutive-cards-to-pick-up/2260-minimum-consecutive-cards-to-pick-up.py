class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        freq_cards = Counter(cards)
        location_cards = defaultdict(list)
        for i, card in enumerate(cards):
            location_cards[card].append(i)
        
        min_val = float('inf')
        for card in cards:
            if freq_cards[card] >= 2:
                location_a_card = location_cards[card]
                for i in range(len(location_a_card)-1):
                    min_val = min(min_val, location_a_card[i+1] - location_a_card[i]+1)
        return -1 if min_val == float('inf') else min_val
