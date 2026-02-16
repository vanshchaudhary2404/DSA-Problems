/* Author : Vansh Kumar
  Date : 2025-16-02
  Description: Leetcode problem-134 Gas Station
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0 , totalCost = 0, currGas = 0, start =0;

        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];  //total available gas 
            totalCost += cost[i];  //total required gas

            currGas += gas[i] - cost[i];
            // if balance becomes negative:
            // → cannot start from previous start
            // → next index becomes new candidate

            if( currGas <0){
                start =i+1; //shift startig point
                currGas =0; // reset currGas to 0 for new gas station.
            }
        }
         // If total gas < total cost → not a viable condition.
        return totalGas < totalCost ? -1 : start;
    }
};
