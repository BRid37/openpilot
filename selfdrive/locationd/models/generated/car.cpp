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
void err_fun(double *nom_x, double *delta_x, double *out_3155248762157281240) {
   out_3155248762157281240[0] = delta_x[0] + nom_x[0];
   out_3155248762157281240[1] = delta_x[1] + nom_x[1];
   out_3155248762157281240[2] = delta_x[2] + nom_x[2];
   out_3155248762157281240[3] = delta_x[3] + nom_x[3];
   out_3155248762157281240[4] = delta_x[4] + nom_x[4];
   out_3155248762157281240[5] = delta_x[5] + nom_x[5];
   out_3155248762157281240[6] = delta_x[6] + nom_x[6];
   out_3155248762157281240[7] = delta_x[7] + nom_x[7];
   out_3155248762157281240[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5194509576030625763) {
   out_5194509576030625763[0] = -nom_x[0] + true_x[0];
   out_5194509576030625763[1] = -nom_x[1] + true_x[1];
   out_5194509576030625763[2] = -nom_x[2] + true_x[2];
   out_5194509576030625763[3] = -nom_x[3] + true_x[3];
   out_5194509576030625763[4] = -nom_x[4] + true_x[4];
   out_5194509576030625763[5] = -nom_x[5] + true_x[5];
   out_5194509576030625763[6] = -nom_x[6] + true_x[6];
   out_5194509576030625763[7] = -nom_x[7] + true_x[7];
   out_5194509576030625763[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_999619185016042165) {
   out_999619185016042165[0] = 1.0;
   out_999619185016042165[1] = 0;
   out_999619185016042165[2] = 0;
   out_999619185016042165[3] = 0;
   out_999619185016042165[4] = 0;
   out_999619185016042165[5] = 0;
   out_999619185016042165[6] = 0;
   out_999619185016042165[7] = 0;
   out_999619185016042165[8] = 0;
   out_999619185016042165[9] = 0;
   out_999619185016042165[10] = 1.0;
   out_999619185016042165[11] = 0;
   out_999619185016042165[12] = 0;
   out_999619185016042165[13] = 0;
   out_999619185016042165[14] = 0;
   out_999619185016042165[15] = 0;
   out_999619185016042165[16] = 0;
   out_999619185016042165[17] = 0;
   out_999619185016042165[18] = 0;
   out_999619185016042165[19] = 0;
   out_999619185016042165[20] = 1.0;
   out_999619185016042165[21] = 0;
   out_999619185016042165[22] = 0;
   out_999619185016042165[23] = 0;
   out_999619185016042165[24] = 0;
   out_999619185016042165[25] = 0;
   out_999619185016042165[26] = 0;
   out_999619185016042165[27] = 0;
   out_999619185016042165[28] = 0;
   out_999619185016042165[29] = 0;
   out_999619185016042165[30] = 1.0;
   out_999619185016042165[31] = 0;
   out_999619185016042165[32] = 0;
   out_999619185016042165[33] = 0;
   out_999619185016042165[34] = 0;
   out_999619185016042165[35] = 0;
   out_999619185016042165[36] = 0;
   out_999619185016042165[37] = 0;
   out_999619185016042165[38] = 0;
   out_999619185016042165[39] = 0;
   out_999619185016042165[40] = 1.0;
   out_999619185016042165[41] = 0;
   out_999619185016042165[42] = 0;
   out_999619185016042165[43] = 0;
   out_999619185016042165[44] = 0;
   out_999619185016042165[45] = 0;
   out_999619185016042165[46] = 0;
   out_999619185016042165[47] = 0;
   out_999619185016042165[48] = 0;
   out_999619185016042165[49] = 0;
   out_999619185016042165[50] = 1.0;
   out_999619185016042165[51] = 0;
   out_999619185016042165[52] = 0;
   out_999619185016042165[53] = 0;
   out_999619185016042165[54] = 0;
   out_999619185016042165[55] = 0;
   out_999619185016042165[56] = 0;
   out_999619185016042165[57] = 0;
   out_999619185016042165[58] = 0;
   out_999619185016042165[59] = 0;
   out_999619185016042165[60] = 1.0;
   out_999619185016042165[61] = 0;
   out_999619185016042165[62] = 0;
   out_999619185016042165[63] = 0;
   out_999619185016042165[64] = 0;
   out_999619185016042165[65] = 0;
   out_999619185016042165[66] = 0;
   out_999619185016042165[67] = 0;
   out_999619185016042165[68] = 0;
   out_999619185016042165[69] = 0;
   out_999619185016042165[70] = 1.0;
   out_999619185016042165[71] = 0;
   out_999619185016042165[72] = 0;
   out_999619185016042165[73] = 0;
   out_999619185016042165[74] = 0;
   out_999619185016042165[75] = 0;
   out_999619185016042165[76] = 0;
   out_999619185016042165[77] = 0;
   out_999619185016042165[78] = 0;
   out_999619185016042165[79] = 0;
   out_999619185016042165[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8264863719993736290) {
   out_8264863719993736290[0] = state[0];
   out_8264863719993736290[1] = state[1];
   out_8264863719993736290[2] = state[2];
   out_8264863719993736290[3] = state[3];
   out_8264863719993736290[4] = state[4];
   out_8264863719993736290[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8264863719993736290[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8264863719993736290[7] = state[7];
   out_8264863719993736290[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5156811274296861720) {
   out_5156811274296861720[0] = 1;
   out_5156811274296861720[1] = 0;
   out_5156811274296861720[2] = 0;
   out_5156811274296861720[3] = 0;
   out_5156811274296861720[4] = 0;
   out_5156811274296861720[5] = 0;
   out_5156811274296861720[6] = 0;
   out_5156811274296861720[7] = 0;
   out_5156811274296861720[8] = 0;
   out_5156811274296861720[9] = 0;
   out_5156811274296861720[10] = 1;
   out_5156811274296861720[11] = 0;
   out_5156811274296861720[12] = 0;
   out_5156811274296861720[13] = 0;
   out_5156811274296861720[14] = 0;
   out_5156811274296861720[15] = 0;
   out_5156811274296861720[16] = 0;
   out_5156811274296861720[17] = 0;
   out_5156811274296861720[18] = 0;
   out_5156811274296861720[19] = 0;
   out_5156811274296861720[20] = 1;
   out_5156811274296861720[21] = 0;
   out_5156811274296861720[22] = 0;
   out_5156811274296861720[23] = 0;
   out_5156811274296861720[24] = 0;
   out_5156811274296861720[25] = 0;
   out_5156811274296861720[26] = 0;
   out_5156811274296861720[27] = 0;
   out_5156811274296861720[28] = 0;
   out_5156811274296861720[29] = 0;
   out_5156811274296861720[30] = 1;
   out_5156811274296861720[31] = 0;
   out_5156811274296861720[32] = 0;
   out_5156811274296861720[33] = 0;
   out_5156811274296861720[34] = 0;
   out_5156811274296861720[35] = 0;
   out_5156811274296861720[36] = 0;
   out_5156811274296861720[37] = 0;
   out_5156811274296861720[38] = 0;
   out_5156811274296861720[39] = 0;
   out_5156811274296861720[40] = 1;
   out_5156811274296861720[41] = 0;
   out_5156811274296861720[42] = 0;
   out_5156811274296861720[43] = 0;
   out_5156811274296861720[44] = 0;
   out_5156811274296861720[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5156811274296861720[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5156811274296861720[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5156811274296861720[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5156811274296861720[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5156811274296861720[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5156811274296861720[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5156811274296861720[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5156811274296861720[53] = -9.8000000000000007*dt;
   out_5156811274296861720[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5156811274296861720[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5156811274296861720[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5156811274296861720[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5156811274296861720[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5156811274296861720[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5156811274296861720[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5156811274296861720[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5156811274296861720[62] = 0;
   out_5156811274296861720[63] = 0;
   out_5156811274296861720[64] = 0;
   out_5156811274296861720[65] = 0;
   out_5156811274296861720[66] = 0;
   out_5156811274296861720[67] = 0;
   out_5156811274296861720[68] = 0;
   out_5156811274296861720[69] = 0;
   out_5156811274296861720[70] = 1;
   out_5156811274296861720[71] = 0;
   out_5156811274296861720[72] = 0;
   out_5156811274296861720[73] = 0;
   out_5156811274296861720[74] = 0;
   out_5156811274296861720[75] = 0;
   out_5156811274296861720[76] = 0;
   out_5156811274296861720[77] = 0;
   out_5156811274296861720[78] = 0;
   out_5156811274296861720[79] = 0;
   out_5156811274296861720[80] = 1;
}
void h_25(double *state, double *unused, double *out_6835227641933438914) {
   out_6835227641933438914[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1586290556835207070) {
   out_1586290556835207070[0] = 0;
   out_1586290556835207070[1] = 0;
   out_1586290556835207070[2] = 0;
   out_1586290556835207070[3] = 0;
   out_1586290556835207070[4] = 0;
   out_1586290556835207070[5] = 0;
   out_1586290556835207070[6] = 1;
   out_1586290556835207070[7] = 0;
   out_1586290556835207070[8] = 0;
}
void h_24(double *state, double *unused, double *out_1847020538430055198) {
   out_1847020538430055198[0] = state[4];
   out_1847020538430055198[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4606324807527765835) {
   out_4606324807527765835[0] = 0;
   out_4606324807527765835[1] = 0;
   out_4606324807527765835[2] = 0;
   out_4606324807527765835[3] = 0;
   out_4606324807527765835[4] = 1;
   out_4606324807527765835[5] = 0;
   out_4606324807527765835[6] = 0;
   out_4606324807527765835[7] = 0;
   out_4606324807527765835[8] = 0;
   out_4606324807527765835[9] = 0;
   out_4606324807527765835[10] = 0;
   out_4606324807527765835[11] = 0;
   out_4606324807527765835[12] = 0;
   out_4606324807527765835[13] = 0;
   out_4606324807527765835[14] = 1;
   out_4606324807527765835[15] = 0;
   out_4606324807527765835[16] = 0;
   out_4606324807527765835[17] = 0;
}
void h_30(double *state, double *unused, double *out_8092074297455467096) {
   out_8092074297455467096[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2941405773292401128) {
   out_2941405773292401128[0] = 0;
   out_2941405773292401128[1] = 0;
   out_2941405773292401128[2] = 0;
   out_2941405773292401128[3] = 0;
   out_2941405773292401128[4] = 1;
   out_2941405773292401128[5] = 0;
   out_2941405773292401128[6] = 0;
   out_2941405773292401128[7] = 0;
   out_2941405773292401128[8] = 0;
}
void h_26(double *state, double *unused, double *out_1989554861722272706) {
   out_1989554861722272706[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2155212762038849154) {
   out_2155212762038849154[0] = 0;
   out_2155212762038849154[1] = 0;
   out_2155212762038849154[2] = 0;
   out_2155212762038849154[3] = 0;
   out_2155212762038849154[4] = 0;
   out_2155212762038849154[5] = 0;
   out_2155212762038849154[6] = 0;
   out_2155212762038849154[7] = 1;
   out_2155212762038849154[8] = 0;
}
void h_27(double *state, double *unused, double *out_814117531377895428) {
   out_814117531377895428[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5116169085092826039) {
   out_5116169085092826039[0] = 0;
   out_5116169085092826039[1] = 0;
   out_5116169085092826039[2] = 0;
   out_5116169085092826039[3] = 1;
   out_5116169085092826039[4] = 0;
   out_5116169085092826039[5] = 0;
   out_5116169085092826039[6] = 0;
   out_5116169085092826039[7] = 0;
   out_5116169085092826039[8] = 0;
}
void h_29(double *state, double *unused, double *out_4451567059631917778) {
   out_4451567059631917778[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2431174428978008944) {
   out_2431174428978008944[0] = 0;
   out_2431174428978008944[1] = 1;
   out_2431174428978008944[2] = 0;
   out_2431174428978008944[3] = 0;
   out_2431174428978008944[4] = 0;
   out_2431174428978008944[5] = 0;
   out_2431174428978008944[6] = 0;
   out_2431174428978008944[7] = 0;
   out_2431174428978008944[8] = 0;
}
void h_28(double *state, double *unused, double *out_5815790799038741073) {
   out_5815790799038741073[0] = state[0];
}
void H_28(double *state, double *unused, double *out_467544157412682693) {
   out_467544157412682693[0] = 1;
   out_467544157412682693[1] = 0;
   out_467544157412682693[2] = 0;
   out_467544157412682693[3] = 0;
   out_467544157412682693[4] = 0;
   out_467544157412682693[5] = 0;
   out_467544157412682693[6] = 0;
   out_467544157412682693[7] = 0;
   out_467544157412682693[8] = 0;
}
void h_31(double *state, double *unused, double *out_7974066903522090352) {
   out_7974066903522090352[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2781420864272200630) {
   out_2781420864272200630[0] = 0;
   out_2781420864272200630[1] = 0;
   out_2781420864272200630[2] = 0;
   out_2781420864272200630[3] = 0;
   out_2781420864272200630[4] = 0;
   out_2781420864272200630[5] = 0;
   out_2781420864272200630[6] = 0;
   out_2781420864272200630[7] = 0;
   out_2781420864272200630[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3155248762157281240) {
  err_fun(nom_x, delta_x, out_3155248762157281240);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5194509576030625763) {
  inv_err_fun(nom_x, true_x, out_5194509576030625763);
}
void car_H_mod_fun(double *state, double *out_999619185016042165) {
  H_mod_fun(state, out_999619185016042165);
}
void car_f_fun(double *state, double dt, double *out_8264863719993736290) {
  f_fun(state,  dt, out_8264863719993736290);
}
void car_F_fun(double *state, double dt, double *out_5156811274296861720) {
  F_fun(state,  dt, out_5156811274296861720);
}
void car_h_25(double *state, double *unused, double *out_6835227641933438914) {
  h_25(state, unused, out_6835227641933438914);
}
void car_H_25(double *state, double *unused, double *out_1586290556835207070) {
  H_25(state, unused, out_1586290556835207070);
}
void car_h_24(double *state, double *unused, double *out_1847020538430055198) {
  h_24(state, unused, out_1847020538430055198);
}
void car_H_24(double *state, double *unused, double *out_4606324807527765835) {
  H_24(state, unused, out_4606324807527765835);
}
void car_h_30(double *state, double *unused, double *out_8092074297455467096) {
  h_30(state, unused, out_8092074297455467096);
}
void car_H_30(double *state, double *unused, double *out_2941405773292401128) {
  H_30(state, unused, out_2941405773292401128);
}
void car_h_26(double *state, double *unused, double *out_1989554861722272706) {
  h_26(state, unused, out_1989554861722272706);
}
void car_H_26(double *state, double *unused, double *out_2155212762038849154) {
  H_26(state, unused, out_2155212762038849154);
}
void car_h_27(double *state, double *unused, double *out_814117531377895428) {
  h_27(state, unused, out_814117531377895428);
}
void car_H_27(double *state, double *unused, double *out_5116169085092826039) {
  H_27(state, unused, out_5116169085092826039);
}
void car_h_29(double *state, double *unused, double *out_4451567059631917778) {
  h_29(state, unused, out_4451567059631917778);
}
void car_H_29(double *state, double *unused, double *out_2431174428978008944) {
  H_29(state, unused, out_2431174428978008944);
}
void car_h_28(double *state, double *unused, double *out_5815790799038741073) {
  h_28(state, unused, out_5815790799038741073);
}
void car_H_28(double *state, double *unused, double *out_467544157412682693) {
  H_28(state, unused, out_467544157412682693);
}
void car_h_31(double *state, double *unused, double *out_7974066903522090352) {
  h_31(state, unused, out_7974066903522090352);
}
void car_H_31(double *state, double *unused, double *out_2781420864272200630) {
  H_31(state, unused, out_2781420864272200630);
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
