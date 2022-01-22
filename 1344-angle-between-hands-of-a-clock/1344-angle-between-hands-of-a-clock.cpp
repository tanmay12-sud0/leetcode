class Solution {
public:
    double angleClock(int hour, int minutes) {
        float angle1 = float(0.5)*(((hour*60)+minutes)%(12*60));
        float angle2 = 6*minutes;
        cout << angle1 << ", " << angle2 << endl;
        double a = abs(angle1-angle2);
        double b = 360-(abs(angle1-angle2));
        double x = min(a, b);
        return x;
    }
};