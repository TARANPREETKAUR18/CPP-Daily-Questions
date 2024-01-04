class Solution{
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2){
        multiset<int> mp;
        for(int i=0; i<nums1.size(); i++) mp.insert(nums1[i]);
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            auto it=mp.upper_bound(nums2[i]);
            if(it!=mp.end()){
                ans.push_back(*(it));
                mp.erase(it);
            }
            else{
                ans.push_back(*(mp.begin()));
                mp.erase(mp.begin());
            }
        }
        return ans;
    }
};