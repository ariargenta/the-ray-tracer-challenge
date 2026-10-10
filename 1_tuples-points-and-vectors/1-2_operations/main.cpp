#include <iostream>
#include <cassert>

class vec4 {
    public:
        double e[4];

        vec4() : e{0, 0, 0, 0} {}
        vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }
        double w() const { return e[3]; }

        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }
};


inline vec4 operator+(const vec4& u, const vec4& v) {
    return vec4(
        u.e[0] + v.e[0]
        , u.e[1] + v.e[1]
        , u.e[2] + v.e[2]
        , u.e[3] + v.e[3]
    );
}

inline vec4 operator-(const vec4& u, const vec4& v) {
    return vec4(
        u.e[0] - v.e[0]
        , u.e[1] - v.e[1]
        , u.e[2] - v.e[2]
        , u.e[3] - v.e[3]
    );
}

inline vec4 operator*(double t, const vec4& v) {
    return vec4(t * v.e[0], t * v.e[1], t * v.e[2], t * v.e[3]);
}

inline vec4 operator*(const vec4& v, double t) {
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

int main(int argc, char* argv[]) {
    test_vector_addition();

    return EXIT_SUCCESS;
}