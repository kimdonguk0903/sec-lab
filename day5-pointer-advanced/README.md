# 🧠 Day 5 — 포인터 심화 (배열, 함수, 주소 전달)

## 📌 학습 목표
- 함수 호출 시 값 전달 vs 주소 전달 차이 이해
- 배열과 포인터의 관계 학습
- GDB로 배열과 포인터 추적 실습

---

## 🧩 실습 파일

### 1. `swap_pointer.c`
- **내용:** 함수 인자 전달 방식 비교 (값/주소)
- **핵심 포인트:**  
  - `swap_by_value()` → 원본 값 변하지 않음  
  - `swap_by_reference()` → 주소를 통해 원본 값 변경  

---

### 2. `array_pointer.c`
- **내용:** 배열과 포인터의 관계 확인
- **핵심 포인트:**  
  - 배열 이름(`arr`)은 첫 번째 원소의 주소  
  - `arr[i] == *(arr + i)`  
  - 주소 연산 및 포인터 탐색 이해  

---

### 3. `array_function.c`
- **내용:** 배열을 함수에 전달하고 포인터로 접근
- **핵심 포인트:**  
  - 함수 인자로 배열 전달 시 `int *p`로 전달  
  - 배열 크기(`size`)를 함께 전달해야 안전  

---

## 🧠 GDB 실습 예시
```bash
gcc -g array_function.c -o array_function
gdb ./array_function
(gdb) break main
(gdb) run
(gdb) step
(gdb) print nums
(gdb) print &nums
(gdb) print *nums
(gdb) continue
```
