; ModuleID = 'example.c'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

define i32 @main() nounwind {
  %1 = alloca i32, align 4
  %x = alloca [10 x double], align 4
  %i = alloca i32, align 4
  store i32 0, i32* %1
  store i32 1, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %20, %0
  %3 = load i32* %i, align 4
  %4 = icmp slt i32 %3, 10
  br i1 %4, label %5, label %23

; <label>:5                                       ; preds = %2
  %6 = load i32* %i, align 4
  %7 = getelementptr inbounds [10 x double]* %x, i32 0, i32 %6
  %8 = load double* %7, align 4
  %9 = load i32* %i, align 4
  %10 = sub nsw i32 %9, 1
  %11 = getelementptr inbounds [10 x double]* %x, i32 0, i32 %10
  %12 = load double* %11, align 4
  %13 = fmul double %8, %12
  %14 = load i32* %i, align 4
  %15 = getelementptr inbounds [10 x double]* %x, i32 0, i32 %14
  %16 = load double* %15, align 4
  %17 = fadd double %13, %16
  %18 = load i32* %i, align 4
  %19 = getelementptr inbounds [10 x double]* %x, i32 0, i32 %18
  store double %17, double* %19, align 4
  br label %20

; <label>:20                                      ; preds = %5
  %21 = load i32* %i, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, i32* %i, align 4
  br label %2

; <label>:23                                      ; preds = %2
  ret i32 0
}
