class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        dic = {A_i : B_i for A_i, B_i in paths}
        
        current_location = paths[0][0]
        while current_location in dic.keys():
            current_location = dic[current_location]
        return current_location