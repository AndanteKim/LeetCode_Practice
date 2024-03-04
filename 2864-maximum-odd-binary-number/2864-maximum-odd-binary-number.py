class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        arr = sorted(s)
        
        # Reverse order for the first N - 1 elements of the array
        # Because we want to keep a 1 at the last index
        # The last element of the array is index N - 1, the second the last is at N - 2
        second_last = len(arr) - 2
        for i in range(len(arr) // 2):
            arr[i], arr[second_last - i] = arr[second_last - i], arr[i]
            
        # Return result
        return "".join(arr)
        