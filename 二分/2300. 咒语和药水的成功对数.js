/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */

// 先排序potions，对每个spell找到满足success的potions最小下标即可，找下标的过程为二分
// 时间，postions排序用快排平均O(m*logm)，二分过程O(n*logm)，相加O(mlogm+nlogm)
// 空间，pairs数组O(n)，二分栈空间O(logm)，相加O(n+logm)
var successfulPairs = function (spells, potions, success) {
  const [n, m] = [spells.length, potions.length];
  const pairs = new Array(n).fill(0);
  // 排序potions
  potions = potions.sort((a, b) => a - b);
  spells.map((cur, i) => {
    // 找到potions中满足条件的最小下标
    const target = success / cur;
    let [l, r] = [0, m - 1];
    while (l < r) {
      let mid = (l + r) >> 1; // 📌 技巧 📌，这里不加括号也行，+-优先级高于位运算
      if (potions[mid] >= target) r = mid;
      else l = mid + 1;
    } // 出while时，l === r 且 positons[l] 要么是满足条件的最小下标，要么是最后一个下标（最大的potion值都不满足条件）
    if (potions[l] * cur >= success) pairs[i] = m - l;
  });
  return pairs;
};

// 嵌套遍历两个数组，时间O(n*m)，空间O(n)，51/56通过，剩下超出时间限制
var successfulPairs1 = function (spells, potions, success) {
  const n = spells.length;
  const pairs = new Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    let cur = spells[i];
    potions.map((potion) => {
      if (cur * potion >= success) {
        pairs[i]++;
      }
    });
  }
  return pairs;
};
