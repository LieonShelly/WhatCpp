//
//  LinkedList.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/4.
//  Copyright © 2021 lieon. All rights reserved.
//
/**
 # 线性表 是具有 n 个相同类型元素 的有限 序列 （ n ≥ 0 ）
 - 常见的线性表有
 - 数组
 - 链表
 - 栈
 - 队列
 - 哈希表（散列）
 ## 动态数组的缺点
 - 可能会造成大量的内存浪费
 ## 链表
 - 链表 是一种 链式存储 的线性表，所有元素的内存地址不一定是连续的
 */
#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "List.hpp"
#include "AbstractList.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

template<typename Element>
class Node {
public:
    Element element;
    Node<Element> *next { nullptr };
    
    Node(const Element &element, Node<Element> * const next) {
        this->element = element;
        this->next = next;
    }
    
    ~Node() {
    }
};

template<typename E>
class LinkedList: public AbstractList<E> {
 
    
private:
    Node<E> *first { nullptr };
    
    // 获取index位置对应的节点对象
    Node<E> & nodeAt(int index) {
        this->rangeCheck(index);
        Node<E> *node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return *node;
    }
public:
    LinkedList() {
        this->m_size = 0;
    }
    
    ~LinkedList() {
        clear();
    }
    
    void clear() override {
        this->m_size = 0;
        if (first != nullptr) {
            Node<E> *node = first->next;
            while (node != nullptr) {
                node = node->next;
                delete node->next;
            }
            delete first;
            first = nullptr;
        }
    }
    
    bool contains(const E &element) override {
        return false;
    }
    
    E& set(int index, const E &element) override {
        Node<E> &node = nodeAt(index);
        E& old = node.element;
        node.element = element;
        return old;
    }
    
    void insert(int index, const E &element) override {
        this->rangeCheckForAdd(index);
        if (index == 0) {
            first = new Node<E>(element, first);
        } else {
            Node<E> &prev = nodeAt(index - 1);
            Node<E> *node = new Node<E>(element, prev.next);
            prev.next = node;
        }
        this->m_size++;
    }
    
    E& get(int index) override {
        return nodeAt(index).element;
    }
    
    int indexOf(const E &element) override {
        Node<E> * node = first;
        for (int i = 0; i < this->m_size; i++) {
            if (element == node->element) {
                return i;
            }
            node = node->next;
        }
        return -1;
    }
    
    E& removeAt(int index) override {
        this->rangeCheck(index);
        Node<E> *node = first;
        if (index == 0) {
            first = first->next;
        } else {
            Node<E> &prev = this->nodeAt(index - 1);
            node = prev.next;
            prev.next = node->next;
        }
        this->m_size--;
        return node->element;
    }
    
    bool isEmpty() override {
        return this->m_size > 0;
    }
    
    Node<E>* reverseList() {
        Node<E> * cur = nullptr;
        Node<E> *pre = first;
        while (pre != nullptr) {
            Node<E> *temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
    
    bool hasCycle() {
        if (first == nullptr || first->next == nullptr) {
            return false;
        }
        Node<E> *slow = first;
        Node<E> *fast = first->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (fast == slow) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

#endif /* LinkedList_hpp */
