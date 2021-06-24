
---
toc:
    depth_from: 1
    depth_to: 4
title: 随机数 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 随机数
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

[TOC]
---



### 模板
> 来源：[https://blog.csdn.net/x356982611/article/details/50909142](https://blog.csdn.net/x356982611/article/details/50909142)

```cpp
#include <random>
#include <memory>
#include <iostream>
using namespace std;
class Random {
public:
    const static unsigned maxRand = std::random_device::max();
    static Random& getInstance() {
        static Random instance;
        return instance;
    }
    unsigned int getInteger() noexcept {
        return (*dist)(rd);
    }
    unsigned int GetMTEngineInteger() noexcept {
        return (*mtEngine)();
    }
    uint64_t  GetMTEngine64Integer() noexcept {
        return (*mtEngine64)();
    }
    unsigned int  GetRand0Integer() noexcept {
        return (*rand0Engine)();
    }
    auto GetRanlux48Integer() noexcept ->decltype(auto) {
        return (*ranlux48Engine)();
    }
private:
    Random() noexcept {
        mtEngine = std::make_shared<std::mt19937>(rd());
        mtEngine64 = std::make_shared<std::mt19937_64>(rd());
        dist = std::make_shared<std::uniform_int_distribution<unsigned>>(std::uniform_int_distribution< unsigned int >(0, maxRand));
        rand0Engine = make_shared<std::minstd_rand0>(rd());
        ranlux48Engine = make_shared<std::ranlux48>(rd());
    }
    std::random_device rd;
    std::shared_ptr<std::mt19937> mtEngine;		//32-bit Mersenne Twister by Matsumoto and Nishimura, 1998
    std::shared_ptr<std::mt19937_64> mtEngine64; //64-bit Mersenne Twister by Matsumoto and Nishimura, 2000(马特赛特旋转演算法)
    std::shared_ptr<std::minstd_rand0> rand0Engine;
    std::shared_ptr<std::ranlux48> ranlux48Engine;
    std::shared_ptr<std::uniform_int_distribution<unsigned>> dist;
};
int main() {
    cout << Random::getInstance().GetMTEngineInteger() << endl;
    cout << Random::getInstance().GetMTEngine64Integer() << endl;
    cout << Random::getInstance().GetRand0Integer() << endl;
    cout << Random::getInstance().GetRanlux48Integer() << endl;
    cout << Random::getInstance().getInteger() << endl;
    return 0;
}
```