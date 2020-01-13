class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> g(n);
        iota(begin(g), end(g), 0);
        function<int(int)> find = [&](int x){
            return g[x] == x ? x : g[x] = find(g[x]);
        };
        for(const auto &e: pairs){
            g[find(e[0])] = find(e[1]);
        }
        vector<vector<int>> indexs(n);
        vector<string> ss(n);
        for(int i = 0;i < n; ++i){
            int id = find(i);
            indexs[id].push_back(i);
            ss[id].push_back(s[i]);
        }
        for(int i = 0;i < n;++i){
            sort(ss[i].begin(), ss[i].end());
            for(int j = 0;j < indexs[i].size(); ++j){
                s[indexs[i][j]] = ss[i][j];
            }
        }
        return s;
    }
};