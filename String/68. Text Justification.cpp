class Solution {
public:
int MAX_WIDTH;

    string findLine(int i , int j , int eachSpace , int extraSpace , vector<string>& words){
        string line;
        for(int k=i; k<j; k++){
            line += words[k];

            if(k == j-1){
                //last word of my line - no space after last word of a line.
                //we would have already added the spaces in all other words apart from last word.
                continue;
            }

            for(int z=1; z<= eachSpace; z++){
                line += " ";
            }

            if(extraSpace > 0){
                line += " ";
                extraSpace--;
            }
        }
        while(line.length() < MAX_WIDTH){
            line += " ";
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();

        MAX_WIDTH = maxWidth;

        int i=0;
        while(i < n){
            int letterCnt = words[i].length();
            int j = i+1;
            int space =0;

            while(j<n && (words[j].length() + 1 + space + letterCnt) <= maxWidth){
                letterCnt += words[j].length();
                space +=1;
                j++;
            }
            int remainingSpace = maxWidth- letterCnt;

            int eachSpace = space ==0 ? 0: remainingSpace / space;
            int extraSpace = space ==0 ? 0 : remainingSpace % space;
            if( j == n){// last line -> left justified
                eachSpace = 1;
                extraSpace = 0;
            }
            res.push_back(findLine(i , j , eachSpace , extraSpace , words));
            i=j;
        }

        return res;
    }
};
