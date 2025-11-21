class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ_map;

        for(int i=0; i<arr.size(); i++){
            occ_map[arr[i]]++;
        }

        set<int> st;

        for(auto &it: occ_map){
            st.insert(it.second);
        }

        return st.size() == occ_map.size();
    }
};