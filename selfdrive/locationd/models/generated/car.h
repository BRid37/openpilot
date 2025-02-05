#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3155248762157281240);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5194509576030625763);
void car_H_mod_fun(double *state, double *out_999619185016042165);
void car_f_fun(double *state, double dt, double *out_8264863719993736290);
void car_F_fun(double *state, double dt, double *out_5156811274296861720);
void car_h_25(double *state, double *unused, double *out_6835227641933438914);
void car_H_25(double *state, double *unused, double *out_1586290556835207070);
void car_h_24(double *state, double *unused, double *out_1847020538430055198);
void car_H_24(double *state, double *unused, double *out_4606324807527765835);
void car_h_30(double *state, double *unused, double *out_8092074297455467096);
void car_H_30(double *state, double *unused, double *out_2941405773292401128);
void car_h_26(double *state, double *unused, double *out_1989554861722272706);
void car_H_26(double *state, double *unused, double *out_2155212762038849154);
void car_h_27(double *state, double *unused, double *out_814117531377895428);
void car_H_27(double *state, double *unused, double *out_5116169085092826039);
void car_h_29(double *state, double *unused, double *out_4451567059631917778);
void car_H_29(double *state, double *unused, double *out_2431174428978008944);
void car_h_28(double *state, double *unused, double *out_5815790799038741073);
void car_H_28(double *state, double *unused, double *out_467544157412682693);
void car_h_31(double *state, double *unused, double *out_7974066903522090352);
void car_H_31(double *state, double *unused, double *out_2781420864272200630);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}