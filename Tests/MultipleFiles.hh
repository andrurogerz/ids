// RUN: %idt -export-macro IDT_TEST_ABI %S/Variables.hh %S/TemplateFunctions.hh 2>&1 | %FileCheck %s

// CHECK: Variables.hh:8:3: remark: unexported public interface 'public_static_class_field'
// CHECK: Variables.hh:11:3: remark: unexported public interface 'public_static_const_class_field'
// CHECK: Variables.hh:29:3: remark: unexported public interface 'public_static_struct_field'
// CHECK: Variables.hh:32:3: remark: unexported public interface 'public_static_const_struct_field'
// CHECK: Variables.hh:46:8: remark: unexported public interface 'extern_variable'
// CHECK: Variables.hh:49:8: remark: unexported public interface 'extern_const_variable'
// CHECK: Variables.hh:52:50: remark: unexported public interface 'extern_annotated_variable'
// CHECK: Variables.hh:55:50: remark: unexported public interface 'extern_annotated_const_variable'
// CHECK: TemplateFunctions.hh:10:13: remark: unexported public interface 'template_function_inline<char>'
