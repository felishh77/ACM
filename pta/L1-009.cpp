#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n;
    scanf("%d", &n);

    ll sum_t = 0, sum_b = 1;  // 和的分子和分母

    for (int i = 0; i < n; i++) {
        ll t, b;
        scanf("%lld/%lld", &t, &b);

        // 通分：sum = sum + t/b
        ll new_b = sum_b * b / gcd(sum_b, b);                  // 新的分母
        ll new_t = sum_t * (new_b / sum_b) + t * (new_b / b);  // 新的分子

        sum_t = new_t;
        sum_b = new_b;

        // 约分
        ll g = gcd(abs(sum_t), sum_b);
        sum_t /= g;
        sum_b /= g;
    }

    // 输出结果
    if (sum_t == 0) {
        printf("0\n");
    } else {
        ll integer_part = sum_t / sum_b;
        ll remainder = sum_t % sum_b;

        if (integer_part != 0 && remainder != 0) {
            printf("%lld %lld/%lld\n", integer_part, abs(remainder), sum_b);
        } else if (integer_part != 0) {
            printf("%lld\n", integer_part);
        } else {
            printf("%lld/%lld\n", remainder, sum_b);
        }
    }

    return 0;
}