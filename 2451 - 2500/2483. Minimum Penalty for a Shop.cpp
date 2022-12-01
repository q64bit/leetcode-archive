class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        vector<int> bef(n, 0), aft(n, 0);
        
        bef[0] = 0;
        for(int i=1; i<n; i++)
            bef[i] = (customers[i-1] == 'N')? bef[i-1] + 1: bef[i-1];
        
        aft[n-1] = 0;
        for(int i=n-2; i>=0; i--)
            aft[i] = (customers[i+1] == 'Y')? aft[i+1] + 1: aft[i+1];
        
        int pen = (customers[0] == 'Y') + aft[0];
        int idx = 0;
        
        for(int i=0; i<n; i++) {
            if(bef[i] + aft[i] + (customers[i] == 'N') < pen) {
                pen = bef[i] + aft[i] + (customers[i] == 'N');
                idx = i+1;
            }
        }
        
        return idx;
    }
};
