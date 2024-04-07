/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

// 找不到目标数字时，-1 会让落点在目标数字本应在的位置左侧，+1 落在右侧
// 时间O(logn)，空间O(1)
var searchInsert = function (nums, target) {
  let n = nums.length;
  // if (target < nums[0]) return 0;
  if (target > nums[n - 1]) return n;
  let [l, r] = [0, n - 1];
  while (l < r) {
    let mid = Math.floor((l + r) / 2);
    if (nums[mid] >= target) r = mid;
    else l = mid + 1; // 若n[mid]严格<target，则mid及其左边一定不是插入点，区间变为[mid+1, r]
  }
  return l;
};
