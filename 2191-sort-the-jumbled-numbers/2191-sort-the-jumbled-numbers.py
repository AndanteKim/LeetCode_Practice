class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        reflected = defaultdict(list)
        
        for num in nums:
            digits, order, origin = 0, 0, num
            
            while origin > 0:
                order += mapping[origin % 10] * (10 ** digits)
                origin //= 10
                digits += 1
            if num == 0:
                reflected[mapping[num]].append(num)
            else:
                reflected[order].append(num)
        
        return [val for k in sorted(reflected.keys()) for val in reflected[k]]