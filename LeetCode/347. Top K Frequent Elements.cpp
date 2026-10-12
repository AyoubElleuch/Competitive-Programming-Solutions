class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int, int> frequency;

        for(int num : nums){
            ++frequency[num];
        }

        for(const auto& element: frequency) bucket[element.second].push_back(element.first);
        
        vector<int> result;
        for(int i=nums.size(); i>=0; i--){
            for(int element : bucket[i]){
                result.push_back(element);
                if(result.size() == k) return result;
            }
        }

        return result;
    }
};