class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a1 = (double)(hour/12.0)*360 +(double)(minutes/60.0*30);
        double a2 =(double)(minutes/60.0)*360;
        cout<<a1<<" "<<a2;

        double angle ;
        if(a1>a2)angle = a1-a2;
        else{
            angle = a2-a1;
        }
        if(angle >180){
            angle= 360-angle;
        }
        return angle;
    }
};
