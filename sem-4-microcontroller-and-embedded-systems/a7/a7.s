;Bubble  sort

		AREA	ACODE, CODE, READONLY
		ENTRY
START	
		MOV		R5, #5
L1
		LDR		R0, =AOUT
		LDR		R1, =UB-4
L2
		LDM		R0, {R2, R3}
		CMP		R2, R3
		MOVGT	R4, R2
		STMGT	R0, {R3, R4}
		
		ADD		R0, #4
		CMP		R0, R1
		BNE		L2
		
		SUBS	R5, #1
		BNE		L1
		
STOP	B		STOP

		AREA	AOUT, DATA, READWRITE
OUT		DCD		5, 4, 3, 2, 1
UB		DCD		0
		END
		