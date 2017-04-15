`define NOOP_CMD 	0x0
// arithmetic
`define ADD_CMD  	0x1
`define ADDI_CMD 	0x2
`define MUL_CMD  	0x3
`define MULI_CMD  	0x4
`define SUB_CMD  	0x5
`define SUBI_CMD  	0x6
`define DIV_CMD  	0x7
`define DIVI_CMD  	0x8
// logic
`define AND_CMD  	0x9
`define ANDI_CMD 	0xA
`define OR_CMD  	0xB
`define ORI_CMD 	0xC
`define XOR_CMD  	0xD
`define XORI_CMD 	0xE
`define INV_CMD  	0xF
// jumps
`define J_CMD 		0x10
`define JAL_CMD 	0x11
`define JR_CMD 		0x12
`define JLB_CMD 	0x13
// shifts
`define SLL_CMD 	0x14
`define SLLV_CMD 	0x15
`define SRL_CMD 	0x16
`define SRLV_CMD 	0x17
`define SLA_CMD 	0x18
`define SRA_CMD 	0x19
// compares
`define BEQ_CMD  	0x1A
`define BGEZ_CMD 	0x1B
`define BGEZAL_CMD 	0x1C
`define BGTZ_CMD 	0x1D
`define BLEZ_CMD 	0x1E
`define BLTZ_CMD 	0x1F
`define BNE_CMD 	0x20
// move
`define SW_CMD 		0x21
`define LW_CMD 		0x22
`define PS_CMD 		0x23
`define PSI_CMD 	0x24