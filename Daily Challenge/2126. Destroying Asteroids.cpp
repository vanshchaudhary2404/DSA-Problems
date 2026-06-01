class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end());
        
        long currentMass = mass;
        for(auto asteroid : asteroids){
            if(currentMass < asteroid){
                return false;
            }
            currentMass += asteroid;
        }

        return true;
    }
};
