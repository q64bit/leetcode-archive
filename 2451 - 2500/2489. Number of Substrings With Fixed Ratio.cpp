class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        int n0 = num1, n1 = num2;
        
        unordered_map<int, int> mp; mp[0] = 1;
        
        int prefix = 0;
        long long res = 0;
        
        for(char ch: s) {
            if(ch == '0') prefix += n1;
            else prefix -= n0;
            
            res += mp[prefix];
            mp[prefix] += 1;
        }        
        return res;
    }
};
