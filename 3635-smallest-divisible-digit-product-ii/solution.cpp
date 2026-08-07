

class Solution {
    struct FactorCount {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    FactorCount getDigitFactors(char ch) {
        int d = ch - '0';
        FactorCount fc;
        if (d == 2) fc.c2 = 1;
        else if (d == 3) fc.c3 = 1;
        else if (d == 4) fc.c2 = 2;
        else if (d == 5) fc.c5 = 1;
        else if (d == 6) { fc.c2 = 1; fc.c3 = 1; }
        else if (d == 7) fc.c7 = 1;
        else if (d == 8) fc.c2 = 3;
        else if (d == 9) fc.c3 = 2;
        return fc;
    }

    // Constructs the minimal sorted digit suffix required to fulfill the missing prime factors
    string getRequiredDigits(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        string res = "";
        for (int i = 0; i < c7; ++i) res += '7';
        for (int i = 0; i < c5; ++i) res += '5';

        int count9 = c3 / 2;
        int rem3 = c3 % 2;
        for (int i = 0; i < count9; ++i) res += '9';

        int count8 = c2 / 3;
        int rem2 = c2 % 3;
        for (int i = 0; i < count8; ++i) res += '8';

        if (rem2 == 1 && rem3 == 0) res += '2';
        else if (rem2 == 2 && rem3 == 0) res += '4';
        else if (rem2 == 0 && rem3 == 1) res += '3';
        else if (rem2 == 1 && rem3 == 1) res += '6';
        else if (rem2 == 2 && rem3 == 1) { res += '2'; res += '6'; }

        sort(res.begin(), res.end());
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Factorize t into powers of 2, 3, 5, 7
        int target2 = 0, target3 = 0, target5 = 0, target7 = 0;
        long long temp = t;
        while (temp % 2 == 0) { temp /= 2; target2++; }
        while (temp % 3 == 0) { temp /= 3; target3++; }
        while (temp % 5 == 0) { temp /= 5; target5++; }
        while (temp % 7 == 0) { temp /= 7; target7++; }

        if (temp > 1) return "-1"; // Prime factor > 7 exists

        int n = num.size();

        // Step 2: Find the first occurrence of '0' in num
        int first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // Step 3: Compute remaining needed prime factors for each prefix of num
        vector<int> pref2(n + 1, target2), pref3(n + 1, target3), pref5(n + 1, target5), pref7(n + 1, target7);
        for (int i = 0; i < first_zero; ++i) {
            FactorCount fc = getDigitFactors(num[i]);
            pref2[i + 1] = max(0, pref2[i] - fc.c2);
            pref3[i + 1] = max(0, pref3[i] - fc.c3);
            pref5[i + 1] = max(0, pref5[i] - fc.c5);
            pref7[i + 1] = max(0, pref7[i] - fc.c7);
        }

        // Check if original num itself is zero-free and valid
        if (first_zero == n) {
            if (pref2[n] == 0 && pref3[n] == 0 && pref5[n] == 0 && pref7[n] == 0) {
                return num;
            }
        }

        // Step 4: Try replacing digit at position i (from right to left) with a larger digit
        int max_i = min(n - 1, first_zero);
        for (int i = max_i; i >= 0; --i) {
            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                FactorCount fc = getDigitFactors(d + '0');
                int rem2 = max(0, pref2[i] - fc.c2);
                int rem3 = max(0, pref3[i] - fc.c3);
                int rem5 = max(0, pref5[i] - fc.c5);
                int rem7 = max(0, pref7[i] - fc.c7);

                string req = getRequiredDigits(rem2, rem3, rem5, rem7);
                int space = n - 1 - i;

                if ((int)req.size() <= space) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += string(space - req.size(), '1');
                    ans += req;
                    return ans;
                }
            }
        }

        // Step 5: If no length-n string works, increase length to fit required digits
        string req = getRequiredDigits(target2, target3, target5, target7);
        int target_len = max(n + 1, (int)req.size());

        return string(target_len - req.size(), '1') + req;
    }
};
