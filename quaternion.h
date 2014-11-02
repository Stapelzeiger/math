#ifndef QUATERNION_H
#define QUATERNION_H

typedef struct {
    float q[4]; // q[0] + q[1]*i + q[2]*j + q[3]*k
} quaternion_t;

// initializer: usage: quaternion_t q = Quaternion(1,2,3,4);
#define Quaternion(a, b, c, d) {.q = {a, b, c, d}}

#ifdef __cplusplus
extern "C" {
#endif

// copy a quaternion
void qcopy(quaternion_t *dest, const quaternion_t *src);
// multiplication by scalar: res = q * a, res pointer can be the same as q
void qmult_scalar(const quaternion_t *q, float a, quaternion_t *res);
// multiplication: res = q1 * q2, res pointer can be the same as q1 or q2
void qmult(const quaternion_t *q1, const quaternion_t *q2, quaternion_t *res);
// addition: res = q1 + q2, res pointer can be the same as q1 or q2
void qadd(const quaternion_t *q1, const quaternion_t *q2, quaternion_t *res);
// conjugate: conj = q*, conj pointer can be the same as q
void qconj(const quaternion_t *q, quaternion_t *conj);
// norm: |q|
float qnorm(const quaternion_t *q);
// square of the norm: |q|^2
float qnorm_sq(const quaternion_t *q);
// normalize: q/|q|
void qnormalize(quaternion_t *q);

#ifdef __cplusplus
}
#endif

#endif // QUATERNION_H
