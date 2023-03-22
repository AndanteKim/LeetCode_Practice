# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def get_hostname(self, url: str) -> str:
        return url.split('/')[2]
    
    def dfs(self, url: str, htmlParser: 'HtmlParser') -> None:
        self.visited.add(url)
        for next_url in htmlParser.getUrls(url):
            if self.get_hostname(next_url) == self.start_hostname and next_url not in self.visited:
                self.dfs(next_url, htmlParser)
    
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        
        self.start_hostname = self.get_hostname(startUrl)
        self.visited = set()
        
        self.dfs(startUrl, htmlParser)
        return self.visited