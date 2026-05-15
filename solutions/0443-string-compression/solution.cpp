class Solution {
public:
    int compress(vector<char>& chars) {

        int idx = 0; // write index

        for (int i = 0; i < chars.size(); ) {

            char current = chars[i];
            int count = 0;

            // count frequency
            while (i < chars.size() && chars[i] == current) {
                i++;
                count++;
            }

            // write character
            chars[idx++] = current;

            // write count if > 1
            if (count > 1) {

                string s = to_string(count);

                for (char c : s) {
                    chars[idx++] = c;
                }
            }
        }

        return idx;
    }
};
