class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size(), i = 0;
        sort(s.begin(), s.end());
        int ans = 0, sum = 0;
        for(int i = 0;i<n;i++) sum+= s[i]*(i+1);
        for(int i = n-2;i>=0;i--) s[i]+=s[i+1];
        i = 0;
        while(i<n){
            ans = sum;
            sum-=s[i++];
            if(sum>ans) ans = sum;
            else break;
        }
        return ans;
    }
};