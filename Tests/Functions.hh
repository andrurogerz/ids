// RUN: %idt -export-macro IDT_TEST_ABI %s 2>&1 | %FileCheck %s

// CHECK: Functions.hh:[[@LINE+1]]:78: remark: unexported public interface 'function_1'
__attribute__((always_inline)) [[deprecated("this function is deprecated")]] int function_1(int);

// CHECK: Functions.hh:[[@LINE+1]]:59: remark: unexported public interface 'function_2'
__attribute__((deprecated("this function is deprecated")))int function_2(int);

// CHECK: Functions.hh:[[@LINE+1]]:55: remark: unexported public interface 'function_3'
[[nodiscard]] __attribute__((noinline)) /* comment */ int function_3(int);

// CHECK: Functions.hh:[[@LINE+1]]:73: remark: unexported public interface 'function_4'
__attribute__((noinline)) [[deprecated("this function is deprecated")]] int function_4(int);

// CHECK: Functions.hh:[[@LINE+2]]:15: remark: unexported public interface 'function_5'
[[nodiscard]] __attribute__((deprecated("this function is deprecated")))
/* comment */ int function_5(int);

// CHECK: Functions.hh:[[@LINE+2]]:1: remark: unexported public interface 'function_6'
[[nodiscard]]
int function_6(int);

// CHECK: Functions.hh:[[@LINE+3]]:1: remark: unexported public interface 'function_7'
[[nodiscard]] [[deprecated("this function is deprecated")]] /* two line
                                                               comment */
int function_7(int);

// CHECK: Functions.hh:[[@LINE+2]]:15: remark: unexported public interface 'function_8'
[[nodiscard]] // this is a comment
/* comment */ int function_8(int);

// CHECK: Functions.hh:[[@LINE+2]]:58: remark: unexported public interface 'function_9'
[[nodiscard]] // this is a comment
__attribute((deprecated("this function is deprecated"))) int function_9(int);

struct Class {
  // CHECK: Functions.hh:[[@LINE+1]]:80: remark: unexported public interface 'method_1'
  __attribute__((always_inline)) [[deprecated("this function is deprecated")]] int method_1(int);

  // CHECK: Functions.hh:[[@LINE+1]]:61: remark: unexported public interface 'method_2'
  __attribute__((deprecated("this function is deprecated")))int method_2(int);

  // CHECK: Functions.hh:[[@LINE+1]]:57: remark: unexported public interface 'method_3'
  [[nodiscard]] __attribute__((noinline)) /* comment */ int method_3(int);

  // CHECK: Functions.hh:[[@LINE+1]]:75: remark: unexported public interface 'method_4'
  __attribute__((noinline)) [[deprecated("this function is deprecated")]] int method_4(int);

  // CHECK: Functions.hh:[[@LINE+2]]:17: remark: unexported public interface 'method_5'
  [[nodiscard]] __attribute__((deprecated("this function is deprecated")))
  /* comment */ int method_5(int);

  // CHECK: Functions.hh:[[@LINE+2]]:3: remark: unexported public interface 'method_6'
  [[nodiscard]]
  int method_6(int);

  // CHECK: Functions.hh:[[@LINE+3]]:3: remark: unexported public interface 'method_7'
  [[nodiscard]] [[deprecated("this function is deprecated")]] /* two line
                                                                 comment */
  int method_7(int);

  // CHECK: Functions.hh:[[@LINE+2]]:3: remark: unexported public interface 'method_8'
  [[nodiscard]] // this is a comment
  int method_8(int);

  // CHECK: Functions.hh:[[@LINE+2]]:60: remark: unexported public interface 'method_9'
  [[nodiscard]] // this is a comment
  __attribute((deprecated("this function is deprecated"))) int method_9(int);
};
