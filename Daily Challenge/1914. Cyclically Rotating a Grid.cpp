class Solution {
public:
    //T.C = O(m*n*min(m,n)/2) -> min(m,n)/2  shows no. of layers present in grid
    //s.c =O(1)
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();//row
        int m = grid[0].size();//col

        int top = 0 , left =0 , bottom = n-1 , right = m-1;

        while( top<bottom && left < right){
            int noOfElement = 2*(bottom- top) + 2*(right - left);
            int rotation = k % noOfElement;

            while(rotation--){

                int temp = grid[top][left];
                //at top layer  move TOP ROW elements to left
                for(int j=left; j<right; j++){
                    grid[top][j] = grid[top][j+1];
                }
                //at last  coulmn layer move RIGHT COLUMN elements up
                for(int i=top; i<bottom; i++){
                    grid[i][right] = grid[i+1][right];
                }
                //at bottom layer  move BOTTOM ROW elements right
                for(int j=right; j>left; j--){
                    grid[bottom][j] = grid[bottom][j-1];
                }
                // at left most layer move LEFT COLUMN elements down
                for(int i=bottom; i>top; i--){
                    grid[i][left] = grid[i-1][left];
                }

                grid[top+1][left] = temp;
            }

            //change to inner layer
            top++;
            left++;
            bottom--;
            right--;
        }
        return grid;
    }
};
