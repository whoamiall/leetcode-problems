solution1：（Brute Force）
时间复杂度：O（n^2) 双层for循环
空间复杂度：O（1）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for(int i = 0; i < len - 1; i++){
            for(int j = i + 1; j < len; j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
思考：虽然解法很简单但是代码效率不高，寻找更加快速的方法解决
我们可以利用map的结构，一个map里可以有两个值一个key一个value，我们key当作值，value当作数组下标，对数组进行遍历把每一个遍历值放进map，这样我们每遍历一个数就可以查询之前访问的数有没有相加等于tgarget的值，哈希表映射使得问题简化。
solution2：（Hash Map）
时/空间复杂度O（n）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hashtable;
       for(int i = 0; i < nums.size();i++){
        auto it = hashtable.find(target - nums[i]);
        if(it != hashtable.end()){
            return {it->second, i};
        }
        hashtable.insert({nums[i],i});   
       }
       return {};
    }
};
