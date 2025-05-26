[token] IDENTIFIER
[token] ASSIGN
[token] INT_NUM
[debug] line 2: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[token] IDENTIFIER
[token] ASSIGN
[token] INT_NUM
[debug] line 3: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[token] IDENTIFIER
[token] ASSIGN
[token] INT_NUM
[debug] line 4: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[debug] line 5: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[token] IF
[token] IDENTIFIER
[token] GT
[token] IDENTIFIER
[token] COLON
[debug] line 6: current_indent=0, new_indent=4, stack_top=1
[token] NEWLINE
[token] INDENT
[token] IDENTIFIER
[token] ASSIGN
[token] INT_NUM
[debug] line 7: current_indent=4, new_indent=0, stack_top=2
[token] NEWLINE
[token] DEDENT
[token] ELSE
[token] COLON
[debug] line 8: current_indent=0, new_indent=4, stack_top=1
[token] NEWLINE
[token] INDENT
[token] IDENTIFIER
[token] ASSIGN
[token] INT_NUM
[debug] line 9: current_indent=4, new_indent=0, stack_top=2
[token] NEWLINE
[token] DEDENT
[debug] line 10: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[token] PRINT
[token] OTHER
[token] IDENTIFIER
[token] OTHER
[debug] line 11: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[token] OTHER
; Parsing successful, generating code...
; Generated AST:
Type: 0
  Type: 2  val:temperature
    Type: 38  val:38 (intValue: 0)
  Type: 2  val:threshold
    Type: 38  val:37 (intValue: 0)
  Type: 2  val:alert
    Type: 38  val:0 (intValue: 0)
  Type: 7
    Type: 28
      Type: 43  val:temperature
      Type: 43  val:threshold
    Type: 0
      Type: 2  val:alert
        Type: 38  val:1 (intValue: 0)
    Type: 12
      Type: 0
        Type: 2  val:alert
          Type: 38  val:0 (intValue: 0)
  Type: 19
    Type: 43  val:alert
; Generated symbol table
; Generated ARM assembly

; Symbol Table (Variable -> Stack Offset)

.section .text
.global _start
_start:
  sub sp, sp, #256  @ Allocate stack frame
  @ Assignment to variable 'temperature'
  mov r0, #38
  str r0, [sp, #224]  @ Store to variable 'temperature'
  @ Assignment to variable 'threshold'
  mov r0, #37
  str r0, [sp, #228]  @ Store to variable 'threshold'
  @ Assignment to variable 'alert'
  mov r0, #0
  str r0, [sp, #232]  @ Store to variable 'alert'
  @ If condition
  ldr r0, [sp, #224]  @ Load identifier 'temperature'
  push {r0}
  ldr r0, [sp, #228]  @ Load identifier 'threshold'
  pop {r1}
  cmp r1, r0
  movgt r0, #1
  movle r0, #0
  cmp r0, #0
  beq ifend_1
  @ Assignment to variable 'alert'
  mov r0, #1
  str r0, [sp, #232]  @ Store to variable 'alert'
  b ifend_1
ifend_1:
  @ Else block
  @ Assignment to variable 'alert'
  mov r0, #0
  str r0, [sp, #232]  @ Store to variable 'alert'
ifend_1:
  @ Print statement
  ldr r0, [sp, #232]  @ Load identifier 'alert'
  mov r1, r0
  ldr r0, =msg
  mov r2, #4
  mov r7, #4  @ syscall write
  svc #0
  mov r7, #1
  mov r0, #0
  svc #0
