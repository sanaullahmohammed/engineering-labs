; A4.s
; Find sum of numbers in array
		AREA ACODE, CODE, READONLY
ENTRY
START
; Lower and upper bounds
		LDR R0, =LB
		LDR R1, =UB-2
; initialize r2 to 0
		LDRH R2, [R0]
LOOP
;sum of numbers in an array
		LDRH R3, [R0, #2]!
		ADD R2, R3, r2 ; r2 = r3 + r2
;terminating condition
		CMP R0, R1 ; LB = UB
		BNE LOOP
		LDR R0, =OUT
		STR R2, [R0] ; mem[R0] = R2
STOP 	B STOP
		AREA AIN, DATA, READONLY
LB 		DCW 1, 2, 3, 4, 5 ; array of numbers
UB 		DCW 0
		AREA AOUT, DATA, READWRITE
OUT 	DCD 0x0 ; sum of array numbers
		END