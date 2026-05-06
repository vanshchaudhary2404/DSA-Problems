class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        /*
        int m = boxGrid.size();//row
        int n = boxGrid[0].size();//col
        //here in place transpose is not work like in rotate image problme  becoz it only works for square matrices 

        vector<vector<char>> result(n , vector<char>(m));//n x m matrix 
        
        //step 1 -> (A). Transpose 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                result[i][j] = boxGrid[j][i];
            }
        }
        //step 1 -> (B). reverse 
        for(vector<char>&row : result){
            reverse(begin(row) ,end(row));
        }

        //Step2 - gravity effect 
        //m-> col of result matrix & n-> row of result matrix
        // O( col*row*row)
        for(int j=0; j< m; j++){
            for(int i=n-1; i>=0; i--){
                if(result[i][j] == '.'){//if it is a space
                    int stoneRow = -1;

                    for(int k = i - 1; k >= 0; k--){
                        if(result[k][j] == '*'){
                            break; // obstacle blocks
                        }
                        if(result[k][j] == '#'){
                            stoneRow = k;
                            break;
                        }
                    }
                    if(stoneRow != -1){
                        result[i][j] = '#';
                        result[stoneRow][j] ='.';
                    }
                }
            }
        }
        return result;
        */




        //OPtimised way
        int m = boxGrid.size();//row
        int n = boxGrid[0].size();//col
        vector<vector<char>> result(n , vector<char>(m));//n x m matrix 
        
        //step 1 -> (A). Transpose 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                result[i][j] = boxGrid[j][i];
            }
        }
        //step 1 -> (B). reverse 
        for(vector<char>&row : result){
            reverse(begin(row) ,end(row));
        }

        //Step2 - gravity effect 
        //m-> col of result matrix & n-> row of result matrix
        //O(col*row)
        for(int j=0; j<m; j++){
            int spaceBottomRow = n-1;
            for(int i=n-1; i>=0; i--){
                if(result[i][j] == '*'){
                    spaceBottomRow = i-1;
                    continue;
                }

                if(result[i][j] == '#'){
                    swap(result[i][j], result[spaceBottomRow][j]);
                    spaceBottomRow--;
                }
            }
        }
        return result;
    }
};
