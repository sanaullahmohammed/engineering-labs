		AREA 	ACODE, CODE, READONLY
		ENTRY
START
	; Lower and upper bounds
		LDR 	R0, =LB
		LDR 	R1, =UB-2
		MOV 	R3, #10
	; initialize r2 to 0, 1 or a[0].
		LDRH 	R2, [R0]
LOOP
	;sum of N natural numbers
		ADD 	R2, R2, R3 ; r2 = r2 + r3
	;terminating condition
		SUBS 	R3, R3, #1 ; N, N-1, 3, 2, 1, 0
		BNE 	LOOP
		LDR 	R0, =OUT
		STR 	R2, [R0] ; mem[R0] = R2, minimum value
STOP 	B 		STOP
		AREA 	AIN, DATA, READONLY
LB 		DCW 	0 ; sum = 0
UB 		DCW 	0
		AREA 	AOUT,DATA, READWRITE
OUT 	DCD 	0x0 ; Result stored here
		END
