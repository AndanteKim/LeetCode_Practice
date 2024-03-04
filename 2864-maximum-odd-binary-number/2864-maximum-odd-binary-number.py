class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        # Get n and char arraay
        n, arr = len(s), [ch for ch in s]
        
        left, right = 0, n - 1
        while left <= right:
            
            # Increment left if equals 1
            if arr[left] == '1':
                left += 1
            
            # Decrement right if equals 0
            if arr[right] == '0':
                right -= 1
            
            # Swap if neither pointer can be iterated
            if left <= right and arr[left] == '0' and arr[right] == '1':
                arr[left], arr[right] = '1', '0'
                
        # Swap rightmost 1 bit to the end
        arr[left - 1], arr[n - 1] = '0', '1'
        
        return "".join(arr)
        