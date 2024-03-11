class Solution{
public:
    int scheduleCourse(vector<vector<int>>& c){
        int n = c.size();
        sort(c.begin(), c.end(), [](vector<int> &a, vector<int> &b){ return a[1] < b[1]; });
        int ans = 0, day = 0;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            if(day + c[i][0] <= c[i][1]){
                ans++;
                pq.push(c[i][0]);
                day += c[i][0];
            }
            else{
                if (!pq.empty()){
                    if (day + c[i][0] - pq.top() <= c[i][1]&&day + c[i][0] - pq.top()<=day){
                        day = day - pq.top() + c[i][0];
                        pq.pop();
                        pq.push(c[i][0]);
                    }
                }            
            }
        }
        return ans;
    }
};