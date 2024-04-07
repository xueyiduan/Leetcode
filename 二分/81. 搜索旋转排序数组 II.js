/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */

// 时间O(n)，空间O(1)
var search = function (nums, target) {
  let n = nums.length;
  let [l, r] = [0, n - 1];
  while (l < r && nums[0] === nums[r]) r--; // 恢复二段性，这句是精髓
  while (l < r) {
    let mid = Math.floor((l + r) / 2);
    if (target === nums[mid]) return true;
    if (check(mid, nums, target)) r = mid;
    else l = mid + 1;
  }
  return target === nums[l];
};

const check = (mid, nums, target) => {
  // 严格小于nums[0]，mid处于后半段 ➡️ 要么target在前半段，要么在后半段且<=nums[mid]
  if (nums[mid] < nums[0]) {
    return target >= nums[0] || target < nums[mid];
  }
  // 大于等于nums[0]，mid处于前半段 ➡️ target在前半段且<=nums[mid]
  else if (nums[mid] >= nums[0]) {
    return target >= nums[0] && target < nums[mid];
  }
};
