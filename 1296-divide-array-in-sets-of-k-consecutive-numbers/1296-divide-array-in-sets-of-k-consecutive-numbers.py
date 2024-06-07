class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k != 0:
            return False
        
        # Count to store the count of each freq's value
        freq = Counter(nums)
        
        for num in nums:
            start = num
            
            # Find the start of the potential straight sequence
            while freq[start - 1] != 0:
                start -= 1
                
            # Process the sequence starting from start
            while start <= num:
                while freq[start]:
                    # Check if we can form a consecutive sequence of k
                    for nxt in range(start, start + k):
                        if freq[nxt] == 0:
                            return False
                        freq[nxt] -= 1
                start += 1
                
        return True