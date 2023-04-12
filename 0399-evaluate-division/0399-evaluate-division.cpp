class Solution {
    unordered_map<string, pair<string,double>> GidWeight;
    
    pair<string, double> find(string& NodeId){
        if (GidWeight.find(NodeId) == GidWeight.end()) GidWeight[NodeId] = make_pair(NodeId, 1);
        auto [GroupId, NodeWeight] = GidWeight[NodeId];
        if (GroupId != NodeId){
            auto [NewGroupId, GroupWeight] = find(GroupId);
            GidWeight[NodeId] = make_pair(NewGroupId, NodeWeight * GroupWeight);
        }
        return GidWeight[NodeId];
    }
    
    void UnionSet(string& Dividend, string& Divisor, double value){
        auto [DividendGid, DividendWeight] = find(Dividend);
        auto [DivisorGid, DivisorWeight] = find(Divisor);
        if (DividendGid != DivisorGid) GidWeight[DividendGid] = make_pair(DivisorGid, DivisorWeight * value / DividendWeight);
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i){
            UnionSet(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        
        for (vector<string>& query : queries){
            if (GidWeight.find(query[0]) == GidWeight.end() || GidWeight.find(query[1]) == GidWeight.end()) ans.push_back(-1.0);
            else{
                auto [DividendGid, DividendWeight] = find(query[0]);
                auto [DivisorGid, DivisorWeight] = find(query[1]);
                if (DividendGid != DivisorGid) ans.push_back(-1.0);
                else ans.push_back(DividendWeight / DivisorWeight);
            }
        }
        return ans;
    }
};