#include <iostream>
#include <cmath>
#include "quaternion.h"
#include "quaternion.cpp"


using namespace std;

int main()
{
    Quaternion q = Quaternion(3.60555, 1, 1, 1);
    Quaternion q1 = Quaternion(q);
    Quaternion qp = Quaternion();
    q1.set_quaternion(2, 2, 2, 2);
    q.print();
    q1.print();

    qp = quat_plus(q, q1);
    qp.print();

    qp = quat_minus(q, q1);
    qp.print();

    qp = multiplication(q, q1);
    qp.print();

    qp = division(q, q1);
    qp.print();

    qp = scalar(q, q1);
    qp.print();

    qp = euclidean_distance(q, q1);
    qp.print();

    qp = chebyshev_norm(q, q1);
    qp.print();
    return 0;
}
