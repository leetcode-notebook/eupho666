/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//https://leetcode-cn.com/problems/clone-graph/

// dfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> m;
        return dfs(m, node);
    }
    Node* dfs(map<Node*,Node*> &m, Node* node){
        if(node == nullptr || m.find(node) != m.end())
            return m[node];

        Node* n = new Node(node->val);
        m[node] = n;
        for(int i = 0;i < node->neighbors.size(); ++i){
            n->neighbors.push_back(dfs(m,node->neighbors[i]));
        }
        return n;
    }
};