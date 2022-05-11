// TC: O(NlogN)
// SC: O(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        sort(itv.begin(), itv.end());
        
        stack<vector<int>> st;
        
        for(auto v: itv){
            if(st.empty()){
                st.push(v);
            }
            else{
                auto tp = st.top();
                st.pop();
                
                if(v[0] >= tp[0] && v[0] <= tp[1]){
                    if(v[1] <= tp[1])
                        st.push(tp);
                    else
                        st.push({tp[0], v[1]});
                }
                else{
                    st.push(tp);
                    st.push(v);
                }
            }
        }
        
        vector<vector<int>> ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};