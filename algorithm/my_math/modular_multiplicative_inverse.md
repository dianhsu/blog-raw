@import "/mystyle.less"

## 乘法逆元
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---

```cpp
/**
 * @brief 乘法逆元
 * @date 2021/05/18
 *
 */
#include <bits/stdc++.h>


template<typename T>
class ExGcd {
public:
    /*
     * @brief 拓展欧几里得算法
     * @note 要求a和p的最大公约数是1
     */
    static T inv(T a, T p) {
        T x, y;
        if (step(a, p, x, y) != 1) // 无解的情形
            return -1;
        return (x % p + p) % p;
    }

private:
    static T step(T a, T b, T &x, T &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        T d = step(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
};

template<typename T>
class QPow {
public:
    /*
     * @brief 快速幂算法，根据费马小定理
     * @note 要求p是质数
     */
    static T inv(T a, T p) {
        return step(a, p - 2, p);
    }

private:
    static T step(T a, T n, T p) {
        T ans = 1;
        while (n) {
            if (n & 1)
                ans = ans % p * a % p;
            a = a % p * a % p;
            n >>= 1;
        }
        return ans;
    }
};

template<typename T>
class LinearInverse {
public:
    /*
     * @brief 批量求乘法逆元
     */
    static std::vector<T> build(int n, int p) {
        std::vector<T> inv(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            inv[i] = (long long) (p - p / i) * inv[p % i] % p;
        }
        return inv;
    }
};

int main() {
    int a = 2, p = 1000000007;
    std::cout << ExGcd<long long>::inv(a, p) << std::endl;
    std::cout << QPow<long long>::inv(a, p) << std::endl;
    auto vec = LinearInverse<long long>::build(10, p);
    for(auto it: vec){
        std::cout << it << std::endl;
    }
    return 0;
}
```