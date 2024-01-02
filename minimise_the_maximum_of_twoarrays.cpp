#include <iostream>
#include <climits>

#define ll long long

using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        if (!b)
            return a;
        return gcd(b, a % b);
    }

    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int low = 1, right = INT_MAX, LCM = lcm(divisor1, divisor2);

        while (low <= right) {
            int mid = low + (right - low) / 2;
            int a = mid / divisor1, b = mid / divisor2;
            if (uniqueCnt1 <= mid - a && uniqueCnt2 <= mid - b && uniqueCnt1 + uniqueCnt2 <= (mid - (mid / LCM))) {
                right = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    int divisor1 = 3, divisor2 = 5, uniqueCnt1 = 4, uniqueCnt2 = 2;

    int result = sol.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    
    cout << "Minimum set size required: " << result << endl;

    return 0;
}
