class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxProfit1=0;
        int maxProfit2=0;
        int minPrice1=prices[0];
        int minPrice2=prices[0];
        if(n<=1) return 0;
        for(int i=0;i<n;i++){
            minPrice1=min(minPrice1,prices[i]);
            maxProfit1=max(maxProfit1,prices[i]-minPrice1);
            minPrice2=min(minPrice2,prices[i]-maxProfit1);
            maxProfit2=max(maxProfit2,prices[i]-minPrice2);
        }
        return maxProfit2;
    }
};