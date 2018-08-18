#pragma once

#include <vector>
#include <memory>

namespace sepolia {

    template<typename T>
    class vector_dense {

    public:

        explicit vector_dense<T>();

        explicit vector_dense<T>(const uint64_t &dim, const T &val = 0);

        vector_dense<T>(const vector_dense<T> &);

        vector_dense<T>(vector_dense<T> &&) noexcept;

        virtual ~vector_dense();

        uint64_t size() const;

        void allocate(const uint64_t &);

        bool allocated() const;

        void deallocate();

        bool deallocated() const;

        // operators

        vector_dense<T> &operator=(const std::vector<T> &);

        vector_dense<T> &operator=(std::vector<T> &&);

        vector_dense<T> &operator=(const vector_dense<T> &);

        vector_dense<T> &operator=(const T &);

        vector_dense<T> &operator=(vector_dense<T> &&) noexcept;

        T &operator()(const uint64_t &) const;

        T &operator[](const uint64_t &) const;

        vector_dense<T> operator+(const vector_dense<T> &) const;

        vector_dense<T> operator+(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator+(const T2 &,
                                          const vector_dense<T2> &);

        vector_dense<T> operator-(const vector_dense<T> &) const;

        vector_dense<T> operator-(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator-(const T2 &,
                                          const vector_dense<T2> &);

        vector_dense<T> operator*(const vector_dense<T> &) const;

        vector_dense<T> operator*(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator*(const T2 &,
                                          const vector_dense<T2> &);

        vector_dense<T> operator/(const vector_dense<T> &) const;

        vector_dense<T> operator/(const T &) const;

        template<typename T2>
        friend vector_dense<T2> operator/(const T2 &,
                                          const vector_dense<T2> &);

        vector_dense<T> operator+=(const vector_dense<T> &);

        vector_dense<T> operator+=(const T &);

        vector_dense<T> operator-=(const vector_dense<T> &);

        vector_dense<T> operator-=(const T &);

        vector_dense<T> operator*=(const vector_dense<T> &);

        vector_dense<T> operator*=(const T &);

        vector_dense<T> operator/=(const vector_dense<T> &);

        vector_dense<T> operator/=(const T &);

        vector_dense<T> operator++();

        const vector_dense<T> operator++(int);

        vector_dense<T> operator--();

        const vector_dense<T> operator--(int);

        bool operator==(const vector_dense<T> &) const;

        bool operator==(const T &) const;

        template<typename T2>
        friend bool operator==(const T2 &, const vector_dense<T2> &);

        bool operator!=(const vector_dense<T> &) const;

        bool operator!=(const T &) const;

        template<typename T2>
        friend bool operator!=(const T2 &, const vector_dense<T2> &);

        T *begin();

        const T *begin() const;

        T *end();

        const T *end() const;

    private:

        uint64_t _dimension;
        bool _allocated;
        std::shared_ptr<T> _vdsp;

        void set(const T &);

        void set(const vector_dense<T> &);

        vector_dense<T> plus(const vector_dense<T> &) const;

        vector_dense<T> plus(const T &) const;

        vector_dense<T> subtract(const vector_dense<T> &) const;

        vector_dense<T> subtract(const T &) const;

        vector_dense<T> times(const vector_dense<T> &) const;

        vector_dense<T> times(const T &) const;

        vector_dense<T> divide(const vector_dense<T> &) const;

        vector_dense<T> divide(const T &) const;

        bool equal(const vector_dense<T> &) const;

        bool equal(const T &) const;
    };
}
