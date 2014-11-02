#include "CppUTest/TestHarness.h"
#include <float.h>
#include <math.h>
#include "../quaternion.h"

TEST_GROUP(Quaternion)
{

};

TEST(Quaternion, Copy)
{
    quaternion_t q = Quaternion(1, 2, 3, 4);
    quaternion_t copy = Quaternion(0, 0, 0, 0);
    qcopy(&copy, &q);
    CHECK_EQUAL(1, copy.q[0]);
    CHECK_EQUAL(2, copy.q[1]);
    CHECK_EQUAL(3, copy.q[2]);
    CHECK_EQUAL(4, copy.q[3]);
}

TEST(Quaternion, MultScalar)
{
    quaternion_t q = Quaternion(1, 2, 3, 4);
    qmult_scalar(&q, 2, &q);
    DOUBLES_EQUAL(1*2, q.q[0], FLT_EPSILON);
    DOUBLES_EQUAL(2*2, q.q[1], FLT_EPSILON);
    DOUBLES_EQUAL(3*2, q.q[2], FLT_EPSILON);
    DOUBLES_EQUAL(4*2, q.q[3], FLT_EPSILON);
}

TEST(Quaternion, Mult)
{
    // (1+2i+3j+4k)*(2.1+4.5i+3.2j+1.3k) = -21.7-0.2 i+24.9 j+2.6 k
    quaternion_t q1 = Quaternion(1, 2, 3, 4);
    quaternion_t q2 = Quaternion(2.1, 4.5, 3.2, 1.3);
    qmult(&q1, &q2, &q1);
    DOUBLES_EQUAL(-21.7, q1.q[0], FLT_EPSILON*8);
    DOUBLES_EQUAL(-0.2, q1.q[1], FLT_EPSILON*8);
    DOUBLES_EQUAL(24.9, q1.q[2], FLT_EPSILON*8);
    DOUBLES_EQUAL(2.6, q1.q[3], FLT_EPSILON*8);
}

TEST(Quaternion, Add)
{
    quaternion_t q1 = Quaternion(1, 2, 3, 4);
    quaternion_t q2 = Quaternion(10, 20, 30, 40);
    qadd(&q1, &q2, &q1);
    DOUBLES_EQUAL(11, q1.q[0], FLT_EPSILON*8);
    DOUBLES_EQUAL(22, q1.q[1], FLT_EPSILON*8);
    DOUBLES_EQUAL(33, q1.q[2], FLT_EPSILON*8);
    DOUBLES_EQUAL(44, q1.q[3], FLT_EPSILON*8);
}

TEST(Quaternion, Conj)
{
    quaternion_t q = Quaternion(1, 2, 3, 4);
    quaternion_t qc = Quaternion(0, 0, 0, 0);
    qconj(&q, &qc);
    DOUBLES_EQUAL(1, qc.q[0], FLT_EPSILON*8);
    DOUBLES_EQUAL(-2, qc.q[1], FLT_EPSILON*8);
    DOUBLES_EQUAL(-3, qc.q[2], FLT_EPSILON*8);
    DOUBLES_EQUAL(-4, qc.q[3], FLT_EPSILON*8);
}

TEST(Quaternion, Norm)
{
    quaternion_t q = Quaternion(1, 2, 3, 4);
    DOUBLES_EQUAL(sqrt(30), qnorm(&q), FLT_EPSILON*8)
}

TEST(Quaternion, NormSq)
{
    quaternion_t q = Quaternion(1, 2, 3, 4);
    DOUBLES_EQUAL(30, qnorm_sq(&q), FLT_EPSILON*8)
}

TEST(Quaternion, Normalize)
{
    quaternion_t q = Quaternion(1, 2, 3, 4);
    qnormalize(&q);
    DOUBLES_EQUAL(1/sqrt(30), q.q[0], FLT_EPSILON*8);
    DOUBLES_EQUAL(2/sqrt(30), q.q[1], FLT_EPSILON*8);
    DOUBLES_EQUAL(3/sqrt(30), q.q[2], FLT_EPSILON*8);
    DOUBLES_EQUAL(4/sqrt(30), q.q[3], FLT_EPSILON*8);
}
