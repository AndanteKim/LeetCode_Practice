/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string getHostname(string& url){
        int pos = min(url.size(), url.find('/', 7));
        return url.substr(7, pos - 7);
    }
    
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string startHostname = getHostname(startUrl);
        queue<string> *q = new queue<string>;
        q -> push(startUrl);
        unordered_set<string> *visited = new unordered_set<string>;
        visited -> insert(startUrl);
        while (!q -> empty()){
            string url = q -> front();
            q -> pop();
            for (string& next_url : htmlParser.getUrls(url)){
                if (getHostname(next_url) == startHostname && !visited -> count(next_url)){
                    q -> push(next_url);
                    visited -> insert(next_url);
                }
            }
        }
        
        return vector<string>(visited -> begin(), visited -> end());
    }
};