#pragma once
#include <string>
#include <cassert>
#ifdef WIN32
    #undef min
    #undef max
#endif

namespace wear {



    template < typename T > void swap(T& src, T& nsrc)
    {
        T temp = nsrc, nsrc = src, src = temp;
    } // Changes the value of two data types
    auto precent(double x, double y)
    {
        return x / 100 * y;
    } // Returns a percentage of the number

    template < typename T > T max(T x, T y)
    {
        return x < y ? y : x;
    } // Returns the maximum value

    template < typename T > T min(T x, T y)
    {
        return x > y ? y : x;
    } // Returns the minimum value

    unsigned CRHash(const std::string text) // Constant string hashing
    {
        unsigned hash{ 1315423911 };

        for (std::size_t i = 0; i < text.length(); i++)
            hash ^= ((hash << 5) + text[i] + (hash >> 2));

        return (hash & 0x7FFFFFFF);
    }

    unsigned RHash(std::string text) // string hashing
    {
        unsigned int B{ 378551 }, A{ 63689 }, H{ NULL };

        for (std::size_t i = 0; i < text.length(); ++i)
            H = H * A + text[i], A = A * B;

        return (H & 0x7FFFFFFF);
    }

    struct Vector3 {
        double x{ 0 }, y{ 0 }, z{ 0 };
        Vector3() {}
        Vector3(double _x, double _y, double _z)
        {
            x = _x; _y = y; _z;
        }
        Vector3(Vector2 vec2, double z) { x = vec2.x; y = vec2.y; this->z = z; }
        Vector3(double x, Vector2 vec2) { this->x = x; y = vec2.x; z = vec2.y; }
        Vector3 min(Vector3 firstVector3, Vector3 secondVector3) {
            return Vector3(wear::min(firstVector3.x, secondVector3.x),
                           wear::min(firstVector3.y, secondVector3.y),
                           wear::min(firstVector3.x, secondVector3.x));
        }
        Vector3 max(Vector3 firstVector3, Vector3 secondVector3) {
            return Vector3(wear::max(firstVector3.x, secondVector3.x),
                           wear::max(firstVector3.y, secondVector3.y),
                           wear::max(firstVector3.x, secondVector3.x));
        }
        void swap(Vector3 firstVector3, Vector3 secondVector3)
        {
            wear::swap(firstVector3.x, secondVector3.x);
            wear::swap(firstVector3.y, secondVector3.y);
            wear::swap(firstVector3.z, secondVector3.z);
        }
        void operator+=(Vector3 vec3) { x += vec3.x; y += vec3.y; z += vec3.z; }
        void operator-=(Vector3 vec3) { x -= vec3.x; y -= vec3.y; z -= vec3.z; }
        void operator/=(Vector3 vec3) { x /= vec3.x; y /= vec3.y; z /= vec3.z; }
        void operator*=(Vector3 vec3) { x *= vec3.x; y *= vec3.y; z *= vec3.z; }
    };

    struct Vector2 {
        double x, y;
        Vector2() {}
        Vector2(double _x, double _y) { x = _x; y = _y; }
        Vector2(Vector3 vec3) { x = vec3.x; y = vec3.y; }
        void operator+=(Vector2 vec3) { x += vec3.x; y += vec3.y; }
        void operator-=(Vector2 vec3) { x -= vec3.x; y -= vec3.y; }
        void operator/=(Vector2 vec3) { x /= vec3.x; y /= vec3.y; }
        void operator*=(Vector2 vec3) { x *= vec3.x; y *= vec3.y; }
    };

} // namespace wear