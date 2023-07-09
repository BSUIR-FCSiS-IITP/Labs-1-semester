#include <iostream>
#include <limits>

template <typename T>

class Vector {
private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;

public:
    class Iterator {
    public:
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        explicit Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }

        pointer operator->() { return m_ptr; }

        Iterator& operator++() {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            m_ptr--;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*(&(*this)));
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.m_ptr == b.m_ptr;
        }

        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.m_ptr != b.m_ptr;
        }

        friend bool operator<(const Iterator& a, const Iterator& b) {
            return a.m_ptr < b.m_ptr;
        }

        friend bool operator>(const Iterator& a, const Iterator& b) {
            return a.m_ptr > b.m_ptr;
        }

        friend bool operator<=(const Iterator& a, const Iterator& b) {
            return a.m_ptr <= b.m_ptr;
        }

        friend bool operator>=(const Iterator& a, const Iterator& b) {
            return a.m_ptr >= b.m_ptr;
        }

        friend Iterator operator+(Iterator iter, difference_type n) {
            return Iterator(iter.m_ptr + n);
        }

        friend Iterator operator-(Iterator iter, difference_type n) {
            return Iterator(iter.m_ptr - n);
        }

        friend Iterator operator+(difference_type n, Iterator iter) {
            return Iterator(iter.m_ptr + n);
        }

        friend difference_type operator-(const Iterator& a, const Iterator& b) {
            return a.m_ptr - b.m_ptr;
        }

        Iterator& operator+=(difference_type n) {
            m_ptr += n;
            return *this;
        }

        Iterator& operator-=(difference_type n) {
            m_ptr -= n;
            return *this;
        }

        reference operator[](difference_type n) const {
            return *(m_ptr + n);
        }

    private:
        pointer m_ptr;
    };

    using iterator = Iterator;
    using const_iterator = const Iterator;
    using difference_type = std::ptrdiff_t;

    Vector() : m_size(0), m_capacity(0), m_data(nullptr) {}

    explicit Vector(size_t size) : m_size(size), m_capacity(size), m_data(new T[size]) {}

    Vector(size_t size, const T &value) : m_size(size), m_capacity(size), m_data(new T[size]) {
        for (size_t i = 0; i < size; ++i) {
            m_data[i] = value;
        }
    }

    Vector(const Vector &other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[other.m_capacity]) {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    Vector &operator=(const Vector &other) {
        if (this != &other) {
            T *tmp = new T[other.m_capacity];
            for (size_t i = 0; i < other.m_size; ++i) {
                tmp[i] = other.m_data[i];
            }
            delete[] m_data;
            m_data = tmp;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
        }
        return *this;
    }

    ~Vector() {
        delete[] m_data;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > m_capacity) {
            T *new_data = new T[new_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
    }

    void assign(size_t count, const T &value) {
        clear();
        if (m_capacity < count) {
            reserve(count);
        }
        for (size_t i = 0; i < count; ++i) {
            push_back(value);
        }
    }

    T &at(size_t pos) {
        if (pos >= m_size) {
            throw std::out_of_range("Invalid index");
        }
        return m_data[pos];
    }

    const T &at(size_t pos) const {
        if (pos >= m_size) {
            throw std::out_of_range("Invalid index");
        }
        return m_data[pos];
    }

    void resize(size_t new_size, const T &value = T()) {
        if (new_size > m_size) {
            reserve(new_size);
            for (size_t i = m_size; i < new_size; ++i) {
                m_data[i] = value;
            }
        }
        m_size = new_size;
    }

    void push_back(const T &value) {
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : 2 * m_capacity);
        }
        m_data[m_size++] = value;
    }

    void pop_back() {
        if (m_size > 0) {
            --m_size;
        }
    }

    T &front() {
        return m_data[0];
    }

    const T &front() const {
        return m_data[0];
    }

    T &back() {
        return m_data[m_size - 1];
    }

    const T &back() const {
        return m_data[m_size - 1];
    }

    T *data() noexcept {
        return m_data;
    }

    const T *data() const noexcept {
        return m_data;
    }

    iterator begin() noexcept {
        return iterator(m_data);
    }

    iterator end() noexcept {
        return iterator(m_data + m_size);
    }

    const_iterator cbegin() const {
        return const_iterator(m_data);
    }

    const_iterator cend() const {
        return const_iterator(m_data + m_size);
    }

    iterator rbegin() {
        return iterator(m_data + m_size);
    }

    iterator rend() {
        return iterator(m_data);
    }

    void insert(iterator pos, const T& value) {
        difference_type index = pos - begin();
        if (m_size >= m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }

        for (int i = m_size; i > index; --i) {
            m_data[i] = std::move(m_data[i - 1]);
        }

        m_data[index] = value;
        ++m_size;
    }

    void erase(iterator position) {
        if (position == end()) {
            return end();
        }

        for (auto it = position; it != end() - 1; ++it) {
            *it = *(it + 1);
        }
        --m_size;
    }

    void erase(iterator first, iterator last) {

        auto rangeSize = last - first;
        auto tailSize = end() - last;

        for (auto it = first; it != end() - rangeSize; ++it) {
            *it = *(it + rangeSize);
        }

        m_size -= rangeSize;

        for (auto it = end() - rangeSize; it != end(); ++it) {
            *it = *(it + tailSize);
        }
    }

    size_t max_size() const {
        return std::numeric_limits<std::ptrdiff_t>::max() / sizeof(T);
    }

    T &operator[](size_t index) {
        return m_data[index];
    }

    const T &operator[](size_t index) const {
        return m_data[index];
    }

    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_capacity;
    }

    bool empty() const {
        return m_size == 0;
    }

    void clear() {
        m_size = 0;
    }

    template<typename... Args>
    T &emplace_back(Args &&... args) {
        if (m_size == m_capacity) {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        T &new_element = m_data[m_size++];
        new(&new_element) T(std::forward<Args>(args)...);
        return new_element;
    }

    void swap(Vector<T> &other) {
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_data, other.m_data);
    }

    friend void swap(Vector<T> &a, Vector<T> &b) {
        a.swap(b);
    }
};