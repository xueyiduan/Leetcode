/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

// 标准做法是两次二分，第一次正好找到首位，第二次找到末位
var searchRange = function (nums, target) {
  let n = nums.length;
  // search for the first
  let [l, r] = [0, n - 1];
  while (l < r) {
    let mid = Math.floor((l + r) / 2);
    if (nums[mid] >= target) r = mid;
    else l = mid + 1;
  }
  let first = nums[l] === target ? l : -1;
  // search for the last
  [l, r] = [0, n - 1];
  while (l < r) {
    let mid = Math.ceil((l + r) / 2);
    if (nums[mid] <= target) l = mid;
    else r = mid - 1;
  }
  let last = nums[l] === target ? l : -1;
  return [first, last];
};

// 自己写的，时间O(n)？两个while好像到不了O(logn)，空间O(1)
var searchRange1 = function (nums, target) {
  let n = nums.length;
  let [l, r] = [0, n - 1];
  while (l < r) {
    let mid = (l + r) >> 1;
    if (nums[mid] >= target) r = mid; // 不能是>，否则会漏过满足条件的nums[mid]
    else l = mid + 1;
  }
  if (nums[l] !== target) return [-1, -1];
  let [i, j] = [l, r];
  while (nums[i] === target) i--;
  while (nums[j] === target) j++;
  return [++i, --j];
};
