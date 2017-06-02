#pragma once

#include <Veritas/Definitions/Definitions.h>
#include <ostream>

namespace Veritas {
    namespace Math {
        template <class T>
        class vec2T {
            public:
                vec2T() {}
                vec2T(T value) : x(value), y(value) {}
                vec2T(T x, T y) : x(x), y(y) {}
                T x, y;
        };
        typedef vec2T<int32> ivec2;
        typedef vec2T<uint32> uvec2;
    }
}

namespace Veritas {
    namespace Math {
        class vec2 {
            public:
                vec2();
                vec2(float32 value);
                vec2(float32 x, float32 y);

                vec2 operator+(float32 s) const;
                vec2 operator-(float32 s) const;
                vec2 operator*(float32 s) const;
                vec2 operator/(float32 s) const;

                void operator+=(float32 s);
                void operator-=(float32 s);
                void operator*=(float32 s);
                void operator/=(float32 s);

                vec2 operator+(const vec2& v) const;
                vec2 operator-(const vec2& v) const;
                vec2 operator*(const vec2& v) const;
                vec2 operator/(const vec2& v) const;

                void operator+=(const vec2& v);
                void operator-=(const vec2& v);
                void operator*=(const vec2& v);
                void operator/=(const vec2& v);

                vec2 operator-() const;

                bool operator==(const vec2& v) const;
                bool operator!=(const vec2& v) const;

                float32 x, y;
        };
    }
}

Veritas::Math::vec2 operator*(const float32 s, const Veritas::Math::vec2& v);

std::ostream& operator<<(std::ostream &os, const Veritas::Math::vec2& v);
