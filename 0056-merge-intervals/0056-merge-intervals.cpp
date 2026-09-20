class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals)); //on the basis of start point
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            //if no overlap
            if(curr_start > result.back()[1]) result.push_back(intervals[i]);
            else result.back()[1] = max(result.back()[1], curr_end); //there is an overlap
        }
        return result;
    }
};