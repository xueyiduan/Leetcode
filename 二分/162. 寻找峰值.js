/**
 * @param {number[]} nums
 * @return {number}
 */

// 这题最重要的是想明白什么情况能找到峰值 ➡️ 峰值一定在更高的那一侧，可以看 @林小鹿 的图示
// 时间O(logn)，空间O(1)
var findPeakElement = function (nums) {
  let [l, r, n] = [0, nums.length - 1, nums.length];
  if (n === 1) return 0;
  while (l < r) {
    let mid = (l + r) >> 1; // x>>1相当于Math.floor(x/2)
    if (nums[mid] > nums[mid + 1]) r = mid; // 这里为啥不用考虑mid+1越界❓
    // ➡️ 因为l和r不相等，区间最窄的情况是r=l+1，此时mid===l，mid+1肯定在界内。如果mid=(l+r+1)>>1就不行了，必须向下取整
    else l = mid + 1;
  }
  return l;
};

// 通过42/67个测试用例
var findPeakElement1 = function (nums) {
  let [l, r, n] = [0, nums.length - 1, nums.length];
  const binary = (l, r) => {
    if (l >= r) return null;
    let mid = (l + r) >> 1;
    if (
      mid > 0 &&
      mid < n - 1 &&
      nums[mid] > nums[mid - 1] &&
      nums[mid] > nums[mid + 1]
    )
      return mid;
    else if (mid === 0 && mid + 1 < n && nums[mid] > nums[mid + 1]) return mid;
    else if (mid === n - 1 && mid - 1 >= 0 && nums[mid] > nums[mid - 1])
      return mid;
    else {
      return binary(l, mid - 1) || binary(mid + 1, r);
    }
  };
  return binary(l, r, n);
};
