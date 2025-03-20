// RUN: %idt --export-classes --export-macro=IDT_TEST_ABI --extra-arg="-DIDT_TEST_ABI=__declspec(dllexport)" %s 2>&1 | %FileCheck --check-prefix=CHECK-POSITIVE %s
// RUN: %idt --export-classes --export-macro=IDT_TEST_ABI --extra-arg="-DIDT_TEST_ABI=__declspec(dllexport)" %s 2>&1 | %FileCheck --check-prefix=CHECK-NEGATIVE %s

class IDT_TEST_ABI AlreadyAnnotatedClass {
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface
public:
  AlreadyAnnotatedClass();
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface
};

class NotAnnotatedClass {
// CHECK-POSITIVE-DAG: Classes.hh:[[@LINE-1]]:6: remark: unexported public interface 'NotAnnotatedClass'
public:
  NotAnnotatedClass();
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface
};

class NotAnnotatedOuterClass {
// CHECK-POSITIVE-DAG: Classes.hh:[[@LINE-1]]:6: remark: unexported public interface 'NotAnnotatedOuterClass'
public:
  NotAnnotatedOuterClass();
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface

  class NotAnnotatedInnerClass {
// CHECK-POSITIVE-DAG: Classes.hh:[[@LINE-1]]:8: remark: unexported public interface 'NotAnnotatedInnerClass'
  public:
    NotAnnotatedInnerClass();
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface
  };

  class IDT_TEST_ABI AnnotatedInnerClass {
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface
  public:
    AnnotatedInnerClass();
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface

    class NotAnnotatedInnerInnerClass {
// CHECK-POSITIVE-DAG: Classes.hh:[[@LINE-1]]:10: remark: unexported public interface 'NotAnnotatedInnerInnerClass'
    public:
      NotAnnotatedInnerInnerClass();
// CHECK-NEGATIVE-NOT: Classes.hh:[[@LINE-1]]:{{.*}} remark: unexported public interface
    };
  };
};
