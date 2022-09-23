/*
 * Interface/Wrapper for C functions generated by CasADi
 *
 * CasADi generated the following four files:
 * - auto_casadi_cost.c
 * - auto_casadi_grad.c
 * - auto_casadi_mapping_f1.c
 * - auto_casadi_mapping_f2.c
 * - auto_preconditioning_functions.c
 *
 * This file is autogenerated by Optimization Engine
 * See http://doc.optimization-engine.xyz
 *
 *
 * Metadata:
 * + Optimizer
 *   + name: {{ meta.optimizer_name }}
 *   + version: {{ meta.version }}
 *   + licence: {{ meta.licence }}
 * + Problem
 *   + vars: {{ problem.dim_decision_variables() }}
 *   + parameters: {{ problem.dim_parameters() }}
 *   + n1: {{ problem.dim_constraints_aug_lagrangian() }}
 *   + n2: {{ problem.dim_constraints_penalty() }}
 *
 */
#include <stdlib.h>

/*
 * This is to be used ONLY for DEBUG purposes
 * Compile with -DTEST_INTERFACE
 */
#ifdef TEST_INTERFACE
#include <stdio.h>
#endif

#include "casadi_memory.h"

/* Number of input variables */
#define NU_{{ meta.optimizer_name | upper}} {{ problem.dim_decision_variables() }}

/* Number of static parameters */
#define NP_{{ meta.optimizer_name | upper}} {{ problem.dim_parameters() }}

/* Dimension of F1 (number of ALM constraints) */
#define N1_{{ meta.optimizer_name | upper}} {{ problem.dim_constraints_aug_lagrangian() }}

/* Dimension of F2 (number of PM constraints) */
#define N2_{{ meta.optimizer_name | upper}} {{ problem.dim_constraints_penalty() }}

/* Dimension of xi = (c, y) */
#define NXI_{{ meta.optimizer_name | upper}} {% if problem.dim_constraints_aug_lagrangian() + problem.dim_constraints_penalty() > 0 %}{{ 1 + problem.dim_constraints_aug_lagrangian() }}{% else %}0{% endif %}

/* Preconditioning Flag */
{% if solver_config.preconditioning %}#define PRECONDITIONING_{{ meta.optimizer_name | upper}}{% endif %}


#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif


/* ------EXTERNAL FUNCTIONS (DEFINED IN C FILES)-------------------------------- */

/*
 * CasADi interface for the cost function
 */
