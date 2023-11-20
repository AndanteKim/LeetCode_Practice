class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        time, count_type = 0, dict()
        for dummy in garbage:
            for trash_type in dummy:
                count_type[trash_type] = count_type.get(trash_type, 0) + 1
        
        for truck in count_type:
            curr = 0
            for i in range(len(garbage)):
                for trash in garbage[i]:
                    if trash == truck:
                        curr += 1
                        count_type[trash] -= 1
                if count_type[truck] == 0:
                    break
                if i < len(travel):
                    curr += travel[i]
            time += curr
            
        return time