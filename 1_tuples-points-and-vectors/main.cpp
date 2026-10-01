#include <iostream>
#include <tuple>
#include <vector>

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
std::tuple<float, float, float, float> make_point(
    float x
    , float y
    , float z
    , float w
) {
    return std::make_tuple(x, y, z, w);
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
    , float w
) {
    static std::vector<float> A = {x, y, z, w};

    return A;
}

int main(int argc, char* argv[]) {
    float x = 4.3;
    float y = -4.2;
    float z = 3.1;
    float w = 1.0;

    auto a = make_point(x, y, z, w);

    std::cout << "A tuple with w = 1.0 is a point" << std::endl;
    std::cout << "a.x = " << get<0>(a) << std::endl;
    std::cout << "a.y = " << get<1>(a) << std::endl;
    std::cout << "a.z = " << get<2>(a) << std::endl;
    std::cout << "a.w = " << get<3>(a) << std::endl;

    std::vector<float> A = make_vector(x, y, z, w);

    for(int i = 0; i < A.size(); ++i) {
        std::cout << A[i] << std::endl;
    }

    return EXIT_SUCCESS;
}