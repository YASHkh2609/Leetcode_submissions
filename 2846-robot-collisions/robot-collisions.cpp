// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         map<int, pair<int,char>>mpp; //pos->{health, direction}
//         int n=positions.size();
//         for(int i=0;i<n;i++){
//             mpp[positions[i]]={healths[i],directions[i]};
//         }

//         stack<pair<int, char>>st; //health and direction

//         for(auto it=mpp.begin(); it!=mpp.end();){
//             int curHealth = it->second.first;
//             char curDirection = it->second.second;
//             if(st.empty()){
//                 st.push({curHealth, curDirection});
//                 it++;
//             }
//             else{
//                 char prevDirection = st.top().second;
//                 char prevHealth = st.top().first;
//                 //no collision
//                 if((curDirection == prevDirection) || (prevDirection=='L' && curDirection=='R')){
//                     st.push({curHealth, curDirection});
//                     it++;
//                 }
//                 //collision
//                 else{
//                     if(prevHealth==curHealth){
//                         st.pop();
//                         it++;
//                     }
//                     else if(prevHealth<curHealth){
//                         st.pop();
//                         curHealth--;
//                         //st.push({curHealth-1,curDirection});
//                         bool flag=true;
//                         while(!st.empty() && (st.top().second=='R' && curDirection=='L')){
//                             int topHealth = st.top().first;
//                             char topDir = st.top().second;
//                             if(curHealth>topHealth){
//                                 st.pop();
//                                 curHealth--;
//                             }
//                             else if(curHealth==topHealth){
//                                 st.pop();
//                                 it++;
//                                 flag=false;
//                                 break;
//                             }
//                             else{
//                                 st.pop();
//                                 st.push({topHealth-1, topDir});
//                                 it++;
//                                 flag=false;
//                                 break;
//                             }
//                         }
//                         if(flag)st.push({curHealth, curDirection});
//                     }
//                     else{
//                         st.pop();
//                         st.push({prevHealth-1, prevDirection});
//                         it++;
//                     }
//                 }
//             }
//         }
//         vector<int>ans;
//         while(!st.empty()){
//             int health = st.top().first;
//             ans.push_back(health);
//             st.pop();
//         }
//         //reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int index = 0; index < n; ++index) {
            indices[index] = index;
        }

        sort(indices.begin(), indices.end(),
             [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });

        for (int currentIndex : indices) {
            // Add right-moving robots to the stack
            if (directions[currentIndex] == 'R') {
                stack.push(currentIndex);
            } else {
                while (!stack.empty() && healths[currentIndex] > 0) {
                    // Pop the top robot from the stack for collision check
                    int topIndex = stack.top();
                    stack.pop();

                    // Top robot survives, current robot is destroyed
                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        // Current robot survives, top robot is destroyed
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        // Both robots are destroyed
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots
        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};