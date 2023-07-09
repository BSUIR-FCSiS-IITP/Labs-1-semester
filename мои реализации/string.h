#include <iostream>
#include <limits>
#include <cstring>


[[maybe_unused]] void* memcpy(void* s1, const void* s2, size_t n) {
    char* dest = static_cast<char*>(s1);
    const char* src = static_cast<const char*>(s2);
    while (n--) {
        *dest++ = *src++;
    }
    return s1;
}

void* memmove(void* s1, const void* s2, size_t n) {
    char* dest = static_cast<char*>(s1);
    const char* src = static_cast<const char*>(s2);
    if (dest <= src || dest >= src + n) {
        while (n--) {
            *dest++ = *src++;
        }
    } else {
        dest += n - 1;
        src += n - 1;
        while (n--) {
            *dest-- = *src--;
        }
    }
    return s1;
}

char* strcpy(char* s1, const char* s2) {
    char* dest = s1;
    while (*s2 != '\0') {
        *dest++ = *s2++;
    }
    *dest = '\0';
    return s1;
}

char* strncpy(char* s1, const char* s2, size_t n) {
    char* dest = s1;
    while (n-- && *s2 != '\0') {
        *dest++ = *s2++;
    }
    while (n-- > 0) {
        *dest++ = '\0';
    }
    return s1;
}

char* strcat(char* s1, const char* s2) {
    char* dest = s1 + strlen(s1);
    while (*s2 != '\0') {
        *dest++ = *s2++;
    }
    *dest = '\0';
    return s1;
}

char* strncat(char* s1, const char* s2, size_t n) {
    char* dest = s1 + strlen(s1);
    while (n-- && *s2 != '\0') {
        *dest++ = *s2++;
    }
    *dest = '\0';
    return s1;
}

int memcmp(const void* s1, const void* s2, size_t n) {
    const unsigned char* p1 = (const unsigned char*) s1;
    const unsigned char* p2 = (const unsigned char*) s2;
    for (size_t i = 0; i < n; ++i) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    return 0;
}

