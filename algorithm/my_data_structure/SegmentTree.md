---

title: 线段树 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 线段树

> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---


```cpp
/**************************************************
 * @brief 线段树模板
 * @note 区间使用的是闭区间，结点是从1开始编号的。来自OI-Wiki
 * @date 2021/05/18
 *************************************************/

#include <bits/stdc++.h>

template<typename T>
class SegmentTree {
public:
    explicit SegmentTree(int n) : lPos(1), rPos(n), node(4 * n + 10), lazy(4 * n + 10) {}

    /**
     * @brief 建立一棵线段树
     * @param data 输入数据
     * @param shift 调整偏移量使得数据和树匹配，因为树中的结点是从1开始计数
     * */
    void build(std::vector<T> &data, int shift) {
        buildStep(lPos, rPos, data, shift, 1);
    }

    /**
     * @brief 区间更新线段树
     * @param diff 被修改的区间元素的变化量
     * @param lPosQ 被修改的区间的左端点
     * @param rPosQ 被修改的区间的右端点
     * 
     * */
    void update(int diff, int lPosQ, int rPosQ) {
        updateStep(lPosQ, rPosQ, diff, lPos, rPos, 1);
    }

    /**
     * @brief 区间求和
     * @param lPosQ 当前结点包含的区间的左端点
     * @param rPosQ 当前结点包含的区间的右端点
     * @param pos 当前结点的编号
     **/
    T query(int lPosQ, int rPosQ) {
        return queryStep(lPosQ, rPosQ, lPos, rPos, 1);
    }

private:
    /**
     * @brief 建立一棵线段树的步骤
     * @param lPosQ 建树区间的左端点
     * @param rPosQ 建树区间的右端点
     * @param pos 当前根的编号
     * @param data 输入数据
     * @param shift 输入数据和建树的序号匹配
     * */
    void buildStep(int lPosQ, int rPosQ, std::vector<T> &data, int shift, int pos) {
        if (lPosQ == rPosQ) {
            node[pos] = data[lPosQ + shift];
            return;
        }
        int mPosP = lPosQ + ((rPosQ - lPosQ) >> 1);
        buildStep(lPosQ, mPosP, data, shift, pos << 1);
        buildStep(mPosP + 1, rPosQ, data, shift, (pos << 1) | 1);
        node[pos] = node[pos << 1] + node[(pos << 1) | 1];
    }

    /**
     * @brief 区间更新线段树
     * @param lPosQ 被修改的区间的左端点
     * @param rPosQ 被修改的区间的右端点
     * @param diff 被修改的区间元素的变化量
     * @param sPos 当前结点包含的区间的左端点
     * @param ePos 当前结点包含的区间的右端点
     * @param pos 当前结点的编号
     * */
    void updateStep(int lPosQ, int rPosQ, int diff, int sPos, int ePos, int pos) {
        if (lPosQ <= sPos and ePos <= rPosQ) {
            node[pos] += (ePos - sPos + 1) * diff;
            lazy[pos] += diff;
            return;
        }
        int mPos = sPos + ((ePos - sPos) >> 1);
        if (lazy[pos] and sPos != ePos) {
            node[pos << 1] += lazy[pos] * (mPos - sPos + 1);
            node[(pos << 1) | 1] += lazy[pos] * (ePos - mPos);
            lazy[pos << 1] += lazy[pos];
            lazy[(pos << 1) | 1] += lazy[pos];
            lazy[pos] = 0;
        }
        if (lPosQ <= mPos) {
            updateStep(lPosQ, rPosQ, diff, sPos, mPos, pos << 1);
        }
        if (rPosQ > mPos) {
            updateStep(lPosQ, rPosQ, diff, mPos + 1, ePos, (pos << 1) | 1);
        }
        node[pos] = node[pos << 1] + node[(pos << 1) | 1];
    }

    /**
     * @brief 区间求和的步骤
     * @param lPosQ 查询区间左端点
     * @param rPosQ 查询区间右端点
     * @param sPos 当前结点包含的区间的左端点
     * @param ePos 当前结点包含的区间的右端点
     * @param pos 当前结点的编号
     **/
    T queryStep(int lPosQ, int rPosQ, int sPos, int ePos, int pos = 1) {
        if (lPosQ <= sPos and ePos <= rPosQ) return node[pos];
        int mPos = sPos + ((ePos - sPos) >> 1);
        if (lazy[pos]) {
            node[pos << 1] += lazy[pos] * (mPos - sPos + 1);
            node[(pos << 1) | 1] += lazy[pos] * (ePos - mPos);
            lazy[pos << 1] = lazy[pos];
            lazy[(pos << 1) | 1] = lazy[pos];
            lazy[pos] = 0;
        }
        T sum = 0;
        if (lPosQ <= mPos) {
            sum = queryStep(lPosQ, rPosQ, sPos, mPos, pos << 1);
        }
        if (rPosQ > mPos) {
            sum += queryStep(lPosQ, rPosQ, mPos + 1, ePos, (pos << 1) | 1);
        }
        return sum;
    }

    int lPos, rPos;
    std::vector<T> node, lazy;
};

int main() {
    std::vector<int> arr{9, -8};
    int arrSize = static_cast<int>(arr.size());
    SegmentTree<int> tre(arrSize);
    tre.build(arr, -1);
    tre.update(-6, 1, 1);
    assert(tre.query(2, 2) == -8);
    assert(tre.query(1, 1) == 3);
    assert(tre.query(1, 2) == -5);
    return 0;
}
```