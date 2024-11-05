class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # Sort the folders alphabetically
        folder.sort()
        
        # Initialize the result list 
        res = [folder[0]]
        
        # Iterate through each folder and check if it's a sub-folder of the last added folder in the result
        for i in range(1, len(folder)):
            last_folder = res[-1]
            last_folder += '/'
            
            # Check if the current folder starts with the last added folder path
            if not folder[i].startswith(last_folder):
                res.append(folder[i])
                
        # Return the result containing only non-sub-folders
        return res