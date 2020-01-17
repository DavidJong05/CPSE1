.cpu cortex-m0 
.bss
	buffer: .fill 0x28
.text 
.align 2 
.global decoder

decoder:
	PUSH {R4, R5, R6, R7, LR} 	//push registers to stack
	LDR	R3, =buffer				//start buffer in R3
	LDR	R4, =compressed			//in R4 first memorylocation
	MOV	R5, #0					//index pointer = 0	
	MOV	R6, #0					//offset = 0 
	MOV	R7, #0					//length = 0
	
mainLoop:
	ADD R0, R4, R5				//add adress of R4 with index R5 in R0
	LDRB R0, [r0]				//get value
	ADD R5, R5, #1				//index pointer +1 
	CMP R0, #0					//check end of compression
	BEQ	done
	
	CMP R0, #'@'				//check if R0 is compressed
	BEQ	decompress			
	bl rotate				
	bl uart_put_char			//print char in R0
	b mainLoop					//continue
	
	
	
decompress:
	ADD R6, R4, R5				//add adress of R4 with index R5 in R6
	LDRB r6, [R6]				//get value
	ADD R5, R5, #1				//index pointer +1
	ADD R7, R4, R5				//add adress of R4 with index R5 in R7
	LDRB r7, [R7]				//get value
	ADD R5, R5, #1				//index pointer +1
	SUB R6, R6, #'0'			//'0'(==48)
	SUB R7, R7, #'0'			//'0'(==48)
	
decompressLoop:
	ADD R0, R3, R6				//add R6 and R3 in R0
	LDRB R0, [R0]				//get value
	bl rotate					
	bl uart_put_char			//print char in R0
	SUB	R7, R7, #1				//length -1
	BEQ mainLoop				//if decompressed
	b decompressLoop		
	
rotate:
	PUSH {LR}
	MOV R1, #39					//bufferlength in R1
rotateLoop:
	SUB R1, R1, #1 				//set R1 1 index lower
	ADD R2, R3, R1 				//add adress R3 with index R1 in R2
	LDRB R2, [R2] 				//get value
	ADD R1, R1, #1			
	STRB R2, [R3, R1]			//store char in buffer[R1]
	SUB R1, R1, #1				//looping

	CMP R1, #0					//compare R1 with 0
	BEQ rotateDone			
	b rotateLoop			
	
rotateDone:
	STRB R0, [R3, #0]			//put current char on index 0
	POP {PC}	
	
done:
	POP {R4, R5, R6, R7, PC} 	//pop to program counter