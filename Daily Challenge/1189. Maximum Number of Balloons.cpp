class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int w[26] = {0};
        for(const char &ch: text){
            w[ch-'a']++;
        }

        int count = INT_MAX;

        count = min(count , w['b'-'a']);
        count = min(count , w['a'-'a']);
        count = min(count , w['l'-'a']/2);
        count = min(count , w['o'-'a']/2);
        count = min(count , w['n'-'a']);

        return count;

    }
};
