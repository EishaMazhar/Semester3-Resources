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
   val1     dword  10000h
   val2     dword  40000h
   val3     dword  20000h
   finalVal dword  ?

.code
main PROC
      mov	eax,val1		; start with 10000h
      add	eax,val2		; add 40000h
      sub	eax,val3		; subtract 20000h
      mov	finalVal,eax		; store the result (30000h)
      call	DumpRegs                ; 
      call	WaitMsg                 ; wait for a keypress
      exit
main ENDP
END main