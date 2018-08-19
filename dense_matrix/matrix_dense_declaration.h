#pragma once

#include <memory>

namespace sepolia {

    template<typename T>
    class matrix_dense {

    public:

        explicit matrix_dense<T>();

        explicit matrix_dense<T>(const uint64_t &rows,
                                 const uint64_t &cols,
                                 const T &val = 0);

        matrix_dense<T>(const matrix_dense<T> &);

        matrix_dense<T>(matrix_dense<T> &&) noexcept;

        virtual ~matrix_dense();

        uint64_t rows() const;

        uint64_t columns() const;

        void allocate(const uint64_t &, const uint64_t &);

        bool allocated() const;

        void deallocate();

        bool deallocated() const;

        // operators

        matrix_dense<T> &operator=(const matrix_dense<T> &);

        matrix_dense<T> &operator=(const T &);

        matrix_dense<T> &operator=(matrix_dense<T> &&) noexcept;

        T &operator()(const uint64_t &, const uint64_t &) const;

        matrix_dense<T> operator+(const matrix_dense<T> &) const;

        matrix_dense<T> operator+(const T &) const;

        template<typename T2>
        friend matrix_dense<T2> operator+(const T2 &,
                                          const matrix_dense<T2> &);

        matrix_dense<T> operator-(const matrix_dense<T> &) const;

        matrix_dense<T> operator-(const T &) const;

        template<typename T2>
        friend matrix_dense<T2> operator-(const T2 &,
                                          const matrix_dense<T2> &);

        matrix_dense<T> operator*(const matrix_dense<T> &) const;

        matrix_dense<T> operator*(const T &) const;

        template<typename T2>
        friend matrix_dense<T2> operator*(const T2 &,
                                          const matrix_dense<T2> &);

        matrix_dense<T> operator/(const matrix_dense<T> &) const;

        matrix_dense<T> operator/(const T &) const;

        template<typename T2>
        friend matrix_dense<T2> operator/(const T2 &,
                                          const matrix_dense<T2> &);

        matrix_dense<T> operator+=(const matrix_dense<T> &);

        matrix_dense<T> operator+=(const T &);

        matrix_dense<T> operator-=(const matrix_dense<T> &);

        matrix_dense<T> operator-=(const T &);

        matrix_dense<T> operator*=(const matrix_dense<T> &);

        matrix_dense<T> operator*=(const T &);

        matrix_dense<T> operator/=(const matrix_dense<T> &);

        matrix_dense<T> operator/=(const T &);

        matrix_dense<T> operator++();

        const matrix_dense<T> operator++(int);

        matrix_dense<T> operator--();

        const matrix_dense<T> operator--(int);

        bool operator==(const matrix_dense<T> &) const;

        bool operator==(const T &) const;

        template<typename T2>
        friend bool operator==(const T2 &, const matrix_dense<T2> &);

        bool operator!=(const matrix_dense<T> &) const;

        bool operator!=(const T &) const;

        template<typename T2>
        friend bool operator!=(const T2 &, const matrix_dense<T2> &);

        T *begin();

        const T *begin() const;

        T *end();

        const T *end() const;

        const T &at(const uint64_t &, const uint64_t &) const;

        void swap(matrix_dense<T> &);

        bool empty() const;

    private:

        void set(const T &);

        void set(const matrix_dense<T> &);

        matrix_dense<T> plus(const matrix_dense<T> &) const;

        matrix_dense<T> plus(const T &) const;

        matrix_dense<T> subtract(const matrix_dense<T> &) const;

        matrix_dense<T> subtract(const T &) const;

        matrix_dense<T> times(const matrix_dense<T> &) const;

        matrix_dense<T> times(const T &) const;

        matrix_dense<T> divide(const matrix_dense<T> &) const;

        matrix_dense<T> divide(const T &) const;

        bool equal(const matrix_dense<T> &) const;

        bool equal(const T &) const;

    private:

        uint64_t _rows;
        uint64_t _columns;
        bool _allocated;
        std::shared_ptr<T> _mdsp;
    };
}
