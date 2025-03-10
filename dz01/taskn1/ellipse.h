#pragma once

class Ellipse {
public:
    double centerX, centerY, semiMajor, semiMinor;
    bool isXAxis;

public:
    Ellipse(double centerX = 0, double centerY = 0, double semiMajor = 0, double semiMinor = 0, bool isXAxis = true);
    Ellipse(const Ellipse &other);
    ~Ellipse();
    void adjustAxes(double &semiMajor, double &semiMinor);
    double computeHyperparameter();
    void setParameters(double centerX, double centerY, double semiMajor, double semiMinor, bool isXAxis);
    void getParameters(double &centerX, double &centerY, double &semiMajor, double &semiMinor, bool &isXAxis);
    void displayPoints();
    void displayFoci();
    void computeChordLength();
    void computeEccentricity();
    void showData();
    void checkPointPosition(double x, double y);
    double calculatePerimeter();
    double calculateArea();
    double findCoordinate(double value, bool isXGiven);
};
  
