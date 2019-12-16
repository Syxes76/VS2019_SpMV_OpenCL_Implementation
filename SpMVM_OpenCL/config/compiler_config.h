#ifndef COMPILER_CONFIG_H
#define COMPILER_CONFIG_H

/*--------------------------------------------------*/
//            Storage format related
//
// This setting sets the precision of the floating point calculations:
// 1 = single-precision
// 2 = double-precision
#define PRECISION 2
//
// This setting is required in order to pre-allocate sufficient space
// for the diag array of the DIA format.
#define MAX_DIAG 10000 // default is 10000
// same but for HDIA
#define MAX_HDIAG 10000 // default is 10000
// same but for ELLG
#define MAX_ELLG 10000 // default is 10000
// same but for HLL
#define MAX_HLL 10000 // default is 10000
//
// Size of 'hacks' for hacked formats 
// should be multiple of WARP_SIZE
// HLL format
#define HLL_HACKSIZE 32 // default is 32
// HDIA format
#define HDIA_HACKSIZE 32 // default is 32
//
// ELL-CSR HYB format
// based on: "Accelerating Sparse Matrix Vector Multiplication in Iterative Methods Using GPU"
// by: Kiran Kumar Matam & Kishore Kothapalli
//
#define ELL_ROW_MAX 256 // default is 256; should be a multiple of 32
//
/*--------------------------------------------------*/

/*--------------------------------------------------*/
//            Kernel related
//
#define KERNEL_FOLDER "../kernels"
//
#define COO_KERNEL_FILE "COO_kernel.cl"
#define GMVM_KERNEL_FILE "GMVM_kernel.cl"
#define CSR_KERNEL_FILE "CSR_kernel.cl"
#define JAD_KERNEL_FILE "JAD_kernel.cl"
#define ELL_KERNEL_FILE "ELL_kernel.cl"
#define ELLG_KERNEL_FILE "ELLG_kernel.cl"
#define HLL_KERNEL_FILE "HLL_kernel.cl"
#define DIA_KERNEL_FILE "DIA_kernel.cl"
#define HDIA_KERNEL_FILE "HDIA_kernel.cl"
//
//#define MAX_THREADS 4*5*2048 // max active threads for a GTX 1080: GPC * SM * 2048 !!! NO LONGER USED !!!
#define WARP_SIZE 32
#define WORKGROUP_SIZE 256 // default is 256
#define WARPS_PER_WORKGROUP (WORKGROUP_SIZE / WARP_SIZE)
//
// required for spmv_coo_reduce_update
#define __WORKGROUP_SIZE 512
//
// Repeat kernel operation for evaluating performace
#define REPEAT 200
//
// This setting tunes the memory used by each workgroup in the JAD kernel
// Recommended to use a multiple of the WORKGROUSIZE
#define MAX_NJAD_PER_WG 1024 // default is 256
// same but for DIA
#define MAX_NDIAG_PER_WG 1024 // default is 256
//
//
// CSR Parameters
#define CSR_WORKGROUP_SIZE 128 // default is 128
//
// Kernels to run (0: Off; 1: On)
#define GMVM_SEQ 1
#define GMVM 1
//
#define CSR_SEQ 1
#define CSR 1
//
#define DIA_SEQ 1
#define DIA 1
#define HDIA_SEQ 1
#define HDIA 1
//
#define ELL_SEQ 1
#define ELL 1
#define ELLG_SEQ 1
#define ELLG 1
#define HLL_SEQ 1
#define HLL 1
//
#define HYB_ELL_SEQ 1
#define HYB_ELL 1
#define HYB_ELLG_SEQ 1
#define HYB_ELLG 1
#define HYB_HLL_SEQ 1
#define HYB_HLL 1
//
#define JAD_SEQ 1
#define JAD 1
/*--------------------------------------------------*/

/*--------------------------------------------------*/
//            Input/Output related
//
#define INPUT_FILE_MODE 1 // 0 for standard input files (i.e. .../input/); 1 for generated input files (i.e. .../input/random/)
//
#define INPUT_FOLDER "../input"
#define INPUT_FILE "sherman3.mtx"
#define SUITE_INPUT_FILES "sherman3.mtx;psmigr_1.mtx;msc01050.mtx;dynamicSoaringProblem_1.mtx" //delimiter is ;
//
#define GENERATOR_FOLDER "random"
#define RANDOM_INPUT_FILE "random_spread_4.mtx"
#define SUITE_RANDOM_INPUT_FILES "imbalanced_cols.mtx;imbalanced_cols_inverted.mtx;imbalanced_rows.mtx;imbalanced_rows_inverted.mtx;random_spread_1.mtx;random_spread_2.mtx;random_spread_3.mtx" //same as above but for randomly generated matrices
//
#define OUTPUT_FOLDER "../output"
//
// Storage format-specific output folders
#define COO_OUTPUT_FOLDER "COO"
#define GMVM_OUTPUT_FOLDER "GMVM"
#define CSR_OUTPUT_FOLDER "CSR"
#define JAD_OUTPUT_FOLDER "JAD"
#define ELL_OUTPUT_FOLDER "ELL"
#define DIA_OUTPUT_FOLDER "DIA"
#define HYB_OUTPUT_FOLDER "HYB"
#define SUITE_OUTPUT_FOLDER "SUITE"
//
#define OUTPUT_FILENAME "output"
#define OUTPUT_FILEFORMAT ".txt"
//
// Print out data about each storage format (WARNING: AVOID FOR VERY LARGE MATRICES!)
#define COO_LOG 0
#define MAT_LOG 0
#define CSR_LOG 0
#define JAD_LOG 0
#define ELLG_LOG 0
#define HLL_LOG 0
#define DIA_LOG 0
#define HDIA_LOG 0
#define HYB_ELLG_LOG 0
#define HYB_HLL_LOG 0
//
// Print out output data for each kernel
#define COO_SEQ_OUTPUT_LOG 1
#define COO_OUTPUT_LOG 1
//
#define GMVM_SEQ_OUTPUT_LOG 1
#define GMVM_OUTPUT_LOG 1
//
#define CSR_SEQ_OUTPUT_LOG 1
#define CSR_OUTPUT_LOG 1
//
#define JAD_SEQ_OUTPUT_LOG 1
#define JAD_OUTPUT_LOG 1
//
#define ELL_SEQ_OUTPUT_LOG 1
#define ELL_OUTPUT_LOG 1
#define ELLG_SEQ_OUTPUT_LOG 1
#define ELLG_OUTPUT_LOG 1
#define HLL_SEQ_OUTPUT_LOG 1
#define HLL_OUTPUT_LOG 1
//
#define DIA_SEQ_OUTPUT_LOG 1
#define DIA_OUTPUT_LOG 1
#define HDIA_SEQ_OUTPUT_LOG 1
#define HDIA_OUTPUT_LOG 1
//
#define HYB_ELL_SEQ_OUTPUT_LOG 1
#define HYB_ELL_OUTPUT_LOG 1
#define HYB_ELLG_SEQ_OUTPUT_LOG 1
#define HYB_ELLG_OUTPUT_LOG 1
#define HYB_HLL_SEQ_OUTPUT_LOG 1
#define HYB_HLL_OUTPUT_LOG 1
//
/*--------------------------------------------------*/
#endif