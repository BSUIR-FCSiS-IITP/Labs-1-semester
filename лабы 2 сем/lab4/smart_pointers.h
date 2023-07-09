#include <iostream>

template<typename T>
class shared_ptr {
public:
    shared_ptr() : m_ptr(nullptr), m_ref_count(nullptr) {}

    explicit shared_ptr(T* ptr) : m_ptr(ptr) {
        m_ref_count = new size_t(1);
    }

    shared_ptr(const shared_ptr<T>& other) {
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;
        if (m_ref_count) {
            ++(*m_ref_count);
        }
    }

    ~shared_ptr() {
        reset();
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other) {
        if (this != &other) {
            reset();
            m_ptr = other.m_ptr;
            m_ref_count = other.m_ref_count;
            if (m_ref_count) {
                ++(*m_ref_count);
            }
        }
        return *this;
    }

    T* get() const {
        return m_ptr;
    }

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    [[nodiscard]] size_t use_count() const {
        return m_ref_count ? *m_ref_count : 0;
    }

    void reset() {
        if (m_ref_count) {
            --(*m_ref_count);
            if (*m_ref_count == 0) {
                delete m_ref_count;
                delete m_ptr;
            }
            m_ref_count = nullptr;
            m_ptr = nullptr;
        }
    }

private:
    T* m_ptr;
    size_t* m_ref_count;
};



template<typename T>
class unique_ptr {
public:

    unique_ptr() noexcept : ptr(nullptr) {}
    explicit unique_ptr(T* p) noexcept : ptr(p) {}
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    ~unique_ptr() {
        reset();
    }

    T* get() const noexcept {
        return ptr;
    }

    T& operator*() const noexcept {
        return *ptr;
    }

    T* operator->() const noexcept {
        return ptr;
    }

    T* release() noexcept {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p = nullptr) noexcept {
        delete ptr;
        ptr = p;
    }

    void swap(unique_ptr& other) noexcept {
        T* tmp = ptr;
        ptr = other.m_ptr;
        other.m_ptr = tmp;
    }

private:
    T* ptr;
};