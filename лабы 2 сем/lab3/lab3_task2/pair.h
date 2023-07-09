template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair() = default;
    Pair(T1 first, T2 second): first(first), second(second) {}
    static Pair<T1, T2> make_pair(T1 first, T2 second)
    {
        return Pair<T1, T2>(first, second);
    }
};
