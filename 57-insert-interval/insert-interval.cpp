
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Phase 1: Add all intervals that come strictly before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Phase 2: Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Append the fully merged newInterval
        result.push_back(newInterval);
        
        // Phase 3: Add all remaining intervals that come strictly after newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};