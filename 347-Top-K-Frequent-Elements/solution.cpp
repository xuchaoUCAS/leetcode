class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> result;
        for(auto n : nums)
            ++map[n];
            
        priority_queue<pair<int, int>> pq;
        for(auto it = map.begin(); it != map.end(); ++it){
            pq.push(make_pair(it->second, it->first));
        }
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};