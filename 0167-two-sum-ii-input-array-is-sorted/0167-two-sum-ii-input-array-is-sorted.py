class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            left, right, second = i + 1, len(numbers) - 1, target - numbers[i]
            
            while left <= right:
                mid = (left + right) >> 1
                if numbers[mid] < second:
                    left = mid + 1
                elif numbers[mid] > second:
                    right = mid - 1
                else:
                    return [i + 1, mid + 1]
        
        return []