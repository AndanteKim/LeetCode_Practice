class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count, last_one = 0, -1
        
        for i in range(len(flowerbed)):
            if not flowerbed[i]:
                count += 1
            else:
                n -= (count - (last_one != -1)) // 2
                count = 0
                last_one = i
        
        n -= (count + (last_one == -1)) // 2
        
        return n <= 0