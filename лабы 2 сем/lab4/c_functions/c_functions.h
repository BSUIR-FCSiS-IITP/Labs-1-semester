void* memcpy(void* s1, const void* s2, size_t n) {
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
        // non-overlapping buffers, copy from left to right
        while (n--) {
            *dest++ = *src++;
        }
    } else {
        // overlapping buffers, copy from right to left
        dest += n - 1;
        src += n - 1;
        while (n--) {
            *dest-- = *src--;
        }
    }
    return s1;
}

// Copies the string pointed to by s2 (including the null character) into the array pointed to by s1.
char* strcpy(char* s1, const char* s2) {
    char* dest = s1;
    while (*s2 != '\0') {
        *dest++ = *s2++;
    }
    *dest = '\0';
    return s1;
}

// Copies not more than n characters from the string pointed to by s2 (including the null character)
// into the array pointed to by s1.
// If the string pointed to by s2 is shorter than n characters, null characters are appended to the destination array
// until a total of n characters have been written.
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

// Appends a copy of the null-terminated byte string pointed to by s2 to the end of the null-terminated byte string pointed to by s1.
char* strcat(char* s1, const char* s2) {
    char* dest = s1 + strlen(s1);
    while (*s2 != '\0') {
        *dest++ = *s2++;
    }
    *dest = '\0';
    return s1;
}

// Appends not more than n characters from the null-terminated byte string pointed to by s2 to the end of the
// null-terminated byte string pointed to by s1.
// The resulting byte string is null-terminated.
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


// Returns the length of the string s, excluding the terminating null byte
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
