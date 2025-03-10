
#include <iostream>
#include <cmath>
#include "ellipse.h"

using namespace std;

Ellipse::Ellipse(double centerX, double centerY, double semiMajor, double semiMinor, bool isXAxis)
{
    this->centerX = centerX;
    this->centerY = centerY;
    this->semiMajor = semiMajor;
    this->semiMinor = semiMinor;
    this->isXAxis = isXAxis;
    adjustAxes(this->semiMinor, this->semiMajor);
}

Ellipse::Ellipse(const Ellipse &other)
{
    centerX = other.centerX;
    centerY = other.centerY;
    semiMajor = other.semiMajor;
    semiMinor = other.semiMinor;
    isXAxis = other.isXAxis;
    adjustAxes(semiMinor, semiMajor);
}

Ellipse::~Ellipse() {}

void Ellipse::adjustAxes(double &minor, double &major)
{
    if (minor > major) swap(minor, major);
}

double Ellipse::computeHyperparameter()
{
    return sqrt(pow(semiMajor, 2) - pow(semiMinor, 2));
}

void Ellipse::setParameters(double centerX, double centerY, double semiMajor, double semiMinor, bool isXAxis)
{
    this->centerX = centerX;
    this->centerY = centerY;
    this->semiMajor = semiMajor;
    this->semiMinor = semiMinor;
    this->isXAxis = isXAxis;
}

void Ellipse::getParameters(double &centerX, double &centerY, double &semiMajor, double &semiMinor, bool &isXAxis)
{
    centerX = this->centerX;
    centerY = this->centerY;
    semiMajor = this->semiMajor;
    semiMinor = this->semiMinor;
    isXAxis = this->isXAxis;
}

void Ellipse::displayPoints()
{
    if (isXAxis)
        cout << "V1(" << centerX - semiMajor << ", " << centerY << ")\n"
             << "V2(" << centerX + semiMajor << ", " << centerY << ")" << endl;
    else
        cout << "V1(" << centerX << ", " << centerY - semiMajor << ")\n"
             << "V2(" << centerX << ", " << centerY + semiMajor << ")" << endl;
}

void Ellipse::displayFoci()
{
    double f = computeHyperparameter();
    if (isXAxis)
        cout << "F1(" << centerX - f << ", " << centerY << ")\n"
             << "F2(" << centerX + f << ", " << centerY << ")" << endl;
    else
        cout << "F1(" << centerX << ", " << centerY - f << ")\n"
             << "F2(" << centerX << ", " << centerY + f << ")" << endl;
}

void Ellipse::computeChordLength()
{
    cout << "LR = " << (2 * pow(semiMinor, 2)) / semiMajor << endl;
}

void Ellipse::computeEccentricity()
{
    cout << "e = " << computeHyperparameter() / semiMajor << endl;
}

void Ellipse::showData()
{
    cout << "\n-----------DATA-----------" << endl;
    cout << "(x - " << centerX << ")^2 / " << pow(semiMajor, 2) << " + (y - " << centerY << ")^2 / " << pow(semiMinor, 2) << " = 1\n";
    cout << "C(" << centerX << ", " << centerY << ")" << endl;
    displayPoints();
    displayFoci();
}

void Ellipse::checkPointPosition(double x, double y)
{
    double val = isXAxis ? pow((x - centerX) / semiMajor, 2) + pow((y - centerY) / semiMinor, 2)
                         : pow((x - centerX) / semiMinor, 2) + pow((y - centerY) / semiMajor, 2);
    if (val < 1)
        cout << "Point is inside the ellipse" << endl;
    else if (val == 1)
        cout << "Point is on the ellipse" << endl;
    else
        cout << "Point is outside the ellipse" << endl;
}

double Ellipse::calculatePerimeter()
{
    return M_PI * (3 * (semiMajor + semiMinor) - sqrt((3 * semiMajor + semiMinor) * (semiMajor + 3 * semiMinor)));
}

double Ellipse::calculateArea()
{
    return M_PI * semiMajor * semiMinor;
}

double Ellipse::findCoordinate(double value, bool isXGiven)
{
    if (isXGiven)
        return isXAxis ? ((semiMinor / semiMajor) * sqrt(pow(semiMajor, 2) - pow(value - centerX, 2))) + centerY
                       : ((semiMajor / semiMinor) * sqrt(pow(semiMinor, 2) - pow(value - centerX, 2))) + centerY;
    else
        return isXAxis ? ((semiMajor / semiMinor) * sqrt(pow(semiMinor, 2) - pow(value - centerY, 2))) + centerX
                       : ((semiMinor / semiMajor) * sqrt(pow(semiMajor, 2) - pow(value - centerY, 2))) + centerX;
}
