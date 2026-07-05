class Solution {
public:
    int reverse(int x) {
        long long a = llabs((long long)x);
        string s = to_string(a);
        ::reverse(s.begin(), s.end());

        long long z = stoll(s);
        long long y = (1LL << 31);

        if (z > y - 1)
            return 0;

        if (x < 0)
            z = -z;

        if (z < -y || z > y - 1)
            return 0;

        return (int)z;
    }
};