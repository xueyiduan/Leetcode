/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */

// 这道题要求k，k的数据范围是pile数量，所以二分是对的二分是对pile数量进行二分
// 注意，如果提前不知道这是二分题，能想到用二分吗
// n是piles长度，m是10e9,时间O(nlogm)，空间O(1)
var minEatingSpeed = function (piles, h) {
  let [l, r] = [1, 10e9];
  let maxpile = 1;
  piles.forEach((cur) => {
    if (cur > maxpile) maxpile = cur;
  });
  while (l < r) {
    let mid = (l + r) >> 1;
    if (canfinish(mid, piles, h)) r = mid;
    else l = mid + 1;
  }
  return l;
};
const canfinish = (k, piles, h) => {
  let time = 0;
  piles.forEach((cur) => {
    time += Math.ceil(cur / k);
  });
  return time <= h;
};
