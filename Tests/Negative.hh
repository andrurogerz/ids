// NOTE: We expect idt to return a non-zero exit code on Windows because the
// compiler will actually produce errors when __declspec(dllexport) appears in
// unsupported locations. So we have to run "not idt" when running on Windows.

// RUN: %if system-windows %{ \
// RUN:   not %idt --export-macro IDT_TEST_ABI %s 2>&1 | FileCheck %s \
// RUN: %} %else %{  \
// RUN:   %idt --export-macro IDT_TEST_ABI %s 2>&1 | FileCheck %s \
// RUN: %}

#if defined(_WIN32)
#define EXPORT_ABI __declspec(dllexport)
#else
#define EXPORT_ABI __attribute__((visibility("default")))
#endif

// CHECK: Negative.hh:[[@LINE+1]]:1: remark: incorrectly exported symbol 'function'
EXPORT_ABI static inline void function() {}

struct Struct {
  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'staticMethod'
  EXPORT_ABI static void staticMethod() {}

  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'method'
  EXPORT_ABI void method() {}

  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'staticConstField'
  EXPORT_ABI static const int staticConstField = 0;

  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'staticConstexprField'
  EXPORT_ABI static constexpr int staticConstexprField = 0;
};

struct EXPORT_ABI ExportedStruct {
  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'staticMethod'
  EXPORT_ABI static void staticMethod();

  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'method'
  EXPORT_ABI void method();

  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'staticConstField'
  EXPORT_ABI static const int staticConstField;

  // CHECK: Negative.hh:[[@LINE+1]]:3: remark: incorrectly exported symbol 'staticField'
  EXPORT_ABI static int staticField;
};
