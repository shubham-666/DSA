class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        
        for (int i = 0; i < list1.size(); i++) {
            index[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int j = 0; j < list2.size(); j++) {
            if (index.count(list2[j])) {
                int sum = index[list2[j]] + j;

                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                }
                else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};