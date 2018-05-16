; ModuleID = 'a.c'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [13 x i8] c"Hello World!\00", align 1

define i32 @main() nounwind {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca i32, align 4
  %x = alloca i8, align 1
  %y = alloca i8, align 1
  %z = alloca i8, align 1
  %d = alloca float, align 4
  %e = alloca float, align 4
  %f = alloca float, align 4
  %g = alloca double, align 8
  %h = alloca double, align 8
  %i = alloca double, align 8
  %arr = alloca i8*, align 4
  %count = alloca i32, align 4
  store i32 0, i32* %1
  store i32 1, i32* %a, align 4
  store i32 2, i32* %b, align 4
  store i32 3, i32* %c, align 4
  store i8 97, i8* %x, align 1
  store i8 98, i8* %y, align 1
  store i8 99, i8* %z, align 1
  store i8* getelementptr inbounds ([13 x i8]* @.str, i32 0, i32 0), i8** %arr, align 4
  store float 0x3FF3AE1480000000, float* %d, align 4
  store float 0x403693F7C0000000, float* %e, align 4
  store float 0x407623C0C0000000, float* %f, align 4
  store double 0x406D4E9E02EA960B, double* %g, align 8
  store double 0x406D522A6357B906, double* %h, align 8
  store double 0x40BACA3C1DC8C799, double* %i, align 8
  store i32 0, i32* %count, align 4
  br label %2

; <label>:2                                       ; preds = %21, %0
  %3 = load i32* %count, align 4
  %4 = icmp slt i32 %3, 10
  br i1 %4, label %5, label %24

; <label>:5                                       ; preds = %2
  %6 = load i32* %a, align 4
  %7 = load i32* %b, align 4
  %8 = add nsw i32 %6, %7
  %9 = load i32* %c, align 4
  %10 = add nsw i32 %8, %9
  store i32 %10, i32* %a, align 4
  %11 = load float* %d, align 4
  %12 = load float* %e, align 4
  %13 = fadd float %11, %12
  %14 = load float* %f, align 4
  %15 = fadd float %13, %14
  store float %15, float* %d, align 4
  %16 = load double* %g, align 8
  %17 = load double* %h, align 8
  %18 = fadd double %16, %17
  %19 = load double* %i, align 8
  %20 = fadd double %18, %19
  store double %20, double* %g, align 8
  br label %21

; <label>:21                                      ; preds = %5
  %22 = load i32* %count, align 4
  %23 = add nsw i32 %22, 1
  store i32 %23, i32* %count, align 4
  br label %2

; <label>:24                                      ; preds = %2
  ret i32 0
}