int strcmp(const char* s1, const char* s2) {
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
        ++i;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int strcoll(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

int strncmp(const char* s1, const char* s2, size_t n) {
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
        ++i;
    }
    if (i == n) {
        return 0;
    } else if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

size_t strxfrm(char* s1, const char* s2, size_t n) {
    size_t s2_len = strlen(s2);
    if (n > s2_len) {
        strcpy(s1, s2);
        return s2_len;
    } else {
        strncpy(s1, s2, n);
        return n;
    }
}

char* strtok(char* s1, const char* s2) {
    static char* last_str = nullptr;
    if (s1 != nullptr) {
        last_str = s1;
    } else if (last_str == nullptr) {
        return nullptr;
    }
    char* start = last_str;
    while (*start != '\0' && strchr(s2, *start) != nullptr) {
        ++start;
    }
    if (*start == '\0') {
        return nullptr;
    }
    char *end = start + 1;
    while (*end != '\0' && strchr(s2, *end) == nullptr) {
        ++end;
    }
    last_str = (*end == '\0') ? nullptr : end;
    *end = '\0';
    return start;
}

void* memset(void* s, int c, size_t n) {
    unsigned char* p = (unsigned char*) s;
    for (size_t i = 0; i < n; ++i) {
        p[i] = (unsigned char) c;
    }
    return s;
}

size_t strlen(const char* s)
{
    size_t len = 0;
    while (*s != '\0') {
        ++len;
        ++s;
    }
    return len;
}

char* strerror(int errnum) {
    static thread_local char buf[256];
    const char* msg = std::strerror(errnum);

    if (msg == nullptr) {
        std::snprintf(buf, sizeof(buf), "Unknown error (%d)", errnum);
    } else {
        std::strncpy(buf, msg, sizeof(buf));
        buf[sizeof(buf) - 1] = '\0';
    }

    return buf;
}


template<typename T>
class SmartPtr {
private:
    T* m_ptr;

public:
    explicit SmartPtr(T* ptr = nullptr) : m_ptr(ptr) {}

    ~SmartPtr() = default;

    SmartPtr(const SmartPtr& other) {
        m_ptr = new T(*other.m_ptr);
    }

    SmartPtr& operator=(SmartPtr<T> &other) {
        if (this != &other) {
            delete m_ptr;
            m_ptr = new T(*other->m_ptr);
        }
        return *this;
    }

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    explicit operator bool() const {
        return m_ptr != nullptr;
    }

    bool operator==(const SmartPtr& other) const {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const SmartPtr& other) const {
        return *this != other;
    }

    [[nodiscard]] T* get() const {
        return m_ptr;
    }
};


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

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}


class StringIterator {
public:

    StringIterator(){};
    StringIterator(char* ptr) : m_ptr(ptr) {}
    ~StringIterator(){}

    StringIterator& operator++() {
        ++m_ptr;
        return *this;
    }

    StringIterator operator++(int) {
        StringIterator tmp = *this;
        ++m_ptr;
        return tmp;
    }

    StringIterator& operator--() {
        --m_ptr;
        return *this;
    }


    StringIterator operator--(int) {
        StringIterator tmp = *this;
        --m_ptr;
        return tmp;
    }

    char& operator*() const {
        return *m_ptr;
    }

    char* operator->() const {
        return m_ptr;
    }

    bool operator==(const StringIterator& other) const {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const StringIterator& other) const {
        return m_ptr != other.m_ptr;
    }

    StringIterator& operator=(const StringIterator &tmp)
    {
        m_ptr=tmp.m_ptr;
    }

private:
    char* m_ptr;
};


class String : public StringIterator
{
private:
    unique_ptr<char> m_data;
    size_t m_size;
public:
    String(): m_size(0) {
        m_data = unique_ptr<char>(new char[1]);
        m_data.get()[0] = '\0';
    }

    String(const char* data, size_t size) : m_data(new char[size]), m_size(size) {
        std::memcpy(m_data.get(), data, size);
    }

    String(const char* str) : m_size(strlen(str)) {
        m_data = unique_ptr<char>(new char[m_size + 1]);
        strcpy(m_data.get(), str);
    }

    String(const String& other) : m_size(other.m_size) {
        m_data = unique_ptr<char>(new char[m_size + 1]);
        strcpy(m_data.get(), other.m_data.get());
    }

    String& operator=(const String& other) {
        if (this != &other) {
            m_size = other.m_size;
            m_data = unique_ptr<char>(new char[m_size + 1]);
            strcpy(m_data.get(), other.m_data.get());
        }
        return *this;
    }

    ~String() = default;

    char& operator[](int index) {
        return m_data.get()[index];
    }

    const char& operator[](int index) const {
        return m_data.get()[index];
    }

    [[nodiscard]] const char* c_str() const {
        return m_data.get();
    }

    [[maybe_unused]] int size() const {
        return m_size;
    }

    bool operator==(const String& other) const {
        return strcmp(m_data.get(), other.m_data.get()) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }
    bool operator<(const String& other) const {
        return strcmp(m_data.get(), other.m_data.get()) < 0;
    }

    bool operator>(const String& other) const {
        return strcmp(m_data.get(), other.m_data.get()) > 0;
    }

    void push_back(const char c) {
        unique_ptr<char> new_data(new char[m_size + 2]);
        strcpy(new_data.get(), m_data.get());
        new_data.get()[m_size] = c;
        new_data.get()[m_size + 1] = '\0';
        m_data = std::move(new_data);
        ++m_size;
    }

    typedef StringIterator Iterator;

    Iterator begin() {
        return {m_data.get()};
    }

    Iterator end() {
        return {m_data.get() + m_size};
    }


    char* data() {
        return m_data.get();
    }

    [[nodiscard]] const char* data() const {
        return m_data.get();
    }

    char& operator[](size_t index) {
        return m_data.get()[index];
    }

    const char& operator[](size_t index) const {
        return m_data.get()[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.m_data.get();
        return os;
    }
};




