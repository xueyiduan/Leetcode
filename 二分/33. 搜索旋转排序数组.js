/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

// 一次二分，重点在check函数，时间O(logn)，n是数组长度，空间O(1)
var search = function (nums, target) {
  let n = nums.length;
  let [l, r] = [0, n - 1];
  while (l < r) {
    let mid = (l + r) >> 1;
    if (check(nums, target, mid)) r = mid;
    else l = mid + 1;
  }
  return target === nums[l] ? l : -1;
};
const check = (nums, target, i) => {
  // i 在前半段，r前移的条件：target也在前半段且小于nums[i]
  if (nums[i] >= nums[0]) {
    return target >= nums[0] && target <= nums[i];
  }
  // i 在后半段，r前移的条件：要么target在前半段，要么target小于nums[i]
  else {
    return target >= nums[0] || target <= nums[i];
  }
};

// 两次二分，时间O(logn)，n是数组长度，空间O(1)
var search1 = function (nums, target) {
  // 二分找转折点k，nums = [>=nums[0]的数列，<nums[0]的数列]，利用此规律二分找k
  let n = nums.length;
  if (n === 1) return target === nums[0] ? 0 : -1;
  let [l, r] = [0, n - 1];
  while (l < r) {
    let mid = (l + r) >> 1;
    if (nums[mid] < nums[0]) r = mid;
    else l = mid + 1;
  }
  let pivot = l;
  // 二分找target
  if (target >= nums[0]) {
    [l, r] = [0, pivot]; // ❗️这里一开始写成pivot-1，是错的，因为如果根本没有旋转，pivot就是n-1，再-1会导致最后一个数没有参与比较
  } else {
    [l, r] = [pivot, n - 1];
  }
  while (l < r) {
    let mid = (l + r) >> 1;
    if (nums[mid] >= target) r = mid;
    else l = mid + 1;
  }
  return target === nums[l] ? l : -1;
};
