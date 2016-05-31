#pragma once

#include <Veritas/Data/Array.h>

// Implement the idea of negative elements
// +A + -A = 0
// -A + -A = -A
// +A + +A = +A
// How to implement Universe with non-discrete elements (e.g. Real - float)?

namespace Veritas {
    namespace Math {
        template <class T>
        class Set {
            public:
                static Set Universe() {
                    uint64 nelements = 1 << (8 * sizeof(T));
                    Set set(nelements);
                    for (uint64 i = 0; i < nelements; i++)
                        set[i] = i;
                    return set;
                }

                Set() {}

                uint32 getSize() const { return elements.getSize(); }
                T& operator[](uint32 index) { return elements[index]; }
                const T& operator[](uint32 index) const { return elements[index]; }

                Set& add(const T& t) {
                    operator+=(t);
                    return *this;
                }
                Set& remove(const T& t) {
                    operator-=(t);
                    return *this;
                }

                bool contains(const T& t) const {
                    for (uint32 i = 0; i < elements.getSize(); i++)
                        if (elements[i] == t) return true;
                    return false;
                }

                bool contains(const Set& set) const {
                    for (uint32 i = 0; i < set.getSize(); i++)
                        if (!contains(set[i])) return false;
                    return true;
                }

                Set operator+(const T& t) const {
                    Set copy = *this;
                    copy += t;
                    return copy;
                }
                Set operator-(const T& t) const {
                    Set copy = *this;
                    copy -= t;
                    return copy;
                }

                Set operator+(const Set& set) const {
                    Set copy = *this;
                    copy += set;
                    return copy;
                }
                Set operator-(const Set& set) const {
                    Set copy = *this;
                    copy -= set;
                    return copy;
                }
                Set operator*(const Set& set) const {
                    Set copy = *this;
                    copy *= set;
                    return copy;
                }

                void operator+=(const T& t) {
                    if (contains(t)) return;

                    elements.setSize(elements.getSize() + 1);
                    new(&elements[elements.getSize() - 1])T(t);
                }

                void operator-=(const T& t) {
                    for (uint32 i = 0; i < elements.getSize(); i++)
                        if (elements[i] == t) {
                            std::swap(elements[i], elements[elements.getSize() - 1]);
                            elements.setSize(elements.getSize() - 1);
                        }
                }

                void operator+=(const Set& set) {
                    for (uint32 i = 0; i < set.getSize(); i++)
                        operator+=(set[i]);
                }

                void operator-=(const Set& set) {
                    for (uint32 i = 0; i < set.getSize(); i++)
                        operator-=(set[i]);
                }

                void operator*=(const Set& set) {
                    for (uint32 i = 0; i < getSize(); i++)
                        if (!set.contains(operator[](i)))
                            operator-=(operator[](i));
                }

                bool operator==(const Set& set) const {
                    if (getSize() != set.getSize()) return false;
                    for (uint32 i = 0; i < set.getSize(); i++)
                        if (operator[](i) != set[i])
                            return false;
                    return true;
                }
            private:
                Set(uint32 size) : elements(size) {}

                Veritas::Data::Array<T> elements;
        };
    }
}
