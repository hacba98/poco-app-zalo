/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyList.h
 * Author: cpu10855
 *
 * Created on June 13, 2019, 3:11 PM
 */

#ifndef MYLIST_H
#define MYLIST_H

#include "Poco/Mutex.h"
#include "Poco/Exception.h"

#include "vector"

// data structure for each element in list
template <typename K, typename T>
class DoubleNode
{
public:
    // constructor
    //DoubleNode<K, T>(K key, T data) : _key(key), _data(data), _next(NULL), _prev(NULL){};
    DoubleNode<K, T>(){};
    ~DoubleNode<K, T>(){};

    // core
    DoubleNode<K, T> *set(const K key, const T data)
    {
        _key = key;
        _data = data;
        return this;
    }

    // utility
    inline K getKey(){return _key;}
    inline T getData(){return _data;}
    inline DoubleNode<K, T> * getNext() {return _next;}
    inline DoubleNode<K, T> * getPrev() {return _prev;}
    
    bool putNext(const DoubleNode<K, T> *next); // return false if next == null
    bool putPrev(const DoubleNode<K, T> *prev);
    

private:
    K _key;
    T _data;
    DoubleNode<K, T> *_prev;
    DoubleNode<K, T> *_next;
};

// wrapper data structure for whole elements
template <typename K, typename T>
class MyList
{
public:
    MyList<K, T>() : _size(1000), _head(NULL), _tail(NULL), _mutex()
    {
        initialize();
    };
    MyList<K, T>(std::int32_t size) : _size(size), _head(NULL), _tail(NULL), _mutex()
    {
        initialize();
    };
    
    ~MyList<K, T>(){
	    for (;_head != NULL;){
		    DoubleNode<K, T> *tmp = _head;
		    _head = _head->getNext();
		    delete tmp;
	    }
    }

    // core
    void initialize();
    //DoubleNode<K, T> *getAllocated(K key);
    // have to make sure element must be in the chain
    void reorder(DoubleNode<K, T> *ele);
    // called when add new element to storage
    DoubleNode<K, T> *add(K key, T data);
    // return list of candidate key for remove (items in the tail)
    std::vector<K> remove(std::uint32_t number);

    // utility
    inline DoubleNode<K, T> *getHead() { return _head; }
    inline DoubleNode<K, T> *getTail() { return _tail; }
    inline std::uint32_t getSize() { return _size; }

private:
    std::uint32_t _size;
    DoubleNode<K, T> *_head;
    DoubleNode<K, T> *_tail;
    Poco::Mutex _mutex;
};

#include "MyList.tcc"

#endif /* MYLIST_H */

