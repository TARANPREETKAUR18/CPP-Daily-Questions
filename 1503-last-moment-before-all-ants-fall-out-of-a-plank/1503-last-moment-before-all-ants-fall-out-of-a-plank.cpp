class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() && right.size()){
            int ltime = *max_element(left.begin(), left.end());
            int rtime = *min_element(right.begin(), right.end());
            return max(ltime, n-rtime);
        }
        else if(left.size() == 0){
            int rtime = *min_element(right.begin(), right.end());
            return n-rtime;
        }
        else if(right.size()==0) return *max_element(left.begin(), left.end());
        return 0;
    }
};