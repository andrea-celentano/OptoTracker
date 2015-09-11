#ifndef TRECONDEFS
#define TRECONDEFS
enum fitObject_t{
    k_null=0,
	k_point,
	k_track
};

enum fitLikelihoodMode_t{
	k_onlyCharge,
	k_onlyTime,
	k_both	
};

enum fitParameters_t{
	k_x0=0,
	k_y0,
	k_z0,
	k_x1,
	k_y1,
	k_z1,
	k_beta,
	k_T0,
	k_N0,
	k_tau
};

#endif
