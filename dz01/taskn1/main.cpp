#include <iostream>
#include <cmath>
#include "ellipse.h"
#include "ellipse.cpp"

using namespace std;

int main()
{
    Ellipse ellipse1, ellipse2;
    
    ellipse1 = Ellipse(1, 2, 3, 4, true);
    ellipse2 = ellipse1;
    
    cout << "Calculated hyperparameter: " << ellipse1.count_hyperparametr() << endl;
    
    cout << "\nКлючевые координаты эклипса:" << endl;
    ellipse1.point_coordinates();
    ellipse1.focus_coordinates();
    
    ellipse1.print_data();
    
    cout << "\nВзаимное расположение для точки (-3, 2):" << endl;
    ellipse1.inside_status(-3, 2);
    
    cout << "\nEllipse perimeter and area:" << endl;
    cout << "Perimeter = " << ellipse1.calculate_perimeter() << "\n"
         << "Area = " << ellipse1.calculate_square() << "\n" << endl;
    
    ellipse1.count_loc_hord();
    ellipse1.count_excentritet();
    
    cout << "Missing coordinate for input 5: " << ellipse1.calculate_coord(5, true) << endl;
    
    cout << "\nUpdating and retrieving parameters:" << endl;
    ellipse1.set_all(5, 6, 7, 8, false);
    
    double centerX, centerY, semiMajor, semiMinor;
    bool isXAxis;
    ellipse1.get_all(centerX, centerY, semiMajor, semiMinor, isXAxis);
    
    cout << "Center X: " << centerX << endl;
    cout << "Center Y: " << centerY << endl;
    cout << "Semi-major axis: " << semiMajor << endl;
    cout << "Semi-minor axis: " << semiMinor << endl;
    cout << "Major axis along X: " << isXAxis << endl;
    
    return 0;
}

