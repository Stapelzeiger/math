#include <math.h>
#include "quaternion.h"

void qcopy(quaternion_t *dest, const quaternion_t *src)
{
    int i;
    for (i = 0; i < 4; i++) {
        dest->q[i] = src->q[i];
    }
}

void qmult_scalar(const quaternion_t *q, float a, quaternion_t *res)
{
    quaternion_t qa = Quaternion(a, 0, 0, 0);
    qmult(q, &qa, res);
}

void qmult(const quaternion_t *q1, const quaternion_t *q2, quaternion_t *res)
{
    quaternion_t buf;
    buf.q[0] = q1->q[0]*q2->q[0] - q1->q[1]*q2->q[1] - q1->q[2]*q2->q[2] - q1->q[3]*q2->q[3];
    buf.q[1] = q1->q[0]*q2->q[1] + q1->q[1]*q2->q[0] + q1->q[2]*q2->q[3] - q1->q[3]*q2->q[2];
    buf.q[2] = q1->q[0]*q2->q[2] - q1->q[1]*q2->q[3] + q1->q[2]*q2->q[0] + q1->q[3]*q2->q[1];
    buf.q[3] = q1->q[0]*q2->q[3] + q1->q[1]*q2->q[2] - q1->q[2]*q2->q[1] + q1->q[3]*q2->q[0];
    qcopy(res, &buf);
}

void qadd(const quaternion_t *q1, const quaternion_t *q2, quaternion_t *res)
{
    int i;
    for (i = 0; i < 4; i++) {
        res->q[i] = q1->q[i] + q2->q[i];
    }
}

void qconj(const quaternion_t *q, quaternion_t *conj)
{
    conj->q[0] = q->q[0];
    int i;
    for (i = 1; i < 4; i++) {
        conj->q[i] = - q->q[i];
    }
}

float qnorm(const quaternion_t *q)
{
    return sqrtf(qnorm_sq(q));
}

float qnorm_sq(const quaternion_t *q)
{
    return q->q[0]*q->q[0] + q->q[1]*q->q[1] + q->q[2]*q->q[2] + q->q[3]*q->q[3];
}

void qnormalize(quaternion_t *q)
{
    qmult_scalar(q, 1/qnorm(q), q);
}
