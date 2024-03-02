class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
        map<int, int> mp;
        for(auto &i: hand){
            mp[i]++;
            
        }
        int val;
        for(auto &i: mp){
            val = i.second;
            if(val){
                for(int temp = 0; temp < groupSize; temp++){
                    if(mp[i.first + temp] < val) return false;
                    mp[i.first + temp] -= val;
                }
            }
        }
        return true;
    }
};