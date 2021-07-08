#include <QtTest/QtTest>
#include "Header.h"
#include "testlist.h"

TestList::TestList(QObject *parent) : QObject(parent)
{
}

void TestList::inHead() {
    List list;
    list.inHead(1);
    QCOMPARE(list.getFirst(), 1);
    list.inHead(2);
    QCOMPARE(list.getFirst(), 2);
    list.inHead(3);
    QCOMPARE(list.getFirst(), 3);
}

void TestList::inTail() {
    List list;
    list.inTail(1);
    QCOMPARE(list.getLast(), 1);
    list.inTail(2);
    QCOMPARE(list.getLast(), 2);
    list.inTail(3);
    QCOMPARE(list.getLast(), 3);
}

void TestList::delFirst() {
    List list;
    list.inTail(1);
    list.inTail(2);
    list.inTail(3);
    list.delFirst();
    QCOMPARE(list.getFirst(), 2);
    list.delFirst();
    QCOMPARE(list.getFirst(), 3);
}

void TestList::delLast() {
    List list;
    list.inTail(1);
    list.inTail(2);
    list.inTail(3);
    list.delLast();
    QCOMPARE(list.getLast(), 2);
    list.delLast();
    QCOMPARE(list.getLast(), 1);
}

void TestList::counter() {
    List list1;
    for (int i = 0; i < 5; ++i)
        list1.inTail(i);
    QCOMPARE(list1.counter(), 5);

    List list2;
    list2.inTail(1);
    QCOMPARE(list2.counter(), 1);

    List list3;
    QCOMPARE(list3.counter(), 0);
}

void TestList::isEmpty()
{
    List list;
    QCOMPARE(list.isEmpty(), true);
    list.inHead(1);
    list.inHead(2);
    QCOMPARE(list.isEmpty(), false);
    list.delLast();
    list.delLast();
    QCOMPARE(list.isEmpty(), true);
}

void TestList::insertelbefore() {
    List list;
    for (int i = 0; i < 6; ++i)
        list.inTail(i+1);
    list.insertelbefore(list.begin(), 7);
    QCOMPARE(list.getFirst(), 7);

    listIterator iter = list.begin();
    while (*iter != 3)
        ++iter;
    list.insertelbefore(iter, 8);
    --iter;
    QCOMPARE(*iter, 8);

    while (*iter != 4)
        ++iter;
    list.insertelbefore(iter, 9);
    --iter;
    QCOMPARE(*iter, 9);
}

void TestList::insertelafter() {
    List list;
    for (int i = 0; i < 6; ++i)
        list.inTail(i+1);
    list.insertelafter(list.begin(), 7);
    listIterator iter = list.begin();
    ++iter;
    QCOMPARE(*iter, 7);

    while (*iter != 3)
        ++iter;
    list.insertelafter(iter, 8);
    ++iter;
    QCOMPARE(*iter, 8);

    while (*iter != 4)
        ++iter;
    list.insertelafter(iter, 9);
    ++iter;
    QCOMPARE(*iter, 9);
}

void TestList::poiskel() {
    List list;
    for (int i = 0; i < 6; ++i)
        list.inTail(i+1);
    listIterator iter = list.begin();
    QCOMPARE(list.poiskel(1), iter);
    ++iter;
    QCOMPARE(list.poiskel(2), iter);

}

void TestList::delel() {
    List list;
    for (int i = 0; i < 6; ++i)
        list.inTail(i+1);
    list.delel(list.begin());
    QCOMPARE(list.getFirst(), 2);

    listIterator iter = list.begin();
    ++iter;
    list.delel(iter);
    iter = list.begin();
    ++iter;
    QCOMPARE(*iter, 4);
}

void TestList::isEmptyiter() {
    List list;
    listIterator iter = list.begin();
    QCOMPARE(iter.isEmptyiter(), true);
    list.inHead(1);
    QCOMPARE(iter.isEmptyiter(), false);
}
