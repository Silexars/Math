#include <Veritas/Math/vec3.h>
#include <Veritas/Math/functions.h>

using namespace Veritas::Math;

vec3::vec3() {}
vec3::vec3(float32 value) : x(value), y(value), z(value) { }
vec3::vec3(float32 x, float32 y, float32 z) : x(x), y(y), z(z) { }
vec3::vec3(const vec2 &xy, float32 z) : x(xy.x), y(xy.y), z(z) { }

vec3::vec3(float32 x, const vec2 &yz) : x(x), y(yz.x), z(yz.y) { }

vec3 vec3::operator+(float32 s) const { return vec3(x+s, y+s, z+s); }
vec3 vec3::operator-(float32 s) const { return vec3(x-s, y-s, z-s); }
vec3 vec3::operator*(float32 s) const { return vec3(x*s, y*s, z*s); }
vec3 vec3::operator/(float32 s) const { return vec3(x/s, y/s, z/s); }

vec3 vec3::operator+(const vec3& v) const { return vec3(x+v.x, y+v.y, z+v.z); }
vec3 vec3::operator-(const vec3& v) const { return vec3(x-v.x, y-v.y, z-v.z); }
vec3 vec3::operator*(const vec3& v) const { return vec3(x*v.x, y*v.y, z*v.z); }
vec3 vec3::operator/(const vec3& v) const { return vec3(x/v.x, y/v.y, z/v.z); }

void vec3::operator+=(float32 s) { x += s; y += s; z += s; }
void vec3::operator-=(float32 s) { x -= s; y -= s; z -= s; }
void vec3::operator*=(float32 s) { x *= s; y *= s; z *= s; }
void vec3::operator/=(float32 s) { x /= s; y /= s; z /= s; }

void vec3::operator+=(const vec3& v) { x += v.x; y += v.y; z += v.z; }
void vec3::operator-=(const vec3& v) { x -= v.x; y -= v.y; z -= v.z; }
void vec3::operator*=(const vec3& v) { x *= v.x; y *= v.y; z *= v.z; }
void vec3::operator/=(const vec3& v) { x /= v.x; y /= v.y; z /= v.z; }

float32 vec3::length() const { return ::length(*this); }

void vec3::normalize() { operator/=(length()); }

vec3 vec3::operator-() const { return vec3(-x, -y, -z); }

bool vec3::operator==(const vec3& v) const { return x == v.x && y == v.y && z == v.z; }
bool vec3::operator!=(const vec3& v) const { return x != v.x || y != v.y || z != v.z; }

vec3 operator*(const float32 s, const vec3& v) { return v*s; }

std::ostream& operator<<(std::ostream &os, const vec3& v) {
    os << '(' << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
