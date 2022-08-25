//
// Created by 111 on 23.08.2022.
//

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include "../include/listnode.h"

/**
 * @brief checkInput - проверяет корректность ввода
 * @param input - строка, которую ввел пользователь
 * @return true - если ввод корректен
 */
bool checkInput(std::string & input)
{
    // проверка каждого символа в строке
    for(auto ch : input)
    {
        // если в строке есть не цифры, то ввод неверный
        if( !(std::isdigit(ch) ) ) return false;
    }
    return true;
}

/**
 * @brief createList - создает связанный список ListNode
 * @return указатель на первый элемент списка и размер списка
 */
std::tuple<ListNode*, int> createList()
{
    std::string input;

    std::cout << "Input size of list: \n";
    std::getline(std::cin, input);

    // пока ввод неверный, будет выводиться сообщение об ошибке, и предложение ввести заново
    while(!checkInput(input) )
    {
        std::cout << "Wrong input, try again: \n";
        std::cin.sync();
        std::getline(std::cin, input);
    }

    // если ввод верный, строку ввода преобразуем в целое число
    int listSize = std::stoi(input);

    if(listSize > 0)
    {
        // @return указатель на первый элемент списка
        ListNode * lNode = new ListNode(1);
        ListNode * ln = lNode;

        // непосредственно создание списка
        for (int i = 1; i < listSize; i++)
        {
            ln->next = new ListNode(i + 1);
            ln = ln->next;
        }

        // возвращаемое значение, указатель на первый элемент + размер списка
        std::tuple<ListNode*, int> tp(lNode, listSize);
        return tp;
    }
    else
    {
        std::tuple<ListNode*, int> tp(nullptr, listSize);
        return tp;
    }
}

/**
 * @brief reverse - инвертирует отрезки связанного списка. размер инвертируемых отрезков необходимо ввести
 * @param listNode указатель на первый элемент связанного списка
 * @param count размер списка
 * @return инвертированный лист
 */
std::shared_ptr<ListNode> reverse(ListNode * listNode, int count)
{
    std::string input;

    // ввод размера инвертируемой области
    std::cout << "Input size of revers area: \n";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, input);

    int revers_area_size;

    // проверка корректности ввода
    while(true)
    {
        // проверка коректности введенных символов
        while (!checkInput(input))
        {
            std::cout << "Wrong input, try again: \n";
            std::cin.ignore();
            std::getline(std::cin, input);
        }

        revers_area_size = std::stoi(input);

        // если все символы корректны, надо проверить корректность введенного числа
        // оно не может быть больше размера инвертируемого связанного списка
        if(revers_area_size > count)
        {
            std::cout << "Wrong input, try again: \n";
            std::cin.ignore();
            std::getline(std::cin, input);
        }
        else break;
    }

    // умный указатель для первого нода листа. Нужен чтобы запустить
    // удаление првого нода листа, по завершении работы программы.
    // Остальные ноды будут удалены рекурсивно через деструктор.
    std::shared_ptr<ListNode> ptrListNode = std::make_shared<ListNode>();

    // временный вектор для указателей на ноды листа. Размер равен размеру инвертируемой области.
    std::vector<ListNode *> pointers_to_node;

    // временные указатели для инверитрования листа
    ListNode * prev = nullptr;
    ListNode * move = listNode;

    // инвертирующий цикл
    for (int i = 0; i <= ( (count/revers_area_size) * revers_area_size) - 1; i += revers_area_size)
    {
        // заполнение временного вектора указателями на ноды
        for(int j = 0; j < revers_area_size; j++)
        {
            pointers_to_node.push_back(move);
            move = move->next;
        }

        // инвертирование отрезка
        for(int j = 0; j < revers_area_size; j++)
        {
            // замена next первого нода отрезка на next последнего
            if (j == 0)
            {
                pointers_to_node[0]->next = pointers_to_node[revers_area_size - 1]->next;
            }
            // остальные ноды указывают "назад", вместо "вперед"
            else
            {
                pointers_to_node[j]->next = pointers_to_node[j - 1];

                // если последний нод в отрезке
                if (j == revers_area_size - 1)
                {
                    // и при этом был предыдущий отрезок
                    if (prev)
                    {
                        // нужно next последнего нода предыдущего отрезка направить на нод,
                        // который стал первым в текущем отрезке
                        prev->next = pointers_to_node[revers_area_size - 1];
                    }
                    // нужно сохранить указатель на последний нод в текущем отрезке
                    prev = pointers_to_node[0];
                }
            }
        }
        if (i == 0)
        {
            // умный указатель должен указывать на первый нод реверсированного списка
            ptrListNode.reset(pointers_to_node[revers_area_size - 1]);
        }
        pointers_to_node.clear();
    }

    return ptrListNode;
}

/**
 * @brief showList - выводит val нодов связанного списка в консоль
 * @param listNode указатель на первый элемент связанного списка
 */
void showList(ListNode * listNode)
{
    if(listNode)
    {
        std::cout << "\n";
        while (true)
        {
            std::cout << listNode->val << "\t";

            // переход на следующий нод списка, если он есть
            if(listNode->next)
            {
                listNode = listNode->next;
            }
            else break;
        }
        std::cout << "\n" << "\n";
    }
}