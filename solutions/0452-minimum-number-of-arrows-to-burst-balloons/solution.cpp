class Solution {
public:
    // Sort by end coordinates to always burst balloons at their earliest exit point
    static bool smaller(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0; // Edge case: No balloons

        // Sort the balloons
        sort(points.begin(), points.end(), smaller);

        int arrows = 1; // We need at least 1 arrow if points is not empty
        int current_end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            // If the current balloon starts AFTER the last arrow's range
            if (points[i][0] > current_end) {
                arrows++;
                current_end = points[i][1]; // Update the arrow position to this balloon's end
            }
        }

        return arrows;
    }
};
