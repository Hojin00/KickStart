
/**

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false

Constrains:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

**/

// Runtime: 155 ms, faster than 41.71% of C++ online submissions for Contains Duplicate.
// Memory Usage: 46.6 MB, less than 78.99% of C++ online submissions for Contains Duplicate.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        
        int cnt = 0;
        int a = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            
            if(a == nums[i]) {
                cnt++;
            } else {
                cnt = 1;
                a = nums[i];
            }
            
            if(cnt >= 2) {
                return true;
                break;
            } 
        }
            
        return false;
    }
};


// Runtime: 123 ms, faster than 69.43% of C++ online submissions for Contains Duplicate.
// Memory Usage: 51.5 MB, less than 50.99% of C++ online submissions for Contains Duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        
        unordered_map<int, int> m; // using BST map, gives us faster runtime and higher memory usage
  		// Runtime: 107 ms, faster than 86.73% 
		// Memory Usage: 52.2 MB, less than 27.53% 
        
        for(int i = 0; i<nums.size(); i++) {
            m[nums[i]] += 1;
            if( m[nums[i]] > 1) return true;
        }
        
        return false;
    }
};