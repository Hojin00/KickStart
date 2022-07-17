

/** 

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). 
You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
Since the answer can be very large, return it modulo 10^9 + 7.

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

**/


// TLE (Time Limit Exceeded)
// this approach contains many branches that had been already visited before. Needs memoization.
// Time Complexity: O(4^n).
// Space Complexity: O(n).
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (startRow == m || startColumn == n || startRow < 0 || startColumn < 0) return 1; // whenever the ball goes out of boundary, counts 1.
        if (maxMove == 0) return 0; // ball can only move within a certain amount of steps
        
        // recursive function
        // takes every 4 steps
        return findPaths(m, n, maxMove - 1, startRow - 1, startColumn)
            + findPaths(m, n, maxMove - 1, startRow + 1, startColumn)
            + findPaths(m, n, maxMove - 1, startRow, startColumn - 1)
            + findPaths(m, n, maxMove - 1, startRow, startColumn + 1);
    }
};