class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = sum(data)
        cnt_one = max_one = 0
        left = 0

        for right in range(len(data)):
            # Updating the number of 1's by adding the new element
            cnt_one += data[right]
            right += 1

            # Maintain the length of the window to ones
            if right - left > ones:
                # updating the number of 1's by removing the oldest element
                cnt_one -= data[left]
                left += 1
            
            # Record the maximum number of 1's in the window
            max_one = max(max_one, cnt_one)
        
        return ones - max_one
        