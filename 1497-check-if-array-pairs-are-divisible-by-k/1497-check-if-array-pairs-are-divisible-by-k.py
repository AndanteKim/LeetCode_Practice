class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        # Custom comparator to sort based on mod values
        arr.sort(key = lambda x: (k + x % k) % k)
        
        # Assign the pairs with modulo first.
        start, end = 0, len(arr) - 1
        
        while start < end:
            if arr[start] % k != 0:
                break
                
            if arr[start + 1] % k != 0:
                return False
            
            start += 2
        
        # Now, pick one element from the beginning and one element from the end.
        while start < end:
            if (arr[start] + arr[end]) % k != 0:
                return False
            start += 1
            end -= 1
        
        return True