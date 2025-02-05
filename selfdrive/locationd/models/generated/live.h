#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_1965639361288013725);
void live_err_fun(double *nom_x, double *delta_x, double *out_5199172378396509024);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2952380910721125403);
void live_H_mod_fun(double *state, double *out_5096821251984911957);
void live_f_fun(double *state, double dt, double *out_3537200419085443625);
void live_F_fun(double *state, double dt, double *out_4868595806798075065);
void live_h_4(double *state, double *unused, double *out_7570804151136260595);
void live_H_4(double *state, double *unused, double *out_2382807001725344315);
void live_h_9(double *state, double *unused, double *out_3545536123264320855);
void live_H_9(double *state, double *unused, double *out_8776718136719759831);
void live_h_10(double *state, double *unused, double *out_8220659860749883277);
void live_H_10(double *state, double *unused, double *out_8907832640427688895);
void live_h_12(double *state, double *unused, double *out_3198950031623364815);
void live_H_12(double *state, double *unused, double *out_3998451375317388681);
void live_h_35(double *state, double *unused, double *out_7612977089408799391);
void live_H_35(double *state, double *unused, double *out_5651245725976743100);
void live_h_32(double *state, double *unused, double *out_445124408325912041);
void live_H_32(double *state, double *unused, double *out_2294955996994783757);
void live_h_13(double *state, double *unused, double *out_2321214207381065649);
void live_H_13(double *state, double *unused, double *out_3609520538520451582);
void live_h_14(double *state, double *unused, double *out_3545536123264320855);
void live_H_14(double *state, double *unused, double *out_8776718136719759831);
void live_h_33(double *state, double *unused, double *out_8305058630017610017);
void live_H_33(double *state, double *unused, double *out_2500688721337885496);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}