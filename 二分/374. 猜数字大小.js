/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function (n) {
  return binary_search(1, n);
};

// 注意1️⃣mid = low + xxx, low不要忘2️⃣else if 里的 mid + 1和 - 1不要忘
const binary_search = (low, high) => {
  const mid = low + Math.round((high - low) / 2);
  const res = guess(mid);
  if (res === 0) {
    return mid;
  } else if (res === -1) {
    return binary_search(low, mid - 1);
  } else {
    return binary_search(mid + 1, high);
  }
};
