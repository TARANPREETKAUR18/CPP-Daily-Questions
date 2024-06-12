class Solution {
public:
    bool condition(vector<int> &weights, int days, int mid) {
        int daysRequired = 1;
        int i = 0, sum = 0;
        while(i < weights.size()) {
            if(weights[i] + sum > mid) {
                daysRequired++;
                sum = weights[i];
            }
            else {
                sum += weights[i];
            }
            i++;
        }
        if(daysRequired <= days) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(),  weights.end()) - 1;
        int hi = accumulate(weights.begin(), weights.end(), 0), mid;
        while( lo + 1 < hi) {
            mid = lo + floor((hi - lo) / 2);
            if(condition(weights, days, mid)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        return hi;
    }
};

// w = [1, 2, 3, 1, 1], d = 4(upperlimit)

// 8 => 1
// 7 => 2
// 6 => 2
// 5 => 2 => (1, 2), (3, 1, 1)
// 4 => 3 => (1, 2), (3, 1), (1)
// 3 => 3
// 2 => not possible

// [f, f, t, t, t, t.....]
//        |
// minimization problem