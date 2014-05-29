class Solution {
public:
    double doit(double x, int n) {
        if (n == 0) return 1;
        double t = pow(x, n / 2);
        if (n & 1) return t * t * x;
        else return t * t;
    }
    double pow(double x, int n) {
        if (n < 0) return 1.0 / doit(x, -n);
        else return doit(x, n);
    }
};