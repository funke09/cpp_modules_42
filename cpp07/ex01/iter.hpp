#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename Function>
void iter(T* array, int length, Function func) {
    for (int i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif 
