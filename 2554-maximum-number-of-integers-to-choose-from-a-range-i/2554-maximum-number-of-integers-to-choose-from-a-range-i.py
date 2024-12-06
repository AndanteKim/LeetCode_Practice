class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        def custom_bin_search(target: int) -> bool:
            left, right = 0, len(banned) - 1
            
            while left <= right:
                mid = (left + right) // 2
                
                if banned[mid] == target:
                    return True
                elif banned[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
                    
            return False
        
        # Sort banned array to enable binary search
        banned.sort()
        count = 0
        
        # Try each number from 1 to n
        for num in range(1, n + 1):
            # Skip if number is in banned array
            if custom_bin_search(num):
                continue
                
            maxSum -= num
            
            # Break if sum exceeds our limit
            if maxSum < 0:
                break
            
            count += 1
        
        return count