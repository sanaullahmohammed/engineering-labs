		;a6
			AREA	 ACODE, CODE, READONLY
			ENTRY
START
			LDR		 R0, =LB
			LDR		 R1, =UB-2
			
			LDRH	 R2, [R0]
LOOP
			LDRH 	 R3, [R0, #2]!
			CMP    	 R2, R3
			MOVGT 	 R2, R3
			CMP		 R0, R1
			BNE		 LOOP
			
			LDR 	 R0, =OUT
			STR      R2, [R0]
STOP		B	     STOP

			AREA AIN, DATA, READONLY
LB			DCW  1,2,3,4,5
UB			DCW 0

			AREA AOUT, DATA, READWRITE
OUT			DCD  0X0
			END
				