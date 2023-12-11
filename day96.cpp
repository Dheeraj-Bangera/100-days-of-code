//799. champagne-tower
class Solution {

public:

    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> dp(query_row + 1, vector<double>(query_row  + 1, 0.0));

        dp[0][0] = static_cast<double>(poured);

        for(int glassRow = 0; glassRow < query_row; glassRow++){

            for(int glassCol = 0; glassCol <= glassRow ; glassCol++){

                double excess = (dp[glassRow][glassCol] - 1.0) / 2.0;

                if(excess > 0){

                    dp[glassRow + 1][glassCol] += excess;

                    dp[glassRow + 1][glassCol + 1] += excess;

                }

            }

        }

        return min(1.0, dp[query_row][query_glass]);

        

    }

};


        
    
