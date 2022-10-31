class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int size = temperatures.size();
        vector<int> answer(size, 0);
        stk.push(size - 1);
        for (int i = size - 2; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
            if (!stk.empty()) answer[i] = stk.top() - i;
            stk.push(i);
        }
        return answer;
    }
};