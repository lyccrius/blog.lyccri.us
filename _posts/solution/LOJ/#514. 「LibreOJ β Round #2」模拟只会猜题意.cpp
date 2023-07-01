#include <iostream>

const int maxN = 1e4;
const int maxX = 1e4;
const int maxM = 1e5;
const int maxA = 1e4;
const int inf = maxN * maxA;

int n, m;
int x;
int a[maxN + 10];
int p[maxN + 10];
int f[maxX + 10];

int main() {
    std::fill(f, f + sizeof(f) / 4, - inf);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
    for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) f[r - l + 1] = std::max(f[r - l + 1], p[r] - p[l - 1]);
    for (int i = 1; i <= m; i++) {
        std::cin >> x;
        std::cout << f[x] << '\n';
    }
    return 0;
}