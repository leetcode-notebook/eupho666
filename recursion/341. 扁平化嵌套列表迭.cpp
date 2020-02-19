/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    queue<int> q;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = 0;i < nestedList.size();++i)
            dfs(nestedList[i]);  
    }
    void dfs(const NestedInteger &nest){
        if(nest.isInteger()){
            q.push(nest.getInteger());
        }else{
            auto subList = nest.getList();
            for(int i = 0;i < subList.size();++i){
                dfs(subList[i]);
            }
        }
    }

    int next() {
        if(!q.empty()){
            int res = q.front();
            q.pop();
            return res;
        }
        return -1;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */