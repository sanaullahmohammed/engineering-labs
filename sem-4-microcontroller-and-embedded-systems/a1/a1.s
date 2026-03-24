; A1.s
; Multiplication of 16bit data
		AREA	 ACODE, CODE, READONLY
ENTRY
START
		LDR 	R0, =LB
		LDR 	R1, =UB-2
		LDRH 	R2, [R0] ; R1 = mem[R0]
		LDRH 	R3, [R0, #2] ; R2 = mem[R0+1]
		MUL 	R2, R3, R2 ; R2 = R3*R2
		LDR 	R0, =OUT
		STR 	R2, [R0] ; mem[R0] = R2
STOP 	B 		STOP
		AREA 	AIN, DATA, READONLY
LB 		DCW 	0x10, 0x10 ; Test for other input values
UB 		DCW 	0x0
		AREA 	AOUT, DATA, READWRITE
OUT		DCD 	0x0 ; Result of multiplication here
		END