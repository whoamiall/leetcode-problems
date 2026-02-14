49. Group Anagrams (字母异位词分组)
💡 核心思路：哈希表分类法
通过将每个字符串进行排序，我们可以得到一个“标准标签（Key）”。所有互为字母异位词的单词，排序后的标签都是一致的。
逻辑拆解：
1. 统一门牌号：对单词如 `eat`, `tea` 排序，都得到 `aet`。
2. 分拣入库：使用 `unordered_map<string, vector<string>>`。
   - `Key` (键): 排序后的标签（如 `"aet"`）。
   - `Value` (值): 原始单词的集合（如 `["eat", "tea"]`）。
3. **搬运结果**：遍历哈希表，将所有“抽屉”里的单词集合存入结果数组。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> dic;
        for(string s : strs){
            string key = s;
            sort(key.begin(),key.end());
            dic[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it = dic.begin(); it != dic.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};
