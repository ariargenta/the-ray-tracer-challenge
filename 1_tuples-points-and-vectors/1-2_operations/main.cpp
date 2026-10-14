#include <iostream>
#include <cassert>
#include <stdexcept>

class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        double operator[](int i) const {
            if(i < 0 || i >= 3) {
                throw std::out_of_range("vec3 is out of range");
            }

            return e[i];
        }

        double& operator[](int i) {
            if(i < 0 || i >= 3) {
                throw std::out_of_range("vec3 is out of range");
            }
            return e[i];
        }

        vec3 operator-() const {
            return vec3(-e[0], -e[1], -e[2]);
        }

        vec3& operator+=(const vec3& v) {
            e[0] += v.x();
            e[1] += v.y();
            e[2] += v.z();

            return *this;
        }

        vec3& operator-=(const vec3& v)  {
            e[0] -= v.x();
            e[1] -= v.y();
            e[2] -= v.z();

            return *this;
        }
};


inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(
        u.e[0] + v.e[0]
        , u.e[1] + v.e[1]
        , u.e[2] + v.e[2]
    );
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(
        u.e[0] - v.e[0]
        , u.e[1] - v.e[1]
        , u.e[2] - v.e[2]
    );
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

/*
 * Scenario: Adding two tuples
 * Given a1 <- tuple(3, -2, 5, 1)
 * And a2 <- tuple(-2, 3, 1, 0)
 * Then a1 + a2 = tuple(1, 1, 6, 1)
 */
void test_vector_addition() {
    vec4 a1 = {3.0, -2.0, 5.0, 1.0};
    vec4 a2 = {-2.0, 3.0, 1.0, 0.0};

    vec4 test = a1 + a2;

    assert(
        test.x() == 1.0
        && test.y() == 1.0
        && test.z() == 6.0
        && test.w() == 1.0
    );

    std::cout << "Test addition OK" << std::endl;
}

/*
 * Scenario: Subtracting two points
 * Given p1 <- point(3, 2, 1)
 * And p2 <- point(5, 6, 7)
 * Then p1 - p2 = vector(-2, -4, -6)
 */
void test_vector_substraction() {
    vec4 p1 = {3.0, 2.0, 1.0, 1.0};
    vec4 p2 = {5.0, 6.0, 7.0, 1.0};

    vec4 test = p1 - p2;

    assert(
        test.x() == -2.0
        && test.y() == -4.0
        && test.z() == -6.0
        && test.w() == 0.0
    );

    std::cout << "Test substraction OK" << std::endl;
}

int main(int argc, char* argv[]) {
    test_vector_addition();
    test_vector_substraction();

    return EXIT_SUCCESS;
}