//
// Created by kinolu on 25-4-2.
//
#include <cinttypes>

#ifndef KUTILS_H
#define KUTILS_H

template<typename _Ty, int N>
_Ty **getVerticalWindow(_Ty *arr, size_t width, size_t height, bool isVerticalArr, int n, _Ty *buff[N])  {
    if (isVerticalArr) {
        for(int i = 0; i < N; i++) {
            buff[i] = arr + n * width + i;
        }
    }
    else {
        for(int i = 0; i < N; i++) {
            buff[i] = arr + height * i + n;
        }
    }
    return buff;
}

template<typename _Ty, int N>
_Ty **getHorizontalWindow(_Ty *arr, size_t width, size_t height, bool isVerticalArr, int n, _Ty *buff[N]) {
    if (isVerticalArr) {
        for(int i = 0; i < N; i++) {
            buff[i] = arr + i * width + n;
        }
    }
    else {
        for(int i = 0; i < N; i++) {
            buff[i] = arr + n * height + i;
        }
    }
    return buff;
}


#endif //KUTILS_H
