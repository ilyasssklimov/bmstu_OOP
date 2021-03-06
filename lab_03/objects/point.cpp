#include "point.hpp"

#include <vector>
#include <math.h>

using namespace std;

Point::Point() {}


Point::Point(const double x, const double y, const double z): x(x), y(y), z(z) {}


void Point::reform(const std::shared_ptr<Matrix<double>> mtr)
{
    vector<double> result(4, 0);
    vector<double> data = {x, y, z, 1.0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            result[i] += data[j] * (*mtr)[i][j];

    set_x(result[0]);
    set_y(result[1]);
    set_z(result[2]);
}


Point Point::deg_to_rad() const
{
    Point radians(x, y, z);
    radians.set_x(x * M_PI / 180);
    radians.set_y(y * M_PI / 180);
    radians.set_z(z * M_PI / 180);

    return radians;
}
