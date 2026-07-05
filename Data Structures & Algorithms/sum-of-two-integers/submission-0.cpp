class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;

        for (int i = 0; i < 32; i++) {
            int bit1 = (a >> i) & 1;
            int bit2 = (b >> i) & 1;

            // Sum bit
            int sum = bit1 ^ bit2 ^ carry;
            res |= (sum << i);

            // Carry for next bit
            carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);
        }

        return res;
    }
};