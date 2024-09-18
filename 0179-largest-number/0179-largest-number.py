class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert each integer to a string
        num_str = [str(num) for num in nums]
        
        # Sort strings based on concatenated values
        num_str.sort(key = lambda x : x * 10, reverse = True)
        
        # Handle the case where the largest number is zero.
        if num_str[0] == '0':
            return "0"
        
        # Concatenate sorted strings to form the largest number
        return "".join(num_str)