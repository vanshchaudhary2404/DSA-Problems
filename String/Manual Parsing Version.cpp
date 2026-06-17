class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();

        for(int i=0; i<n; i++){
            if( path[i] == '/') continue;

            string dir = "";

            while(i <n && path[i] != '/'){
                dir += path[i];
                i++;
            }

            if( dir == ".") continue;
            else if(dir == ".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(dir);
            }
        }

        string ans = "";
        for(auto &dir : st){
            ans += "/"+ dir;
        }

        return ans.empty() ? "/" : ans;
    }
};
