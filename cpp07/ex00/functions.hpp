#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T& a, T& b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(T& a, T& b) {
    return (a > b) ? a : b;
}

#endif 
