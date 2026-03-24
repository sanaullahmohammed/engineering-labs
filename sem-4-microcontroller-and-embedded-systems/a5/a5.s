			;a5
			AREA ACODE, CODE, READONLY
			ENTRY
START
			LDR R0, =LB
			LDR R1, =UB-2
			MOV R3, #5
			
			LDRH R2, [R0]
LOOP
			LDRH R1, [R0]
			LDRH R2, [R0, #2]!
			
			CMP R1, R3
			BNE LOOP
			
			LDR R0, =OUT
			STR R2, [R0]
STOP		B	STOP

			AREA AIN, DATA, READONLY
LB			DCW  1,1,2,4,3,9,4,16,5,25
UB			DCW 0

			AREA AOUT, DATA, READWRITE
OUT			DCD  0X0
			END
				