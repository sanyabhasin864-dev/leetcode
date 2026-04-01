class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> actual_index(n);
        iota(begin(actual_index), end(actual_index), 0);

        auto lambda = [&](int &i, int &j){
            return positions[i] < positions[j];
        };

        sort(begin(actual_index), end(actual_index), lambda);

        stack<int> stk;

        for(int &curr_idx : actual_index){
            if(directions[curr_idx] == 'R'){
                stk.push(curr_idx);
            } 
            else {
                while(!stk.empty() && directions[stk.top()] == 'R' && healths[curr_idx] > 0){
                    int top_idx = stk.top();
                    stk.pop();

                    if(healths[top_idx] > healths[curr_idx]){
                        healths[top_idx] -= 1;
                        healths[curr_idx] = 0;
                        stk.push(top_idx);
                    }
                    else if(healths[top_idx] < healths[curr_idx]){
                        healths[curr_idx] -= 1;
                        healths[top_idx] = 0;
                    }
                    else {
                        healths[curr_idx] = 0;
                        healths[top_idx] = 0;
                    }
                }

                // IMPORTANT: push surviving 'L'
                if(healths[curr_idx] > 0){
                    stk.push(curr_idx);
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};