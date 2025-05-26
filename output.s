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
[token] IDENTIFIER
[token] PLUS
[token] IDENTIFIER
[debug] line 4: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[debug] line 5: current_indent=0, new_indent=0, stack_top=1
[token] NEWLINE
[token] IF
[token] IDENTIFIER
[token] GT
[token] INT_NUM
[token] COLON
[debug] line 6: current_indent=0, new_indent=4, stack_top=1
[token] NEWLINE
[token] INDENT
[token] IDENTIFIER
[token] ASSIGN
[token] IDENTIFIER
[token] TIMES
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
[token] IDENTIFIER
[token] OTHER
[token] INT_NUM
[debug] line 9: current_indent=4, new_indent=0, stack_top=2
[token] NEWLINE
[token] DEDENT
[token] OTHER
Type: 0
  Type: 2  val:x
    Type: 38  val:1 (intValue: 0)
  Type: 2  val:y
    Type: 38  val:3 (intValue: 0)
  Type: 2  val:z
    Type: 31
      Type: 43  val:x
      Type: 43  val:y
  Type: 7
    Type: 28
      Type: 43  val:z
      Type: 38  val:3 (intValue: 0)
    Type: 0
      Type: 2  val:z
        Type: 33
          Type: 43  val:z
          Type: 38  val:2 (intValue: 0)
    Type: 12
      Type: 0
        Type: 2  val:z
          Type: 32
            Type: 43  val:z
            Type: 38  val:1 (intValue: 0)
; Generated ARM assembly
.section .text
.global _start
_start:
  @ Assignment to variable 'x'
  mov r0, #1
  @ (Storing r0 to variable 'x')
  @ Assignment to variable 'y'
  mov r0, #3
  @ (Storing r0 to variable 'y')
  @ Assignment to variable 'z'
  @ Load identifier 'x' (not implemented)
  push {r0}
  @ Load identifier 'y' (not implemented)
  pop {r1}
  add r0, r1, r0
  @ (Storing r0 to variable 'z')
  @ If condition
  @ Load identifier 'z' (not implemented)
  push {r0}
  mov r0, #3
  pop {r1}
  cmp r1, r0
  movgt r0, #1
  movle r0, #0
  cmp r0, #0
  beq ifend_1
  @ Assignment to variable 'z'
  @ Load identifier 'z' (not implemented)
  push {r0}
  mov r0, #2
  pop {r1}
  mul r0, r1, r0
  @ (Storing r0 to variable 'z')
  b ifend_1
ifend_1:
  @ Else block
  @ Assignment to variable 'z'
  @ Load identifier 'z' (not implemented)
  push {r0}
  mov r0, #1
  pop {r1}
  sub r0, r1, r0
  @ (Storing r0 to variable 'z')
ifend_1:
  mov r7, #1
  mov r0, #0
  svc #0
