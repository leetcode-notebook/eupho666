class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        for(auto &s : strs){
            auto s1 = s;
            sort(s.begin(), s.end());
            map[s].push_back(s1);
        }
        for(auto &item: map){
            res.push_back(item.second);
        }
        return res;
    }
};