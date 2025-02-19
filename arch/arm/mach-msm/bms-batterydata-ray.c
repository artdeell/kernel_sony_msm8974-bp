/* Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x = {-20, 0, 25, 40, 60},
	.y = {1343, 1353, 1408, 1345, 1342},
	.cols = 5
};

static struct single_row_lut fcc_sf = {
	.x = {0},
	.y = {100},
	.cols = 1
};

static struct sf_lut rbatt_sf = {
	.rows = 29,
	.cols = 5,
	.row_entries = {-20, 0, 25, 40, 60},
	.percent = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35,
		30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.sf = {
	       {604, 192, 100, 79, 71},
	       {605, 192, 100, 79, 71},
	       {641, 205, 103, 81, 72},
	       {641, 221, 108, 84, 75},
	       {622, 238, 115, 87, 77},
	       {612, 254, 123, 92, 79},
	       {605, 252, 137, 96, 83},
	       {607, 219, 154, 104, 87},
	       {613, 202, 135, 109, 89},
	       {626, 200, 106, 90, 77},
	       {656, 201, 101, 82, 75},
	       {684, 204, 100, 84, 77},
	       {710, 211, 100, 85, 79},
	       {747, 224, 106, 89, 82},
	       {806, 241, 116, 90, 80},
	       {905, 260, 119, 87, 77},
	       {1046, 291, 113, 87, 77},
	       {1309, 329, 116, 90, 79},
	       {1476, 300, 126, 97, 83},
	       {1598, 311, 127, 98, 84},
	       {1771, 323, 130, 99, 85},
	       {1984, 342, 136, 101, 86},
	       {2438, 368, 140, 101, 86},
	       {3381, 388, 137, 100, 84},
	       {4913, 414, 141, 99, 86},
	       {6979, 468, 155, 104, 90},
	       {9968, 565, 192, 113, 98},
	       {16163, 833, 350, 140, 120},
	       {36511, 6483, 4872, 472, 1095}
	       }
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows = 29,
	.cols = 5,
	.temp = {-20, 0, 25, 40, 60},
	.percent = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35,
		30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv = {
		{4177, 4174, 4199, 4167, 4162},
		{4107, 4112, 4141, 4109, 4106},
		{4058, 4064, 4091, 4061, 4059},
		{3996, 4015, 4044, 4017, 4015},
		{3947, 3975, 4001, 3978, 3976},
		{3909, 3939, 3962, 3943, 3940},
		{3874, 3901, 3926, 3911, 3907},
		{3845, 3858, 3892, 3882, 3878},
		{3821, 3826, 3851, 3849, 3846},
		{3801, 3804, 3815, 3810, 3808},
		{3788, 3789, 3793, 3789, 3787},
		{3778, 3780, 3778, 3776, 3773},
		{3769, 3776, 3770, 3767, 3764},
		{3757, 3772, 3766, 3762, 3757},
		{3740, 3765, 3762, 3754, 3744},
		{3714, 3747, 3750, 3739, 3724},
		{3668, 3706, 3717, 3710, 3697},
		{3602, 3644, 3662, 3662, 3654},
		{3533, 3571, 3601, 3607, 3605},
		{3518, 3557, 3583, 3592, 3590},
		{3500, 3543, 3565, 3576, 3574},
		{3478, 3528, 3546, 3559, 3557},
		{3451, 3506, 3521, 3538, 3534},
		{3417, 3473, 3481, 3505, 3496},
		{3377, 3423, 3424, 3454, 3444},
		{3327, 3361, 3351, 3391, 3380},
		{3261, 3279, 3258, 3310, 3297},
		{3165, 3165, 3138, 3198, 3182},
		{3000, 3000, 3000, 3000, 3000}
		}
};

struct bms_battery_data oem_batt_data = {
	.fcc = 1300,
	.fcc_temp_lut = &fcc_temp,
	.fcc_sf_lut = &fcc_sf,
	.pc_temp_ocv_lut = &pc_temp_ocv,
	.rbatt_sf_lut = &rbatt_sf,
	.default_rbatt_mohm = 172
};

struct bms_battery_data *bms_batt_data = &oem_batt_data;
int bms_batt_data_num = 1;
