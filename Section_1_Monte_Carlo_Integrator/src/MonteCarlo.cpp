#include <iostream>
#include <cmath>
#include <random>
#include <functional>

bool InsideUnitSphere(double x, double y, double z)
{
    return ((x*x + y*y + z*z) <= 1);
}

double IntegrateMonteCarlo3D(int n_points, double min, double max, int seed, std::function<bool(double, double, double)> test_point)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    std::uniform_real_distribution<double> uni_dist(-1.0, 1.0);
    std::mt19937 rng_mt(seed);
    auto rand_real = std::bind(uni_dist, rng_mt);  // Limits amount of typing

    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = rand_real;
        double y = rand_real;
        double z = rand_real;
        if(test_point(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Give me a seed you donut." << std::endl;
        return -1;
    }
    int seed = std::stoi(argv[1]);
    int N_points = 10000;
    
    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0, seed, InsideUnitSphere);

    std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;
}