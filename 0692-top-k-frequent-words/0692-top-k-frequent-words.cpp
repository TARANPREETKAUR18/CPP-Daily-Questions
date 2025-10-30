class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        //step-1: (store the frequency)
        for(auto &it: words){
            mp[it]++;
        }

        vector<pair<string, int>> vec;

        //step-2: (populate the vector with {word, freq.})
        for(auto &it: mp){
            vec.push_back({it.first, it.second});
        }

        //step-3: (sort the vector using comparator)
        auto lambda = [](pair<string, int> p1, pair<string, int> p2){
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        //step-4: (pick top-K)
        int i = 0;
        vector<string> result(k);
        while(i < k){
            result[i] = vec[i].first;
            i++;
        }

        return result;
    }
};