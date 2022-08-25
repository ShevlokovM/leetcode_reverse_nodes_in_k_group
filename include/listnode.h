//
// Created by 111 on 23.08.2022.
//

#ifndef LETCODE_REVERSE_NODES_IN_K_GROUP_LISTNODE_H
#define LETCODE_REVERSE_NODES_IN_K_GROUP_LISTNODE_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <tuple>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    /**
     * деструктор удаляет весь связанный список,
     * нужно только запустить деструктор для первого элемента
     */
    ~ListNode()
    {
        if(next)
        {
            delete next;
        }
    }
};


/**
 * @brief checkInput - проверяет корректность ввода
 * @param input - строка, которую ввел пользователь
 * @return true - если ввод корректен
 */
bool checkInput(std::string & input);


/**
 * @brief createList - создает связанный список ListNode
 * @return указатель на первый элемент списка и размер списка
 */
std::tuple<ListNode*, int> createList();


/**
 * @brief reverse - инвертирует отрезки связанного списка. размер инвертируемых отрезков необходимо ввести
 * @param listNode указатель на первый элемент связанного списка
 * @param count размер списка
 * @return инвертированный лист
 */
std::shared_ptr<ListNode> reverse(ListNode * listNode, int count);


/**
 * @brief showList - выводит val нодов связанного списка в консоль
 * @param listNode указатель на первый элемент связанного списка
 */
void showList(ListNode * listNode);


#endif //LETCODE_REVERSE_NODES_IN_K_GROUP_LISTNODE_H
