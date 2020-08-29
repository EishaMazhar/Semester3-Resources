   .486                                    ; create 32 bit code
   .model flat, stdcall                    ; 32 bit memory model
   option casemap:none                     ; case sensitive

  ; ------------------------------------------------
  ; Irvine library
  ; ------------------------------------------------

   include     \Irvine\Irvine32.inc
   includelib  \Irvine\Irvine32.lib
   includelib  \Irvine\kernel32.lib
   includelib  \Irvine\user32.lib
    
.data
   str1 byte "How many spaces are there in this string" , 0

.code
main PROC
      mov	ebx, offset str1
      mov   al,0
      
      mov   ah, [ebx]
  l1: cmp   ah, ' '         ; check space
      jne   chk
      inc   al              ; increment al (contains count)
 chk: inc   ebx             ; check end of string
      mov   ah, [ebx]       ; by reading next character
      cmp   ah, 0           ; 
      jnz   l1              ; read next char if not null char

      call	DumpRegs       
      call	WaitMsg        
      exit
main ENDP
END main