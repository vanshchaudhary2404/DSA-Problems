class Solution {
public:
    double angleClock(int hour, int minutes) {
    /*    double totalHr = double(hour) + double(minutes)/60;

        double angleHrHand = totalHr*30;

        double angleMinHand = minutes*6;

        double res = abs(angleMinHand - angleHrHand);

        if(res > 180){
            return 360-res;
        }

        return res;
    }
    */

        if(hour == 12) hour = 0;

        double angle = abs(30.0*hour - 5.5*minutes);

        return min(angle , 360-angle);
    }
};
