//1631. Path With Minimum Effort
class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> visited; 
    int to1D(int i, int j) {
        return i*m +j;
    }

    bool dfs(int idx, int& maxEffort, int maxD, vector<vector<int>>& heights) {
        if (idx == n*m-1) return 1;
        auto [i, j] = div(idx, m);
     
        visited[idx] = 1;

      
        bool result=0;

        
        for (auto& di : dir) {
            int r = i + di[0], s = j + di[1];
            if (r < 0 || r >= n || s < 0 || s >= m || visited[to1D(r, s)]) continue;

            int w = abs(heights[i][j] - heights[r][s]);
            if (w <= maxD) {
                maxEffort = max(maxEffort, w);
                result = result || dfs(to1D(r, s), maxEffort, maxD, heights);

               
                if (result) return 1;
            }
        }
        return result;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        if (n == 1 && m == 1) return 0; 
        visited.assign(n*m, 0); 
        int maxEffort = 0;
        dfs(0, maxEffort, INT_MAX, heights);
        int l = 0, r=maxEffort;
        int result=-1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            visited.assign(n*m, 0);

            if (dfs(0, maxEffort, mid, heights)) {
                result = mid;
                r = mid-1;
            } 
            else 
                l = mid+1;
        }
        return result;
    }
};
