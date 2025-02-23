#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3945128746363994716) {
   out_3945128746363994716[0] = delta_x[0] + nom_x[0];
   out_3945128746363994716[1] = delta_x[1] + nom_x[1];
   out_3945128746363994716[2] = delta_x[2] + nom_x[2];
   out_3945128746363994716[3] = delta_x[3] + nom_x[3];
   out_3945128746363994716[4] = delta_x[4] + nom_x[4];
   out_3945128746363994716[5] = delta_x[5] + nom_x[5];
   out_3945128746363994716[6] = delta_x[6] + nom_x[6];
   out_3945128746363994716[7] = delta_x[7] + nom_x[7];
   out_3945128746363994716[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_716587360181185079) {
   out_716587360181185079[0] = -nom_x[0] + true_x[0];
   out_716587360181185079[1] = -nom_x[1] + true_x[1];
   out_716587360181185079[2] = -nom_x[2] + true_x[2];
   out_716587360181185079[3] = -nom_x[3] + true_x[3];
   out_716587360181185079[4] = -nom_x[4] + true_x[4];
   out_716587360181185079[5] = -nom_x[5] + true_x[5];
   out_716587360181185079[6] = -nom_x[6] + true_x[6];
   out_716587360181185079[7] = -nom_x[7] + true_x[7];
   out_716587360181185079[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3114700198542551124) {
   out_3114700198542551124[0] = 1.0;
   out_3114700198542551124[1] = 0;
   out_3114700198542551124[2] = 0;
   out_3114700198542551124[3] = 0;
   out_3114700198542551124[4] = 0;
   out_3114700198542551124[5] = 0;
   out_3114700198542551124[6] = 0;
   out_3114700198542551124[7] = 0;
   out_3114700198542551124[8] = 0;
   out_3114700198542551124[9] = 0;
   out_3114700198542551124[10] = 1.0;
   out_3114700198542551124[11] = 0;
   out_3114700198542551124[12] = 0;
   out_3114700198542551124[13] = 0;
   out_3114700198542551124[14] = 0;
   out_3114700198542551124[15] = 0;
   out_3114700198542551124[16] = 0;
   out_3114700198542551124[17] = 0;
   out_3114700198542551124[18] = 0;
   out_3114700198542551124[19] = 0;
   out_3114700198542551124[20] = 1.0;
   out_3114700198542551124[21] = 0;
   out_3114700198542551124[22] = 0;
   out_3114700198542551124[23] = 0;
   out_3114700198542551124[24] = 0;
   out_3114700198542551124[25] = 0;
   out_3114700198542551124[26] = 0;
   out_3114700198542551124[27] = 0;
   out_3114700198542551124[28] = 0;
   out_3114700198542551124[29] = 0;
   out_3114700198542551124[30] = 1.0;
   out_3114700198542551124[31] = 0;
   out_3114700198542551124[32] = 0;
   out_3114700198542551124[33] = 0;
   out_3114700198542551124[34] = 0;
   out_3114700198542551124[35] = 0;
   out_3114700198542551124[36] = 0;
   out_3114700198542551124[37] = 0;
   out_3114700198542551124[38] = 0;
   out_3114700198542551124[39] = 0;
   out_3114700198542551124[40] = 1.0;
   out_3114700198542551124[41] = 0;
   out_3114700198542551124[42] = 0;
   out_3114700198542551124[43] = 0;
   out_3114700198542551124[44] = 0;
   out_3114700198542551124[45] = 0;
   out_3114700198542551124[46] = 0;
   out_3114700198542551124[47] = 0;
   out_3114700198542551124[48] = 0;
   out_3114700198542551124[49] = 0;
   out_3114700198542551124[50] = 1.0;
   out_3114700198542551124[51] = 0;
   out_3114700198542551124[52] = 0;
   out_3114700198542551124[53] = 0;
   out_3114700198542551124[54] = 0;
   out_3114700198542551124[55] = 0;
   out_3114700198542551124[56] = 0;
   out_3114700198542551124[57] = 0;
   out_3114700198542551124[58] = 0;
   out_3114700198542551124[59] = 0;
   out_3114700198542551124[60] = 1.0;
   out_3114700198542551124[61] = 0;
   out_3114700198542551124[62] = 0;
   out_3114700198542551124[63] = 0;
   out_3114700198542551124[64] = 0;
   out_3114700198542551124[65] = 0;
   out_3114700198542551124[66] = 0;
   out_3114700198542551124[67] = 0;
   out_3114700198542551124[68] = 0;
   out_3114700198542551124[69] = 0;
   out_3114700198542551124[70] = 1.0;
   out_3114700198542551124[71] = 0;
   out_3114700198542551124[72] = 0;
   out_3114700198542551124[73] = 0;
   out_3114700198542551124[74] = 0;
   out_3114700198542551124[75] = 0;
   out_3114700198542551124[76] = 0;
   out_3114700198542551124[77] = 0;
   out_3114700198542551124[78] = 0;
   out_3114700198542551124[79] = 0;
   out_3114700198542551124[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_919830539308120838) {
   out_919830539308120838[0] = state[0];
   out_919830539308120838[1] = state[1];
   out_919830539308120838[2] = state[2];
   out_919830539308120838[3] = state[3];
   out_919830539308120838[4] = state[4];
   out_919830539308120838[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_919830539308120838[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_919830539308120838[7] = state[7];
   out_919830539308120838[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8061374538994660092) {
   out_8061374538994660092[0] = 1;
   out_8061374538994660092[1] = 0;
   out_8061374538994660092[2] = 0;
   out_8061374538994660092[3] = 0;
   out_8061374538994660092[4] = 0;
   out_8061374538994660092[5] = 0;
   out_8061374538994660092[6] = 0;
   out_8061374538994660092[7] = 0;
   out_8061374538994660092[8] = 0;
   out_8061374538994660092[9] = 0;
   out_8061374538994660092[10] = 1;
   out_8061374538994660092[11] = 0;
   out_8061374538994660092[12] = 0;
   out_8061374538994660092[13] = 0;
   out_8061374538994660092[14] = 0;
   out_8061374538994660092[15] = 0;
   out_8061374538994660092[16] = 0;
   out_8061374538994660092[17] = 0;
   out_8061374538994660092[18] = 0;
   out_8061374538994660092[19] = 0;
   out_8061374538994660092[20] = 1;
   out_8061374538994660092[21] = 0;
   out_8061374538994660092[22] = 0;
   out_8061374538994660092[23] = 0;
   out_8061374538994660092[24] = 0;
   out_8061374538994660092[25] = 0;
   out_8061374538994660092[26] = 0;
   out_8061374538994660092[27] = 0;
   out_8061374538994660092[28] = 0;
   out_8061374538994660092[29] = 0;
   out_8061374538994660092[30] = 1;
   out_8061374538994660092[31] = 0;
   out_8061374538994660092[32] = 0;
   out_8061374538994660092[33] = 0;
   out_8061374538994660092[34] = 0;
   out_8061374538994660092[35] = 0;
   out_8061374538994660092[36] = 0;
   out_8061374538994660092[37] = 0;
   out_8061374538994660092[38] = 0;
   out_8061374538994660092[39] = 0;
   out_8061374538994660092[40] = 1;
   out_8061374538994660092[41] = 0;
   out_8061374538994660092[42] = 0;
   out_8061374538994660092[43] = 0;
   out_8061374538994660092[44] = 0;
   out_8061374538994660092[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8061374538994660092[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8061374538994660092[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8061374538994660092[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8061374538994660092[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8061374538994660092[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8061374538994660092[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8061374538994660092[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8061374538994660092[53] = -9.8000000000000007*dt;
   out_8061374538994660092[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8061374538994660092[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8061374538994660092[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8061374538994660092[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8061374538994660092[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8061374538994660092[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8061374538994660092[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8061374538994660092[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8061374538994660092[62] = 0;
   out_8061374538994660092[63] = 0;
   out_8061374538994660092[64] = 0;
   out_8061374538994660092[65] = 0;
   out_8061374538994660092[66] = 0;
   out_8061374538994660092[67] = 0;
   out_8061374538994660092[68] = 0;
   out_8061374538994660092[69] = 0;
   out_8061374538994660092[70] = 1;
   out_8061374538994660092[71] = 0;
   out_8061374538994660092[72] = 0;
   out_8061374538994660092[73] = 0;
   out_8061374538994660092[74] = 0;
   out_8061374538994660092[75] = 0;
   out_8061374538994660092[76] = 0;
   out_8061374538994660092[77] = 0;
   out_8061374538994660092[78] = 0;
   out_8061374538994660092[79] = 0;
   out_8061374538994660092[80] = 1;
}
void h_25(double *state, double *unused, double *out_5888062735106196579) {
   out_5888062735106196579[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3753622120726827903) {
   out_3753622120726827903[0] = 0;
   out_3753622120726827903[1] = 0;
   out_3753622120726827903[2] = 0;
   out_3753622120726827903[3] = 0;
   out_3753622120726827903[4] = 0;
   out_3753622120726827903[5] = 0;
   out_3753622120726827903[6] = 1;
   out_3753622120726827903[7] = 0;
   out_3753622120726827903[8] = 0;
}
void h_24(double *state, double *unused, double *out_1077211176371475216) {
   out_1077211176371475216[0] = state[4];
   out_1077211176371475216[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8492089273131562287) {
   out_8492089273131562287[0] = 0;
   out_8492089273131562287[1] = 0;
   out_8492089273131562287[2] = 0;
   out_8492089273131562287[3] = 0;
   out_8492089273131562287[4] = 1;
   out_8492089273131562287[5] = 0;
   out_8492089273131562287[6] = 0;
   out_8492089273131562287[7] = 0;
   out_8492089273131562287[8] = 0;
   out_8492089273131562287[9] = 0;
   out_8492089273131562287[10] = 0;
   out_8492089273131562287[11] = 0;
   out_8492089273131562287[12] = 0;
   out_8492089273131562287[13] = 0;
   out_8492089273131562287[14] = 1;
   out_8492089273131562287[15] = 0;
   out_8492089273131562287[16] = 0;
   out_8492089273131562287[17] = 0;
}
void h_30(double *state, double *unused, double *out_1572496029142691746) {
   out_1572496029142691746[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3882961067870067973) {
   out_3882961067870067973[0] = 0;
   out_3882961067870067973[1] = 0;
   out_3882961067870067973[2] = 0;
   out_3882961067870067973[3] = 0;
   out_3882961067870067973[4] = 1;
   out_3882961067870067973[5] = 0;
   out_3882961067870067973[6] = 0;
   out_3882961067870067973[7] = 0;
   out_3882961067870067973[8] = 0;
}
void h_26(double *state, double *unused, double *out_4826545488271157400) {
   out_4826545488271157400[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7495125439600884127) {
   out_7495125439600884127[0] = 0;
   out_7495125439600884127[1] = 0;
   out_7495125439600884127[2] = 0;
   out_7495125439600884127[3] = 0;
   out_7495125439600884127[4] = 0;
   out_7495125439600884127[5] = 0;
   out_7495125439600884127[6] = 0;
   out_7495125439600884127[7] = 1;
   out_7495125439600884127[8] = 0;
}
void h_27(double *state, double *unused, double *out_4944552882204534144) {
   out_4944552882204534144[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6057724379670492884) {
   out_6057724379670492884[0] = 0;
   out_6057724379670492884[1] = 0;
   out_6057724379670492884[2] = 0;
   out_6057724379670492884[3] = 1;
   out_6057724379670492884[4] = 0;
   out_6057724379670492884[5] = 0;
   out_6057724379670492884[6] = 0;
   out_6057724379670492884[7] = 0;
   out_6057724379670492884[8] = 0;
}
void h_29(double *state, double *unused, double *out_7145340890726000580) {
   out_7145340890726000580[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3372729723555675789) {
   out_3372729723555675789[0] = 0;
   out_3372729723555675789[1] = 1;
   out_3372729723555675789[2] = 0;
   out_3372729723555675789[3] = 0;
   out_3372729723555675789[4] = 0;
   out_3372729723555675789[5] = 0;
   out_3372729723555675789[6] = 0;
   out_3372729723555675789[7] = 0;
   out_3372729723555675789[8] = 0;
}
void h_28(double *state, double *unused, double *out_2340147561395836493) {
   out_2340147561395836493[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5593257950099977125) {
   out_5593257950099977125[0] = 1;
   out_5593257950099977125[1] = 0;
   out_5593257950099977125[2] = 0;
   out_5593257950099977125[3] = 0;
   out_5593257950099977125[4] = 0;
   out_5593257950099977125[5] = 0;
   out_5593257950099977125[6] = 0;
   out_5593257950099977125[7] = 0;
   out_5593257950099977125[8] = 0;
}
void h_31(double *state, double *unused, double *out_6045249403457325724) {
   out_6045249403457325724[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3722976158849867475) {
   out_3722976158849867475[0] = 0;
   out_3722976158849867475[1] = 0;
   out_3722976158849867475[2] = 0;
   out_3722976158849867475[3] = 0;
   out_3722976158849867475[4] = 0;
   out_3722976158849867475[5] = 0;
   out_3722976158849867475[6] = 0;
   out_3722976158849867475[7] = 0;
   out_3722976158849867475[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_3945128746363994716) {
  err_fun(nom_x, delta_x, out_3945128746363994716);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_716587360181185079) {
  inv_err_fun(nom_x, true_x, out_716587360181185079);
}
void car_H_mod_fun(double *state, double *out_3114700198542551124) {
  H_mod_fun(state, out_3114700198542551124);
}
void car_f_fun(double *state, double dt, double *out_919830539308120838) {
  f_fun(state,  dt, out_919830539308120838);
}
void car_F_fun(double *state, double dt, double *out_8061374538994660092) {
  F_fun(state,  dt, out_8061374538994660092);
}
void car_h_25(double *state, double *unused, double *out_5888062735106196579) {
  h_25(state, unused, out_5888062735106196579);
}
void car_H_25(double *state, double *unused, double *out_3753622120726827903) {
  H_25(state, unused, out_3753622120726827903);
}
void car_h_24(double *state, double *unused, double *out_1077211176371475216) {
  h_24(state, unused, out_1077211176371475216);
}
void car_H_24(double *state, double *unused, double *out_8492089273131562287) {
  H_24(state, unused, out_8492089273131562287);
}
void car_h_30(double *state, double *unused, double *out_1572496029142691746) {
  h_30(state, unused, out_1572496029142691746);
}
void car_H_30(double *state, double *unused, double *out_3882961067870067973) {
  H_30(state, unused, out_3882961067870067973);
}
void car_h_26(double *state, double *unused, double *out_4826545488271157400) {
  h_26(state, unused, out_4826545488271157400);
}
void car_H_26(double *state, double *unused, double *out_7495125439600884127) {
  H_26(state, unused, out_7495125439600884127);
}
void car_h_27(double *state, double *unused, double *out_4944552882204534144) {
  h_27(state, unused, out_4944552882204534144);
}
void car_H_27(double *state, double *unused, double *out_6057724379670492884) {
  H_27(state, unused, out_6057724379670492884);
}
void car_h_29(double *state, double *unused, double *out_7145340890726000580) {
  h_29(state, unused, out_7145340890726000580);
}
void car_H_29(double *state, double *unused, double *out_3372729723555675789) {
  H_29(state, unused, out_3372729723555675789);
}
void car_h_28(double *state, double *unused, double *out_2340147561395836493) {
  h_28(state, unused, out_2340147561395836493);
}
void car_H_28(double *state, double *unused, double *out_5593257950099977125) {
  H_28(state, unused, out_5593257950099977125);
}
void car_h_31(double *state, double *unused, double *out_6045249403457325724) {
  h_31(state, unused, out_6045249403457325724);
}
void car_H_31(double *state, double *unused, double *out_3722976158849867475) {
  H_31(state, unused, out_3722976158849867475);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
