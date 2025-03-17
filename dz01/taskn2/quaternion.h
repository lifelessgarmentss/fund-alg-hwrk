#pragma once

class Quaternion
{
private:
    double  a, b, c, d;
public:
    Quaternion(double  a, double  b, double  c, double  d);
    Quaternion(const Quaternion &q);
    ~Quaternion();
    void set_quaternion(double na, double nb, double nc, double nd);
    void get_quaternion(double &na, double &nb, double &nc, double &nd);
    void print();
    double  norm();
    Quaternion conjugate();
    void  normalize();
    Quaternion inverse();
};

Quaternion quat_plus(Quaternion &q1, Quaternion &q2);
Quaternion quat_minus(Quaternion &q1, Quaternion &q2);
Quaternion multiplication(Quaternion &q1, Quaternion &q2);
Quaternion division(Quaternion &q1, Quaternion q2);
Quaternion scalar(Quaternion &q1, Quaternion &q2);
double  euclidean_distance(Quaternion &q1, Quaternion &q2);
double  chebyshev_norm(Quaternion &q1, Quaternion &q2);
