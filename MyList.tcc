/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyList.cpp
 * Author: cpu10855
 * 
 * Created on June 13, 2019, 3:11 PM
 */

#include "MyList.h"

using namespace std;

// element class
template <typename K, typename T>
bool DoubleNode<K, T>::putNext(DoubleNode<K, T> *next)
{
	bool ret = true;
	if (next == NULL)
	    ret = false;
	_next = next;
	return ret;
}

template <typename K, typename T>
bool DoubleNode<K, T>::putPrev(DoubleNode<K, T> *prev)
{
	bool ret = true;
	if (prev == NULL)
	    ret = false;
	_prev = prev;
	return ret;
}

// list class
template <typename TKEY, typename TDATA>
void MyList<TKEY, TDATA>::initialize()
{
    DoubleNode<TKEY, TDATA> *head = new DoubleNode<TKEY, TDATA>();
    DoubleNode<TKEY, TDATA> *tail = new DoubleNode<TKEY, TDATA>();

    if (!tail->putPrev(head) || !head->putNext(tail))
        throw Poco::Exception("Cannot initialize cache. Error at allocated step 1.");

    for (int i = 0; i < _size; i++)
    {
        DoubleNode<TKEY, TDATA> *tmp = new DoubleNode<TKEY, TDATA>();
        if (!tail->putNext(tmp) || !tmp->putPrev(tail))
            throw Poco::Exception("Cannot initialize cache. Error at allocated step 2.");
        tail = tmp;
    }

    _head = head;
    _tail = tail;
    return;
}

// function call when element be accessed -> put it into the front
// have to make sure element is in the chain
// pointer should coming from mapping
template <typename TKEY, typename TDATA>
void MyList<TKEY, TDATA>::reorder(DoubleNode<TKEY, TDATA> *ele)
{
	// get it out of chain -> connect prev and next node
	if (ele == _head)
		return;
	ele->getPrev()->putNext(ele->getNext());
	if (_tail == ele)
	    _tail = ele->getPrev();
	else
	    ele->getNext()->putPrev(ele->getPrev());

	// put to front -> next is current head & prev is null
	bool ok_ = ele->putNext(_head);
	ok_ = ele->putPrev(NULL) && ok_;
	ok_ = _head->putPrev(ele) && ok_;

	// update new head
	_head = ele;
}

template <typename TKEY, typename TDATA>
DoubleNode<TKEY, TDATA> *MyList<TKEY, TDATA>::add(TKEY key, TDATA data)
{
	// set data to last node
	DoubleNode<TKEY, TDATA> *ret = _tail;
	ret->set(key, data);
	// put that node to front
	reorder(ret);
	// return address of that node
	return ret;
}

template <typename TKEY, typename TDATA>
std::vector<TKEY> MyList<TKEY, TDATA>::remove(std::uint32_t number){
	std::vector<TKEY> ret;
	// loop and gather last elements in the queue
	for(int i=0; i < number; i++){
		DoubleNode<TKEY, TDATA> *tmp = _tail;
		ret.push_back(tmp->getKey());
		tmp = tmp->getPrev();
	}
	return ret;
}