extern int {{meta.cost_function_name or 'phi'}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

/*
 * CasADi interface for the gradient of the cost
 */
extern int {{meta.grad_function_name  or 'grad_phi'}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

/*
 * CasADi interface for the gradient of mapping F1
 */
extern int {{meta.alm_mapping_f1_function_name}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

/*
 * CasADi interface for the gradient of mapping F2
 */
extern int {{meta.constraint_penalty_function_name}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

//#ifdef PRECONDITIONING_{{ meta.optimizer_name | upper}}
/*
 * CasADi interface for cost function preconditioning
 */
extern int {{meta.w_cost_function_name}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

/*
 * CasADi interface for f1 constraints preconditioning
 */
extern int {{meta.w_f1_function_name}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

/*
 * CasADi interface for f2 constraints preconditioning
 */
extern int {{meta.w_f2_function_name}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);

/*
 * CasADi interface for initial penalty
 */
extern int {{meta.initial_penalty_function_name}}(
    const casadi_real** arg,
    casadi_real** res,
    casadi_int* iw,
    casadi_real* w,
    void* mem);


/* ------WORKSPACES------------------------------------------------------------- */

/*
 * Integer workspaces
 */
#if COST_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_cost[COST_SZ_IW_{{ meta.optimizer_name | upper}}];  /* cost (int )  */
#else
static casadi_int *allocated_i_workspace_cost = NULL;
#endif

#if GRAD_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_grad[GRAD_SZ_IW_{{ meta.optimizer_name | upper}}];  /* grad (int )  */
#else
static casadi_int *allocated_i_workspace_grad = NULL;
#endif

#if F1_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_f1[F1_SZ_IW_{{ meta.optimizer_name | upper}}];      /* f1 (int )    */
#else
static casadi_int *allocated_i_workspace_f1 = NULL;
#endif

#if F2_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_f2[F2_SZ_IW_{{ meta.optimizer_name | upper}}];      /* f2 (int )    */
#else
static casadi_int *allocated_i_workspace_f2 = NULL;
#endif

#if W_COST_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_w_cost[W_COST_SZ_IW_{{ meta.optimizer_name | upper}}];      /* w_cost (int )    */
#else
static casadi_int *allocated_i_workspace_w_cost = NULL;
#endif

#if W1_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_w1[W1_SZ_IW_{{ meta.optimizer_name | upper}}];      /* w1 (int )    */
#else
static casadi_int *allocated_i_workspace_w1 = NULL;
#endif

#if W2_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_w2[W2_SZ_IW_{{ meta.optimizer_name | upper}}];      /* w2 (int )    */
#else
static casadi_int *allocated_i_workspace_w2 = NULL;
#endif

#if INIT_PENALTY_SZ_IW_{{ meta.optimizer_name | upper}} > 0
static casadi_int allocated_i_workspace_init_penalty[INIT_PENALTY_SZ_IW_{{ meta.optimizer_name | upper}}];      /* init_penalty (int )    */
#else
static casadi_int *allocated_i_workspace_init_penalty = NULL;
#endif


/*
 * Real workspaces
 */
#if COST_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_cost[COST_SZ_W_{{ meta.optimizer_name | upper}}];  /* cost (real)  */
#else
static casadi_real *allocated_r_workspace_cost = NULL;
#endif


#if GRAD_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_grad[GRAD_SZ_W_{{ meta.optimizer_name | upper}}];  /* grad (real ) */
#else
static casadi_real *allocated_r_workspace_grad = NULL;
#endif

#if F1_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_f1[F1_SZ_W_{{ meta.optimizer_name | upper}}];      /* f1 (real )   */
#else
static casadi_real *allocated_r_workspace_f1 = NULL;
#endif

#if F2_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_f2[F2_SZ_W_{{ meta.optimizer_name | upper}}];      /* f2 (real )   */
#else
static casadi_real *allocated_r_workspace_f2 = NULL;
#endif

#if W_COST_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_w_cost[W_COST_SZ_W_{{ meta.optimizer_name | upper}}];      /* w_cost (real )   */
#else
static casadi_real *allocated_r_workspace_w_cost = NULL;
#endif

#if W1_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_w1[W1_SZ_W_{{ meta.optimizer_name | upper}}];      /* w1 (real )   */
#else
static casadi_real *allocated_r_workspace_w1 = NULL;
#endif

#if W2_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_w2[W2_SZ_W_{{ meta.optimizer_name | upper}}];      /* w2 (real )   */
#else
static casadi_real *allocated_r_workspace_w2 = NULL;
#endif

#if INIT_PENALTY_SZ_W_{{ meta.optimizer_name | upper}} > 0
static casadi_real allocated_r_workspace_init_penalty[INIT_PENALTY_SZ_W_{{ meta.optimizer_name | upper}}];      /* init_penalty (real )   */
#else
static casadi_real *allocated_r_workspace_init_penalty = NULL;
#endif

/*
 * Result workspaces
 */
#if COST_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_cost[COST_SZ_RES_{{ meta.optimizer_name | upper}}];       /* cost (res )  */
#else
static casadi_real **result_space_cost = NULL;
#endif

#if GRAD_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_grad[GRAD_SZ_RES_{{ meta.optimizer_name | upper}}];        /* grad (res )  */
#else
static casadi_real **result_space_grad = NULL;
#endif


#if F1_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_f1[F1_SZ_RES_{{ meta.optimizer_name | upper}}];            /* f1 (res )    */
#else
static casadi_real **result_space_f1 = NULL;
#endif


#if F2_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_f2[F2_SZ_RES_{{ meta.optimizer_name | upper}}];            /* f2 (res )    */
#else
static casadi_real **result_space_f2 = NULL;
#endif


#if W_COST_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_w_cost[W_COST_SZ_RES_{{ meta.optimizer_name | upper}}];            /* w_cost (res )    */
#else
static casadi_real **result_space_w_cost = NULL;
#endif


#if W1_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_w1[W1_SZ_RES_{{ meta.optimizer_name | upper}}];            /* w1 (res )    */
#else
static casadi_real **result_space_w1 = NULL;
#endif


#if W2_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_w2[W2_SZ_RES_{{ meta.optimizer_name | upper}}];            /* w2 (res )    */
#else
static casadi_real **result_space_w2 = NULL;
#endif


#if INIT_PENALTY_SZ_RES_{{ meta.optimizer_name | upper}} > 0
static casadi_real *result_space_init_penalty[INIT_PENALTY_SZ_RES_{{ meta.optimizer_name | upper}}];            /* init_penalty (res )    */
#else
static casadi_real **result_space_init_penalty = NULL;
#endif



/* ------U, XI, P, W------------------------------------------------------------ */

/*
 * Space for storing (u, xi, p, w)
 * that is, uxip_space = [u, xi, p, w]
 *
 * The memory layout of the u-xi-p-w space is described below
 *
 * | --- | -- 0
 * |     |
 * |  u  |
 * |     |
 * | --- |
 *
 * | --- | -- NU
 * |     |
 * |  ξ  |
 * |     |
 * | --- |
 *
 * | --- | -- NU + NXI
 * |     |
 * |  p  |
 * |     |
 * | --- |
 *
 * | --- |
 * | wc  | -- NU + NXI + NP
 * | --- |
 *
 * | --- | -- NU + NXI + NP + 1
 * |     |
 * |  w1 |
 * |     |
 * | --- |
 *
 * | --- | -- NU + NXI + NP + N1 + 1
 * |     |
 * |  w2 |
 * |     |
 * | --- |
 *
 */

#define IDX_XI_{{ meta.optimizer_name | upper}} NU_{{ meta.optimizer_name | upper}}
#define IDX_P_{{ meta.optimizer_name | upper}}  IDX_XI_{{ meta.optimizer_name | upper}} + NXI_{{ meta.optimizer_name | upper}}
#define IDX_WC_{{ meta.optimizer_name | upper}} IDX_P_{{ meta.optimizer_name | upper}} + NP_{{ meta.optimizer_name | upper}}
#define IDX_W1_{{ meta.optimizer_name | upper}} IDX_WC_{{ meta.optimizer_name | upper}} + 1
#define IDX_W2_{{ meta.optimizer_name | upper}} IDX_W1_{{ meta.optimizer_name | upper}} + N1_{{ meta.optimizer_name | upper}}
#define N_UXIPW_{{ meta.optimizer_name | upper}} IDX_W2_{{ meta.optimizer_name | upper}} + N2_{{ meta.optimizer_name | upper}}

static casadi_real uxip_space[N_UXIPW_{{ meta.optimizer_name | upper}}];

/**
 * This function should be called upon initialisation. The sets all w's to 1.
 */
void init_interface(void) {
    unsigned int i;
    unsigned int offset = IDX_WC_{{ meta.optimizer_name | upper}};
    unsigned int len = N1_{{ meta.optimizer_name | upper}} + N2_{{ meta.optimizer_name | upper}} + 1;
    for (i = 0; i < len; i++) {
        uxip_space[offset + i] = 1.0;
    }
}

/**
 * Copy (u, xi, p) into uxip_space
 *
 * Input arguments:
 * - `arg = {u, xi, p}`, where `u`, `xi` and `p` are pointer-to-double
 */
static void copy_args_into_uxip_space(const casadi_real** arg) {
    unsigned int i;
    for (i=0; i<NU_{{ meta.optimizer_name | upper}}; i++)  uxip_space[i] = arg[0][i];  /* copy u  */
    for (i=0; i<NXI_{{ meta.optimizer_name | upper}}; i++) uxip_space[IDX_XI_{{ meta.optimizer_name | upper}}+i] = arg[1][i];  /* copy xi */
    for (i=0; i<NP_{{ meta.optimizer_name | upper}}; i++)  uxip_space[IDX_P_{{ meta.optimizer_name | upper}}+i] = arg[2][i];  /* copy p  */
}


 /**
 * Copy (u, p) into uxip_space
 *
 * Input arguments:
 * - `arg = {u, p}`, where `u` and `p` are pointer-to-double
 */
static void copy_args_into_up_space(const casadi_real** arg) {
    unsigned int i;
    for (i=0; i<NU_{{ meta.optimizer_name | upper}}; i++) uxip_space[i] = arg[0][i];  /* copy u  */
    for (i=0; i<NP_{{ meta.optimizer_name | upper}}; i++) uxip_space[IDX_P_{{ meta.optimizer_name | upper}}+i] = arg[1][i];  /* copy p  */
}

/**
 * Copy (u, p, w) into uxip_space
 *
 * Input arguments:
 * - `arg = {u, p, w_cost, w1, w2}`, where `u` and `p` are pointer-to-double
 */
static void copy_args_into_upw_space(const casadi_real** arg) {
    unsigned int i;
    for (i=0; i<NU_{{ meta.optimizer_name | upper}}; i++) uxip_space[i] = arg[0][i];  /* copy u  */
    for (i=0; i<NP_{{ meta.optimizer_name | upper}}; i++) uxip_space[IDX_P_{{ meta.optimizer_name | upper}}+i] = arg[1][i];  /* copy p  */
    uxip_space[IDX_WC_{{ meta.optimizer_name | upper}}] = arg[2][0];  /* copy w_cost  */
    for (i=0; i<N1_{{ meta.optimizer_name | upper}}; i++) uxip_space[IDX_W1_{{ meta.optimizer_name | upper}}+i] = arg[3][i];  /* copy w_1  */
    for (i=0; i<N2_{{ meta.optimizer_name | upper}}; i++) uxip_space[IDX_W2_{{ meta.optimizer_name | upper}}+i] = arg[4][i];  /* copy w_2  */
}

/* ------COST------------------------------------------------------------------- */

int cost_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    const casadi_real* args__[COST_SZ_ARG_{{ meta.optimizer_name | upper}}] =
             {uxip_space,  /* :u  */
              uxip_space + IDX_XI_{{ meta.optimizer_name | upper}},   /* :xi  */
              uxip_space + IDX_P_{{ meta.optimizer_name | upper}} };  /* :p  */
    copy_args_into_uxip_space(arg);

    result_space_cost[0] = res[0];
    return {{meta.cost_function_name or 'phi'}}(
        args__,
        result_space_cost,
        allocated_i_workspace_cost,
        allocated_r_workspace_cost,
        (void*) 0);
}


/* ------GRADIENT--------------------------------------------------------------- */

int grad_cost_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    const casadi_real* args__[GRAD_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            { uxip_space,  /* :u  */
              uxip_space + IDX_XI_{{ meta.optimizer_name | upper}},  /* :xi  */
              uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p   */
    copy_args_into_uxip_space(arg);
    result_space_grad[0] = res[0];
    return {{meta.grad_function_name  or 'grad_phi'}}(
        args__,
        result_space_grad,
        allocated_i_workspace_grad,
        allocated_r_workspace_grad,
        (void*) 0);
}


/* ------MAPPING F1------------------------------------------------------------- */

int mapping_f1_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[F1_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            {uxip_space,  /* :u   */
            uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p  */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_f1
     * (memory has been allocated - see beginning of this file)
     */
    result_space_f1[0] = res[0];
    /*
     * Call auto-generated function {{meta.alm_mapping_f1_function_name}}
     * Implemented in: icasadi/extern/auto_casadi_mapping_f1.c
     */
    return {{meta.alm_mapping_f1_function_name}}(
        args__,
        result_space_f1,
        allocated_i_workspace_f1,
        allocated_r_workspace_f1,
        (void*) 0);
}


/* ------MAPPING F2------------------------------------------------------------- */

int mapping_f2_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[F2_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            {uxip_space,  /* :u   */
             uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p   */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_f2
     * (memory has been allocated - see beginning of this file)
     */
    result_space_f2[0] = res[0];
    /*
     * Call auto-generated function {{meta.constraint_penalty_function_name}}
     * Implemented in: icasadi/extern/auto_casadi_mapping_f2.c
     */
    return {{meta.constraint_penalty_function_name}}(
        args__,
        result_space_f2,
        allocated_i_workspace_f2,
        allocated_r_workspace_f2,
        (void*) 0);
}

/**
 * Interface to auto-generated CasADi function for w_cost(u, p)
 */
int preconditioning_w_cost_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[W_COST_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            {uxip_space,  /* :u   */
             uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p   */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_w_cost
     * (memory has been allocated - see beginning of this file)
     */
    result_space_w_cost[0] = res[0];
    /*
     * Call auto-generated function {{meta.w_cost_function_name}}
     * Implemented in: icasadi/extern/auto_preconditioning_functions.c
     */
    return {{meta.w_cost_function_name}}(
        args__,
        result_space_w_cost,
        allocated_i_workspace_w_cost,
        allocated_r_workspace_w_cost,
        (void*) 0);
}

/**
 * Interface to auto-generated CasADi function for w1(u, p), which computes an
 * n1-dimensional vector of scaling parameters
 */
int preconditioning_w1_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[W1_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            {uxip_space,  /* :u   */
             uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p   */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_w1
     * (memory has been allocated - see beginning of this file)
     */
    result_space_w1[0] = res[0];
    /*
     * Call auto-generated function {{meta.w_f1_function_name}}
     * Implemented in: icasadi/extern/auto_preconditioning_functions.c
     */
    return {{meta.w_f1_function_name}}(
        args__,
        result_space_w1,
        allocated_i_workspace_w1,
        allocated_r_workspace_w1,
        (void*) 0);
}

/**
 * Interface to auto-generated CasADi function for w2(u, p), which computes an
 * n2-dimensional vector of scaling parameters
 */
int preconditioning_w2_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[W2_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            {uxip_space,  /* :u   */
             uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p   */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_up_space(arg);
    /*
     * The result should be written in result_space_w2
     * (memory has been allocated - see beginning of this file)
     */
    result_space_w2[0] = res[0];
    /*
     * Call auto-generated function {{meta.w_f2_function_name}}
     * Implemented in: icasadi/extern/auto_preconditioning_functions.c
     */
    return {{meta.w_f2_function_name}}(
        args__,
        result_space_w2,
        allocated_i_workspace_w2,
        allocated_r_workspace_w2,
        (void*) 0);
}

/**
 * Interface to auto-generated CasADi function for rho_1(u, theta), which computes the initial
 * penalty parameter. Note that this is a function of u and theta = (p, w_cost, w1, w2) and the
 * caller needs to provide p, w_cost, w1 and w2
 */
int preconditioning_init_penalty_function_{{ meta.optimizer_name }}(const casadi_real** arg, casadi_real** res) {
    /* Array of pointers to where (u, p) are stored */
    const casadi_real* args__[INIT_PENALTY_SZ_ARG_{{ meta.optimizer_name | upper}}] =
            {uxip_space,  /* :u   */
             uxip_space + IDX_P_{{ meta.optimizer_name | upper}}};  /* :p   */
    /* Copy given data to variable `uxip_space` */
    copy_args_into_upw_space(arg);
    /*
     * The result should be written in result_space_init_penalty
     * (memory has been allocated - see beginning of this file)
     */
    result_space_init_penalty[0] = res[0];
    /*
     * Call auto-generated function {{meta.init_penalty_function_name}}
     * Implemented in: icasadi/extern/auto_preconditioning_functions.c
     */
    return {{meta.initial_penalty_function_name}}(
        args__,
        result_space_init_penalty,
        allocated_i_workspace_init_penalty,
        allocated_r_workspace_init_penalty,
        (void*) 0);
}

/*
 * This is to be used ONLY for DEBUG purposes
 * Compile with -DTEST_INTERFACE
 */
#if defined(TEST_INTERFACE) && defined(PRECONDITIONING_{{ meta.optimizer_name | upper}})

static casadi_real u_test[NU_{{ meta.optimizer_name | upper}}];
static casadi_real p_test[NP_{{ meta.optimizer_name | upper}}];

static void init_up_test(void) {
    unsigned int i;
    for (i=0; i<NU_{{ meta.optimizer_name | upper}}; i++){
        u_test[i] = 20 + i;
    }
    for (i=0; i<NP_{{ meta.optimizer_name | upper}}; i++){
        p_test[i] = 1.5 + 15 * i;
    }
}

static void print_static_array(void){
    unsigned int i;
    for (i=0; i<NU_{{ meta.optimizer_name | upper}}; i++){
        printf("u[%2d] = %4.2f\n", i, uxip_space[i]);
    }
    for (i=0; i<NXI_{{ meta.optimizer_name | upper}}; i++){
        printf("ξ[%2d] = %4.2f\n", i, uxip_space[IDX_XI_{{ meta.optimizer_name | upper}}+i]);
    }
    for (i=0; i<NP_{{ meta.optimizer_name | upper}}; i++){
        printf("p[%2d] = %4.2f\n", i, uxip_space[IDX_P_{{ meta.optimizer_name | upper}}+i]);
    }
    printf("w_cost = %g\n", uxip_space[IDX_WC_{{ meta.optimizer_name | upper}}]);
#if N1_{{ meta.optimizer_name | upper}} > 0
     for (i=0; i<N1_{{ meta.optimizer_name | upper}}; i++){
        printf("w1[%2d] = %g\n", i, uxip_space[IDX_W1_{{ meta.optimizer_name | upper}}+i]);
    }
#endif /* IF N1 > 0 */
#if N2_{{ meta.optimizer_name | upper}} > 0
     for (i=0; i<N2_{{ meta.optimizer_name | upper}}; i++){
        printf("w2[%2d] = %g\n", i, uxip_space[IDX_W2_{{ meta.optimizer_name | upper}}+i]);
    }
#endif /* IF N2 > 0 */
}

static void test_w_cost(void) {
    const casadi_real *args[2] = {u_test, p_test};
    casadi_real *res[1] = {uxip_space + IDX_WC_{{ meta.optimizer_name | upper}}};
    preconditioning_w_cost_function_{{ meta.optimizer_name }}(args, res);
}

static void test_w1(void) {
    const casadi_real *args[2] = {u_test, p_test};
    casadi_real *res[1] = { uxip_space + IDX_W1_{{ meta.optimizer_name | upper}} };
    preconditioning_w1_function_{{ meta.optimizer_name }}(args, res);
}

static void test_w2(void) {
    const casadi_real *args[2] = {u_test, p_test};
    casadi_real *res[1] = { uxip_space + IDX_W2_{{ meta.optimizer_name | upper}} };
    preconditioning_w2_function_{{ meta.optimizer_name }}(args, res);
}

static casadi_real test_initial_penalty(void) {
    casadi_real *wc_ptr = uxip_space + IDX_WC_{{ meta.optimizer_name | upper}};
    casadi_real *w1_ptr = uxip_space + IDX_W1_{{ meta.optimizer_name | upper}};
    casadi_real *w2_ptr = uxip_space + IDX_W2_{{ meta.optimizer_name | upper}};
    const casadi_real *args[5] = {u_test, p_test, wc_ptr, w1_ptr, w2_ptr};
    casadi_real initial_penalty = -1.;
    casadi_real *res[1] = { &initial_penalty };
    preconditioning_init_penalty_function_{{ meta.optimizer_name }}(args, res);
    return initial_penalty;
}

int main(void) {
    init_interface();
    init_up_test();
    test_w_cost();
    test_w1();
    test_w2();
    casadi_real rho1 = test_initial_penalty();
    print_static_array();
    printf("rho1 = %g\n", rho1);
    return 0;
}

#endif /* END of TEST_INTERFACE and PRECONDITIONING_{{ meta.optimizer_name | upper}} */
