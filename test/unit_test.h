#ifndef _UNIT_TEST_H_
#define _UNIT_TEST_H_

typedef int (*Comparator)(void*,  void*);
typedef int (*Evaluator)(void *vector, int n, int size, Comparator comparator);

struct _UnitTest{
    void *vector;
    int n;
    int size;
    Comparator comparator;
    Evaluator evaluator;
    int result;
};

typedef struct _UnitTest UnitTest;

void evaluateUnitTest(UnitTest * unitTest);
UnitTest createUnitTest(void *vector, int n, int size, Comparator comparator, Evaluator evaluator);

#endif