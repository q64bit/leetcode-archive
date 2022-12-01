class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> r0(row, 0), r1(row, 0), c0(col, 0), c1(col, 0);
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                r0[i] += (grid[i][j] == 0);
                r1[i] += (grid[i][j] == 1);
            }
        }
        
        for(int j=0; j<col; j++) {
            for(int i=0; i<row; i++) {
                c0[j] += (grid[i][j] == 0);
                c1[j] += (grid[i][j] == 1);
            }
        }
        
        vector<vector<int>> diff(row, vector<int>(col));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                diff[i][j] = r1[i] + c1[j] - r0[i] - c0[j]; 
            }
        }
        
        return diff;
    }
};
