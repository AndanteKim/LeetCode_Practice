class Solution:
    def remove_largest(self, stones: List[int]) -> int:
        index_of_largest = stones.index(max(stones))
        stones[index_of_largest], stones[-1] = stones[-1], stones[index_of_largest]
        return stones.pop()
    
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stone1 = self.remove_largest(stones)
            stone2 = self.remove_largest(stones)
            if stone1 != stone2:
                stones.append(stone1 - stone2)
        return stones[0] if stones else 0