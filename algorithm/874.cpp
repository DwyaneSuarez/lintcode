class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        // Write your code here
        int n = flights.size();
        int k = days[0].size();
        vector<int> dp[2];
        for (int i = 0; i < 2; ++i) {
            dp[i].resize(n);
        }
        dp[0][0] = 0;
        for (int i = 1; i < n; ++i)
            dp[0][i] = -1;
        for (int i = 1; i <= k; ++i) {
            int cur = i & 1;
            for (int j = 0; j < n; ++j)
                dp[cur][j] = -1;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (flights[j][k] && dp[1 - cur][j] != -1) {
                        dp[cur][k] = max(dp[cur][k], dp[1 - cur][j] + days[k][i - 1]);
                    } else if (j == k && dp[1 - cur][j] != -1) {
                        dp[cur][k] = max(dp[cur][k], dp[1 - cur][j] + days[k][i - 1]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[k & 1][i]);
        return ans;
    }
};