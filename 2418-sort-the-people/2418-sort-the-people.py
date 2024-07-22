class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        n = len(names)
        
        # Create a dictionary to store height-name pairs
        height_to_name = dict(zip(heights, names))
        
        sorted_heights = sorted(heights, reverse = True)
        
        # Create a list of sorted names based on descending heights
        sorted_names = [height_to_name[height] for height in sorted_heights]
        
        return sorted_names