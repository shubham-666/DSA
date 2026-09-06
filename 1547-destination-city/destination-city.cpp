class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> source;

        // Store all cities having an outgoing path
        for (auto &path : paths) {
            source.insert(path[0]);
        }

        // Destination = city with no outgoing path
        for (auto &path : paths) {
            if (source.find(path[1]) == source.end()) {
                return path[1];
            }
        }

        return "";
    }
};