class Solution {
public:
    string frequencySort(string s) {
        vector<vector<char>> bucket(s.size()+1);
        unordered_map<char, int> frequency;

        for(char c : s){
            ++frequency[c];
        }

        for(const auto& element:frequency) bucket[element.second].push_back(element.first);

        string result = "";
        for(int i=s.size(); i>0; i--){
            for(char element : bucket[i]){
                for(int j=0; j<i; j++) result+=element;
            }
        }
        
        return result;
    }
};