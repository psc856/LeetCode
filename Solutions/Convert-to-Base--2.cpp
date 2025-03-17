class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans="";
        while (n != 0) {
            int remainder = n % -2; //quotient can be -ve and +ve depending on dividend
            n /= -2;

            if (remainder < 0) {
                remainder += 2; // Make the remainder positive
                n++; // Adjust n accordingly to maintain consistency
            }

            ans.push_back(remainder + '0'); // Convert int to char
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};