class Solution {
public:
    int kthGrammar(int N, int K) {
        return N == 1? 0 : !kthGrammar(N-1, K+1 >> 1) ^ (K & 1);
    }
};