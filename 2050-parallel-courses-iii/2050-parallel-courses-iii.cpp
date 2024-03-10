class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        for (const auto& relation : relations) {
            int prevCourse = relation[0];
            int nextCourse = relation[1];
            graph[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }
        queue<int> q;
        vector<int> earliestStart(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                earliestStart[i] = 0;
            }
        }
        int minTime = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            minTime = max(minTime, earliestStart[course] + time[course - 1]);
            for (int nextCourse : graph[course]) {
                indegree[nextCourse]--;
                earliestStart[nextCourse] = max(earliestStart[nextCourse], earliestStart[course] + time[course - 1]);
                if (indegree[nextCourse] == 0) q.push(nextCourse);
            }
        }
        return minTime;
    }
};