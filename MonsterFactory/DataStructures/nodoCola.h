#ifndef NODOCOLA_H
#define NODOCOLA_H


template <typename T>
class nodoCola {
public:
    T data;
    nodoCola* next;

    nodoCola(){
        data = 0;
        next = nullptr;
    }

    nodoCola(T _data){
        data = _data;
        next = nullptr;
    }
};

#endif // NODOCOLA_H
