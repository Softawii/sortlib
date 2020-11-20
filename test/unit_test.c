#include <stdbool.h>

#include "unit_test.h"


UnitTest createUnitTest(void *vector, int n, int size, Comparator comparator, Evaluator evaluator) {
    UnitTest ut;
    ut.vector = vector; ut.n = n; ut.size = size; ut.result = -1;
    ut.comparator = comparator; ut.evaluator = evaluator;
    
    return ut;
}


void evaluateUnitTest(UnitTest * unitTest, long double time) {
    unitTest->result = unitTest->evaluator( unitTest->vector, 
                                            unitTest->n, 
                                            unitTest->size, 
                                            unitTest->comparator);
    unitTest->time = time;
}

