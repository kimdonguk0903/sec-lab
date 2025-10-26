# Day 3 — 프로세스, 스레드, 스택 메모리 실습 (GDB 사용)

## 🧠 학습 목표
- 포인터의 구조와 주소 연산 이해
- malloc/free를 이용한 동적 메모리 관리
- 메모리 누수 및 세그멘테이션 폴트 이해
- GDB, Valgrind를 이용한 메모리 추적 실습

---

## 🧩 오늘 실습 내용

### 1️⃣ 실습 목록
1. pointer_basic.c
- 포인터 선언과 값 추적
- *p를 이용해 변수 값 변경
- 학습 포인트:
  p는 주소를 저장, *p는 그 주소 안의 실제 값 
  *p = &num; 는 잘못된 접근(타입 불일치)

2. malloc_free.c
- malloc으로 힙 메모리 동적 할당
- free() 후 접근 시 Undefined Behavior 발생
- GDB로 ptr 주소와 값 추적

3. memory_leak.c
- 메모리 누수 발생 의도 (free() 없음)
- Valgrind로 누수 확인
- 결과: 40 bytes in 1 blocks definitely lost

4. day4-memory-2.c
- 메모리 누수 예제와 정상 해제 예제 비교
- allocate_and_use() → 누수 발생
- allocate_and_free() → 정상 해제
Valgrind 결과:
- 누수 함수: 40 bytes lost
- 정상 해제 함수: 누수 없음
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
**파일:** `./stack_trace.c`

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
**파일:** `./memory_compare.c`

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
