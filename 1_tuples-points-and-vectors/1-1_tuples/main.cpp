#include <iostream>
#include <tuple>
#include <vector>
#include <cassert>

/*
 * Scenario: A tuple with w = 1.0 is a point
 * Given a <- tuple(4.3, -4.2, 3.1, 1.0)
 * Then a.x = 4.3
 * And a.y = -4.2
 * And a.z = 3.1
 * And a.w = 1.0
 * And a is a point
 * And a is not a vector
 */

struct Point {
    float x;
    float y;
    float z;
    float w;
};

Point make_point(float x, float y , float z , float w = 1.0) {
    Point point;

    point.x = x;
    point.y = y;
    point.z = z;
    point.w = w;

    return point;
}

/*
 * Scenario: A tuple with w = 0 is a vector
 * Given a <- tuple(4.3, -4.2, 3.1, 0.0)
 * Then a.x = 4.3
 * And a.y = -4.2
 * And a.z = 3.1
 * And a.w = 0.0
 * And a is not a point
 * And a is a vector
 */
std::vector<float>& make_vector(
    float x
    , float y
    , float z
    , float w = 0.0
) {
    static std::vector<float> A = {x, y, z, w};

    return A;
}

/*
 * Scenario: `point()` creates tuples with w = 1
 * Given p <- point(4, -4, 3)
 * Then p = tuple(4, -4, 3, 1)
 */

/*
 * Scenario: `vector()` creates tuples with w = 0
 * Given v <- vector(4, -4, 3)
 * Then v = tuple(4, -4, 3, 0)
 */

int main(int argc, char* argv[]) {
    float x = 4.3;
    float y = -4.2;
    float z = 3.1;

    Point a = make_point(x, y, z);

    std::cout << "A tuple with w = 1.0 is a point" << std::endl;
    std::cout << "a.x = " << a.x << std::endl;
    std::cout << "a.y = " << a.y << std::endl;
    std::cout << "a.z = " << a.z << std::endl;
    std::cout << "a.w = " << a.w << std::endl;

    std::vector<float> A = make_vector(x, y, z);

    for(int i = 0; i < A.size(); ++i) {
        std::cout << A[i] << std::endl;
    }

    return EXIT_SUCCESS;
}