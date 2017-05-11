//   NAME			CODE 	DW	with 0	OP 	Link
func(beq_cmd, 		0x1A, 	21, 0,		==, 0)
func(bne_cmd, 		0x20, 	21, 0,		!=, 0)
func(bgez_cmd, 		0x1B, 	16, 1,		>=, 0)
func(bgezal_cmd,	0x1C, 	16, 1,		>=, 1)
func(bgtz_cmd, 		0x1D, 	16, 1,		>, 	0)
func(blez_cmd, 		0x1E, 	16, 1,		<, 	0)
func(bltz_cmd, 		0x1F, 	16, 1,		<, 	0)