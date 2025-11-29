/* Author : Vansh Kumar
  Date : 2025-11-29
  Description: Leetcode problem-2149. Rearrange Array Elements by Sign
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>&a) {
       //brute force with one pass
        /*int n= a.size();
        vector<int> ans(n,0);
        int posIdx =0, negIdx = 1;
        for(int i=0; i<n; i++){
            if( a[i] > 0){
                ans[posIdx] = a[i];
                posIdx +=2; 
            } else{
                ans[negIdx] = a[i];
                negIdx +=2;
            }
        }
        return ans;*/

        // Problem Variety 2 : IF size of a is not even means positive element no. != negative element no.
        vector<int> pos , neg;
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i] > 0) pos.push_back(a[i]);
            else neg.push_back(a[i]);
        }
        
        if( pos.size() > neg.size()){
            for(int i=0; i<neg.size(); i++){
                a[2*i] = pos[i];
                a[2*i+1] = neg[i];
            }
            int idx = neg.size()*2;//run from double index of the size negative arr because of small size of neg arr
            for(int i=neg.size(); i<pos.size(); i++){
                a[idx] = pos[i];
                idx++; 
            }
        } else {
            for(int i=0; i<pos.size(); i++){
                a[2*i] = pos[i];
                a[2*i+1] = neg[i];
            }
            int idx = pos.size()*2;//run from double index of the size negative arr because of small size of neg arr
            for(int i=pos.size(); i<neg.size(); i++){
                a[idx] = neg[i];
                idx++; 
            }
        }
        return a;
    }
};
