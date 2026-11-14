class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        // here we use multiset bcz set loses its duplicate but multiset dont 
        // EX : arr = { 3 , 3 , 2 } --> set = { 2, 3 } , multiset --> { 2 , 3, 3 } ;
        // set = unique + sorted
        // multiset = duplicates allowed + sorted
        multiset<int> s;
        int i = 0;
        int j = 0;
        while (j < n) {
            while (s.size() < k-1) {
                s.insert(nums[j]);
                j++;
            }
            s.insert(nums[j]);
            int maxi = *s.rbegin();
            ans.push_back(maxi);
            // here we erase by using s.erase(s.find(nums[i])) not only s.erase(nums[i]) bcz if we dont use s.find(nums[i]) then it removes all occurrences of nums[i]
            s.erase(s.find(nums[i]));
            i++;
            j++;
        }
        return ans;
        // T.C = O( NLOGK )
        // S.C = O(K) --> for multiset + O(N) --> for ans 
    }
};