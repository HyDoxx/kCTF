//
// Created by kinolu on 25-4-2.
//
#include <cinttypes>

#ifndef KUTILS_H
#define KUTILS_H

template<typename _Ty, int N>
struct windowView {
    using type = _Ty**;
    _Ty *view[N] = {};

    _Ty operator[](int i){
        return *(view[i]);
    }

    type getVerticalWindow(_Ty *arr, size_t width, size_t height, bool isVerticalArr, int n)  {
        if (isVerticalArr) {
            for(int i = 0; i < N; i++) {
                view[i] = arr + n * width + i;
            }
        }
        else {
            for(int i = 0; i < N; i++) {
                view[i] = arr + height * i + n;
            }
        }
        return view;
    }

    type getHorizontalWindow(_Ty *arr, size_t width, size_t height, bool isHorizontalArr, int n)  {
        if (isHorizontalArr) {
            for(int i = 0; i < N; i++) {
                view[i] = arr + i * width + n;
            }
        }
        else {
            for(int i = 0; i < N; i++) {
                view[i] = arr + n * height + i;
            }
        }
        return view;
    }

    void operator >> (int count){
        _Ty oldArr[N];
        for(int i = 0; i < N; ++i){
            oldArr[i] = *(view[i]);
        }
        for(int i = 0; i < N; ++i){
            if(i + count > N - 1){
                *(view[i + count - N]) = oldArr[i];
            }
            else{
                *(view[i + count]) = oldArr[i];
            }
        }
    }

    void operator << (int count){
        operator >>(N - count);
    }
};


template<typename _Ty, int N>
void shift(_Ty *arr, bool isLeft, size_t count){
    _Ty oldArr[N];
    if(isLeft){
        count = N - count;
    }
    for(int i = 0; i < N; ++i){
        oldArr[i] = arr[i];
    }
    for(int i = 0; i < N; ++i){
        if(i + count > N - 1){
            arr[i + count - N] = oldArr[i];
        }
        else{
            arr[i + count] = oldArr[i];
        }
    }
}



#endif //KUTILS_H
