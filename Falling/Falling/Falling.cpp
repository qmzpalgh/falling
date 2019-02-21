#include <iostream>
#include <math.h>
#define G 6.67408 * pow(10, -11)
#define EARTH_MASS 5.972 * pow(10, 24)
#define EARTH_RADIUS 6.371 * pow(10, 6)

double Fg(double m1, double m2, double r)
{
    return -(G * m1 * m2 / pow(r, 2));
}

double Fd(double density, double speed, double area, double drag_coefficient)
{
    return 0.5 * pow(density * speed, 2) * drag_coefficient * area;
}

double air_density(double altitude)
{
    //return ((100000 - altitude) / 100000) * 1.225;// VERY basic linear air density formula, take with grain of salt
    return 1.225 * pow(10, -altitude / 11000 );
}

int main()
{
    double altitude = 100000;
    double mass = 80.0;
    double fg = 0.0;  //force of gravity
    double v = 0.0;//initial velocity
    double fd = 0.0;  //force of drag
    double a = 0.0;
	std::cout << "Calculating\n" << std::endl;
    int seconds = 0;
    while (altitude > 0.0) {
        fg = Fg(mass, EARTH_MASS, EARTH_RADIUS + altitude);
        fd = Fd(air_density(altitude), v, 1.0, 0.5);
        a = (fg + fd) / mass;
        altitude += v;
        v += a;
        seconds++;
        if (altitude < 0.0) {
            altitude = 0.0;
        }
		std::cout << v << std::endl;
    }
	std::cout << "Altitude: " << altitude << "\nVelocity: " << v << "\nit took " << seconds << " seconds" << std::endl;
    return 0;
}
