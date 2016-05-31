#pragma once

#include <Veritas/Definitions/Definitions.h>

namespace Veritas {
    namespace Math {
        class Complex {
            public:
                Complex();
                Complex(float32 a, float32 b);

                float32 a, b;

                Complex operator+(const Complex& v) const;
                Complex operator-(const Complex& v) const;
                Complex operator*(const Complex& v) const;
                Complex operator/(const Complex& v) const;

                Complex operator+(const float32 s) const;
                Complex operator-(const float32 s) const;
                Complex operator*(const float32 s) const;
                Complex operator/(const float32 s) const;

                void operator+=(const Complex& v);
                void operator-=(const Complex& v);
                void operator*=(const Complex& v);
                void operator/=(const Complex& v);

                void operator+=(const float32 s);
                void operator-=(const float32 s);
                void operator*=(const float32 s);
                void operator/=(const float32 s);

                Complex operator-() const;

                void conjugate();
        };
    }
}

Veritas::Math::Complex operator+(const float32 s, const Veritas::Math::Complex& c);
Veritas::Math::Complex operator-(const float32 s, const Veritas::Math::Complex& c);
Veritas::Math::Complex operator*(const float32 s, const Veritas::Math::Complex& c);
Veritas::Math::Complex operator/(const float32 s, const Veritas::Math::Complex& c);
