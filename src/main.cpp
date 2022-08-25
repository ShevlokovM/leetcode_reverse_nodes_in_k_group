/*
    Given the head of a linked list, reverse the nodes of the list k at a time,
    and return the modified list. k is a positive integer and is less than or
    equal to the length of the linked list. If the number of nodes is not a
    multiple of k then left-out nodes, in the end, should remain as it is.
    You may not alter the values in the list's nodes, only nodes themselves
    may be changed.
*/

#include "../include/listnode.h"

int main()
{
    // создание связанного списка
    std::tuple<ListNode*, int> listNodeData = createList();

    // вывод связанного списка в консоль
    showList(std::get<0>(listNodeData));

    // инвертирование частей связанного списка
    std::shared_ptr<ListNode> ptrListNode = reverse(std::get<0>(listNodeData), std::get<1>(listNodeData));

    // вывод инвертированного связанного списка в консоль
    showList(ptrListNode.get());

    return 0;
}
