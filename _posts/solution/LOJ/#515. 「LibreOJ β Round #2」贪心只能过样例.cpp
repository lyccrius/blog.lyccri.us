#include <iostream>
#include <bitset>

const int maxN = 100;
const int maxA = 100;

int n;
int a[maxN + 10], b[maxN + 10];
std::bitset<maxN * maxA * maxA + 10> f[maxN + 10];

int main() {
    f[0][0] = true;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) for (int x = a[i]; x <= b[i]; x++) f[i] |= (f[i - 1] << (x * x));
    std::cout << f[n].count() << '\n';
    return 0;
}