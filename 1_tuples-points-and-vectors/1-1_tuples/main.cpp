#include <iostream>
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
void test_point() {
    Point test_point = make_point(4, -4, 3);

    assert(
        test_point.x == 4.0
        && test_point.y == -4.0
        && test_point.z == 3.0
        && test_point.w == 1.0
    );

    std::cout << "Test point passed" << std::endl;
}

/*
 * Scenario: `vector()` creates tuples with w = 0
 * Given v <- vector(4, -4, 3)
 * Then v = tuple(4, -4, 3, 0)
 */
void test_vector() {
    std::vector test_vector = make_vector(4.0, -4.0, 3.0, 0.0);

    assert(
        test_vector[0] == 4.0
        && test_vector[1] == -4.0
        && test_vector[2] == 3.0
        && test_vector[3] == 0.0
    );

    std::cout << "Test vector passed" << std::endl;
}

int main(int argc, char* argv[]) {
    test_point();
    test_vector();

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