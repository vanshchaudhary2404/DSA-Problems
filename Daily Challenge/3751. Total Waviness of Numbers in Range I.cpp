class Solution {
public:
    //Brute force approach->recursive
    int findWaiveScore(int num){
        string s = to_string(num);
        int l=s.length();
        if(l<3) return 0;

        int score = 0;
        for(int i=1; i<=l-2; i++){
            //peak
            if(s[i] > s[i-1] && s[i] > s[i+1]) score++;

            //valley
            if(s[i] < s[i-1] && s[i] < s[i+1]) score++;

        }
        return score; 
    }

    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int num= num1; num<=num2; num++){
            score += findWaiveScore(num);
        }
        return score;
    }
    //Bruite force by self
    /* int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = num1; num <= num2; num++) {
            string s = to_string(num);
            int cnt = 0;
            for (int j = 1; j < s.size() - 1; j++) {
                int x = s[j - 1] - '0';
                int y = s[j] - '0';
                int z = s[j + 1] - '0';

                if ((y > x && y > z) ||
                    (y < x && y < z)) {
                    cnt++;
                }
            }
            ans += cnt;
        }
        return ans;
    }*/
};
