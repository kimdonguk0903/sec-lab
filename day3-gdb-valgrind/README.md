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
