class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        values_list = []
        for value in Counter(arr).values():
            values_list.append(value)
        
        return True if len(set(values_list)) == len(values_list) else False