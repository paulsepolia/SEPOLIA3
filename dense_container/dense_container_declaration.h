#pragma once

#include <memory>

namespace sepolia {

    template<typename T>
    class dense_container {

    public:

        explicit dense_container<T>();

        explicit dense_container<T>(const uint64_t &,const T &val = 0);

        dense_container<T>(const dense_container<T> &);

        dense_container<T>(dense_container<T> &&) noexcept;

    public:

        virtual ~dense_container();

        virtual void allocate(const uint64_t &);

        virtual bool allocated() const;

        virtual void deallocate();

        virtual bool deallocated() const;

        uint64_t size() const;

        // operators

        dense_container<T> &operator=(const dense_container<T> &);

        virtual dense_container<T> &operator=(const T &);

        dense_container<T> &operator=(dense_container<T> &&) noexcept;

        virtual T &operator()(const uint64_t &) const;

        virtual T &operator[](const uint64_t &) const;

        virtual dense_container<T> operator+(const dense_container<T> &) const;

        virtual dense_container<T> operator+(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator+(const T2 &,
                                             const dense_container<T2> &);

        virtual dense_container<T> operator-(const dense_container<T> &) const;

        virtual dense_container<T> operator-(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator-(const T2 &,
                                             const dense_container<T2> &);

        virtual dense_container<T> operator*(const dense_container<T> &) const;

        virtual dense_container<T> operator*(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator*(const T2 &,
                                             const dense_container<T2> &);

        virtual dense_container<T> operator/(const dense_container<T> &) const;

        dense_container<T> operator/(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator/(const T2 &,
                                             const dense_container<T2> &);

        virtual dense_container<T> operator+=(const dense_container<T> &);

        virtual dense_container<T> operator+=(const T &);

        virtual dense_container<T> operator-=(const dense_container<T> &);

        virtual dense_container<T> operator-=(const T &);

        virtual dense_container<T> operator*=(const dense_container<T> &);

        virtual dense_container<T> operator*=(const T &);

        virtual dense_container<T> operator/=(const dense_container<T> &);

        virtual dense_container<T> operator/=(const T &);

        virtual dense_container<T> operator++();

        virtual const dense_container<T> operator++(int);

        virtual dense_container<T> operator--();

        virtual const dense_container<T> operator--(int);

        virtual bool operator==(const dense_container<T> &) const;

        virtual bool operator==(const T &) const;

        template<typename T2>
        friend bool operator==(const T2 &, const dense_container<T2> &);

        virtual bool operator!=(const dense_container<T> &) const;

        virtual bool operator!=(const T &) const;

        template<typename T2>
        friend bool operator!=(const T2 &, const dense_container<T2> &);

        virtual T *begin();

        virtual const T *begin() const;

        virtual T *end();

        virtual const T *end() const;

        virtual const T &at(const uint64_t &) const;

        virtual const T &at(const uint64_t &, const uint64_t &) const;

        virtual void swap(dense_container<T> &);

        virtual bool empty() const;

    private:

        void set(const T &);

        void set(const dense_container<T> &);

        dense_container<T> plus(const dense_container<T> &) const;

        dense_container<T> plus(const T &) const;

        dense_container<T> subtract(const dense_container<T> &) const;

        dense_container<T> subtract(const T &) const;

        dense_container<T> times(const dense_container<T> &) const;

        dense_container<T> times(const T &) const;

        dense_container<T> divide(const dense_container<T> &) const;

        dense_container<T> divide(const T &) const;

        virtual bool equal(const dense_container<T> &) const;

        virtual bool equal(const T &) const;

    private:

        uint64_t _dimension;
        bool _allocated;
        std::shared_ptr<T> _dsp;
    };
}
