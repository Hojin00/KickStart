/**

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

**/

// Runtime: 19 ms, faster than 90.99% of C++ online submissions for Majority Element.
// Memory Usage: 19.5 MB, less than 58.28% of C++ online submissions for Majority Element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int num = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                num = nums[i];
            } 
            if(num == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return num;
    }
};


// Runtime: 29 ms, faster than 55.37% of C++ online submissions for Majority Element.
// Memory Usage: 19.6 MB, less than 58.28% of C++ online submissions for Majority Element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            
            // m.find(a) -> this line of code delays the runtime
            if(m.find(a) == m.end()) {
                auto p = m.find(a);
                
                m.insert(make_pair(a,1)); // and this line too.
            } else {
                auto p = m.find(a);
                p->second = p->second + 1;
                
            }
        }
        
        int max = nums.size()/2;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            auto p = m.find(a);
            
            if(p->second > max) {
                result = p->first;
                break;
            }
        } 
        return result;
    }
};

//this way of insertion gives Runtime: 20 ms, faster than 87.84% of C++ online submissions for Majority Element. and same memory usage.
for(int e : nums) {
    if(m.find(e) == m.end()) {
        m[e] = 1; // it's better to update a new value or old value this way.
    } else {
        m[e] += 1;
   	}
            
}
