include Irvine32.inc
.data
	arr word 1,2,3,4,5
	rowsize=($-arr)
		word 6,7,8,9,10
		word 0,1,2,3,4
.code
main proc
	rowind=0
	colind=0
	mov eax,0
	mov ebx,offset arr
	add ebx,rowind*rowsize
	mov esi,colind
	mov ecx,3
	L2:
	push ecx
	mov ecx,5
	L1:
		mov al,[ebx+esi*type arr]	
		call writedec
		inc esi							
	loop L1
	add ebx,rowind*rowsize
	call crlf
	pop ecx
	loop l2
	exit
main endp
end main
