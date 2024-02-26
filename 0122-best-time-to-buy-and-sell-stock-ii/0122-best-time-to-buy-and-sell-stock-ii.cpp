class Solution {
public:
    int maxProfitMain(vector<int> &prices, int size, bool buy, vector<vector<int>> &cache){
        if(size==1)return buy?-prices[0]:0;
        if(cache[size-1][buy]!=-1) return cache[size-1][buy];
        if(buy == true){
            return cache[size-1][buy] = max(maxProfitMain(prices, size-1, false, cache) - prices[size-1], maxProfitMain(prices, size-1, true, cache));
        }
        return cache[size-1][buy] = max(maxProfitMain(prices, size-1, false, cache), maxProfitMain(prices, size-1, true, cache)+prices[size-1]);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> cache(prices.size(), vector<int>(2, -1));
        return maxProfitMain(prices, prices.size(), false, cache);
    }
};