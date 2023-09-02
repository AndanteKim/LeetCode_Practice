class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        
        for i in range(len(flowerbed)):
            # check if the current plot is empty:
            if not flowerbed[i]:
                # check if the left and right plots are empty
                empty_left_plot = (i == 0) or (flowerbed[i - 1] == 0)
                empty_right_plot = (i == len(flowerbed) - 1) or (flowerbed[i + 1] == 0)
                
                # If both plots are empty, we can plant a flower here
                if empty_left_plot and empty_right_plot:
                    flowerbed[i] = 1
                    count += 1
        
        return count >= n