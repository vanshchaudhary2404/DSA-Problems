class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            string s = to_string(num);

            for(char ch:s){
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};

//Java code 
/*class Solution {

    // Method returns an array of separated digits
    public int[] separateDigits(int[] nums) {

        // ArrayList is used because size is dynamic
        // Concept: Collection Framework / Dynamic Array
        List<Integer> list = new ArrayList<>();


        // Enhanced for loop to iterate through each number in nums
        // Concept: Enhanced For Loop
        for (int num : nums) {

            // Convert integer into String
            // Concept: Type Conversion (int -> String)
            String s = String.valueOf(num);


            // Convert string into character array and iterate each character
            // Concept: String Methods + Character Array
            for (char ch : s.toCharArray()) {

                // Convert character digit into integer digit
                // Example: '5' - '0' = 5
                // Concept: ASCII Character Arithmetic
                list.add(ch - '0');
            }
        }


        // Create result array of exact required size
        // Concept: Array Creation
        int[] result = new int[list.size()];


        // Copy elements from ArrayList to Array
        // Concept: Array Traversal
        for (int i = 0; i < list.size(); i++) {

            // get(i) fetches element from ArrayList
            result[i] = list.get(i);
        }


        // Return final separated digits array
        return result;
    }
}*/
