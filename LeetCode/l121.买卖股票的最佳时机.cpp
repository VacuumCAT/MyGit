class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int b=INT_MAX,ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>=b) ans=max(ans,prices[i]-b);
            else b=prices[i];
        }
        return ans;

    }
};