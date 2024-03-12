class Solution{
public:
    int minSwapsCouples(vector<int>& row){
        int n = size(row);
        int ans = 0;
        vector<int> vis(n,0);
        unordered_map<int,int> m;
        for(int i=0;i<n;++i) m[row[i]] = i;
        for(int i=0;i<n;i+=2){
            if(!vis[i]){
                int pa = i;
                int pb = -1;
                int loopEdge = 0;
                while(!vis[pa]){
                    if(row[pa]%2==0) pb = m[row[pa]+1];
                    else pb = m[row[pa]-1];
                    vis[pa] = vis[pb] = 1;
                    pa = pb;
                    pb = -1;
                    if(pa%2==0) ++pa;
                    else --pa;
                    ++loopEdge;
                }
                ans += loopEdge-1;
            }
        }
        return ans;
    }
};