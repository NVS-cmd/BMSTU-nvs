#pragma once

template<typename TFirst, typename TSecond>
class Pair {
public:
    TFirst  first;
    TSecond second;

    Pair() = default;

    Pair(const TFirst& f, const TSecond& s)
        : first(f), second(s) {}
};
