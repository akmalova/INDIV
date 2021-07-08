#ifndef TESTLIST_H
#define TESTLIST_H
#include <QObject>
#include "Header.h"

class TestList : public QObject
{
    Q_OBJECT
public:
    explicit TestList(QObject *parent = 0);

private slots:
    void inHead();
    void inTail();
    void delFirst();
    void delLast();
    void counter();
    void isEmpty();
    void insertelbefore();
    void insertelafter();
    void delel();
    void poiskel();
    void isEmptyiter();
};

#endif // TESTLIST_H
