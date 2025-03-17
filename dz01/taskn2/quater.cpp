#include <iostream>
#include <cmath>
#include "quaternion.h"


using namespace std;

Quaternion::Quaternion(double  na = 1, double  nb = 0, double  nc = 0, double  nd = 0)
{
    a = na;
    b = nb;
    c = nc;
    d = nd;
}

Quaternion::Quaternion(const Quaternion &q)
{
    a = q.a;
    b = q.b;
    c = q.b;
    d = q.d;
}

Quaternion::~Quaternion(){}

void Quaternion::set_quaternion(double na, double nb, double nc, double nd)
{
    a = na;
    b = nb;
    c = nc;
    d = nd;
}

void Quaternion::get_quaternion(double &na, double &nb, double &nc, double &nd)
{
    na = a;
    nb = b;
    nc = c;
    nd = d;
}

void Quaternion::print()
{
    cout << "Quaterion: " << a;
    if (b < 0)
    {
        cout << " - " << abs(b) << "i";
    }
    else if (b > 0)
    {
        cout << " + " << b << "i";
    }

    if (c < 0)
    {
        cout << " - " << abs(c) << "j";
    }
    else if (c > 0)
    {
        cout << " + " << c << "j";
    }

    if (d < 0)
    {
        cout << " - " << abs(d) << "k";
    }
    else if (d > 0)
    {
        cout << " + " << d << "k";
    }

    cout << endl;
}

double Quaternion::norm()
{
    return sqrt(a*a + b*b + c*c + d*d);
}

Quaternion Quaternion::conjugate()
{
    return Quaternion(a, -1 * b, -1 * c, -1 * d);
}

void  Quaternion::normalize()
{
    double n = norm();

    a /= n;
    b /= n;
    c /= n;
    d /= n;
}

Quaternion Quaternion::inverse()
{
    Quaternion con_q = Quaternion(a, -1 * b, -1 * c, -1 * d);
    double n = con_q.norm();
    con_q.a /= n*n;
    con_q.b /= n*n;
    con_q.c /= n*n;
    con_q.d /= n*n;
    return con_q;
}


Quaternion quat_plus(Quaternion &q1, Quaternion &q2)
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    q1.get_quaternion(a1, b1, c1, d1);
    q2.get_quaternion(a2, b2, c2, d2);
    return Quaternion(a1 + a2, b1 + b2, c1 + c2, d1 + d2);
}

Quaternion quat_minus(Quaternion &q1, Quaternion &q2)
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    q1.get_quaternion(a1, b1, c1, d1);
    q2.get_quaternion(a2, b2, c2, d2);
    return Quaternion(a1 - a2, b1 - b2, c1 - c2, d1 - d2);
}

Quaternion multiplication(Quaternion &q1, Quaternion &q2)
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    q1.get_quaternion(a1, b1, c1, d1);
    q2.get_quaternion(a2, b2, c2, d2);
    return Quaternion(a1*a2 - b1*b2 - c1*c2 - d1*d2, a1*b2 + b1*a2 + c1*d2 - d1*d2,
        a1*c2 + c1*a2 + d1*b2 - b1*d2, a1*d2 + d1*a2 + b1*c2 - c1*b2);
}

Quaternion division(Quaternion &q1, Quaternion q2)
{   
    q2 = q2.inverse();
    return multiplication(q1, q2);
}

Quaternion scalar(Quaternion &q1, Quaternion &q2)
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    q1.get_quaternion(a1, b1, c1, d1);
    q2.get_quaternion(a2, b2, c2, d2);
    return Quaternion(a1*a2, a1*b2, a1*c2, a1*d2);
}
  
double  euclidean_distance(Quaternion &q1, Quaternion &q2)
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    q1.get_quaternion(a1, b1, c1, d1);
    q2.get_quaternion(a2, b2, c2, d2);
    return sqrt(pow(a1 - a2, 2) + pow(b1 - b2, 2) + pow(c1 - c2, 2) + pow(d1 - d2, 2));
}

double  chebyshev_norm(Quaternion &q1, Quaternion &q2)
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    q1.get_quaternion(a1, b1, c1, d1);
    q2.get_quaternion(a2, b2, c2, d2);
    double n[4] = {abs(a1 - a2), abs(b1 - b2), abs(c1 - c2), abs(d1 - d2)};
    double m = 0;
    for (int i = 0; i < 4; i++)
    {
        m = max(m, n[i]);
    }
    return m;
}
