# Day 3 — 프로세스, 스레드, 스택 메모리 실습 (GDB 사용)

## 🧠 학습 목표
- 프로세스(Process)와 스레드(Thread)의 차이를 이해한다.
- 프로그램 메모리 구조(Stack, Heap, Data, Text)를 이해한다.
- GDB를 사용하여 변수 추적 및 메모리 동작을 관찰한다.
- 함수 호출 시 스택 프레임(stack frame)과 스택 성장(stack growth)을 시각적으로 이해한다.

---

## 🧩 오늘 실습 내용

### 1️⃣ 변수 추적 및 스택 관찰
**파일:** `day3-gdb-valgrind/basic_stack.c`

- 간단한 C 프로그램을 작성하고 GDB를 이용하여:
  - `print` 명령으로 변수 값 확인
  - `print &a` 명령으로 변수 주소 확인
  - 지역 변수들이 함수 호출 시 스택에 올라가고, 함수 종료 시 사라지는 것을 관찰
- 스택 주소가 함수 호출이 깊어질수록 작아지는 것 확인

**GDB 실습 예시:**
```bash
gcc -g -o basic_stack basic_stack.c
gdb ./basic_stack
(gdb) break main
(gdb) run
(gdb) next
(gdb) print a
(gdb) print &a
(gdb) continue
```
### 2️⃣ 함수 호출 스택 추적
**파일:** `day3-gdb-valgrind/stack_trace.c`

- 함수 호출 시 스택 프레임 확인 (backtrace, info locals)
- 스택 주소 감소와 함수별 지역 변수 관찰

**GDB 실습 예시:**
```bash
gcc -g -o stack_trace stack_trace.c
gdb ./stack_trace
(gdb) break funcB
(gdb) run
(gdb) backtrace
#0 funcB (y=7)
#1 funcA (z=6)
#2 main ()
(gdb) info locals
(gdb) print &y
(gdb) print &z
(gdb) print &num
```
관찰 내용

- 스택 프레임 생성 순서: main → funcA → funcB → funcC
- 함수 종료 시 해당 프레임 제거
- 프로그램 종료 후에는 스택이 사라져 backtrace 명령에서 "No stack." 메시지 출력

### 3️⃣ 스택 vs 힙 메모리 비교
**파일:** `day3-gdb-valgrind/memory_compare.c`

- 스택 변수와 힙 변수 주소 확인
- 스택과 힙의 메모리 영역 차이 관찰

**GDB 실습 예시:**
```bash
gcc -g -o memory_compare memory_compare.c
gdb ./memory_compare
(gdb) break main
(gdb) run
(gdb) print &stack_var
(gdb) print heap_var
(gdb) x/4x heap_var
(gdb) continue
(gdb) quit
```
관찰 내용

- 스택 변수(stack_var) 주소: 높은 메모리 영역 (0x7ffffff...)
- 힙 변수(heap_var) 주소: 낮은 메모리 영역 (0x55...)
- 스택 위쪽, 힙 아래쪽 메모리 구조 확인
