; ModuleID = 'a.ll'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [13 x i8] c"Hello World!\00", align 1
@.str1 = private unnamed_addr constant [43 x i8] c"%d\09%d\09%d\0A%c\09%c\09%c\0A%f\09%f\09%f\0A%lf\09%lf\09%lf\0A%s\0A\00", align 1
@.str2 = private unnamed_addr constant [14 x i8] c"Addition: %d\0A\00", align 1
@.str3 = private unnamed_addr constant [17 x i8] c"Subtraction: %f\0A\00", align 1
@.str4 = private unnamed_addr constant [21 x i8] c"Multiplication: %lf\0A\00", align 1
@.str5 = private unnamed_addr constant [14 x i8] c"Division: %d\0A\00", align 1

define i32 @main() nounwind {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([43 x i8]* @.str1, i32 0, i32 0), i32 1, i32 2, i32 3, i32 97, i32 98, i32 99, double 0x3FF3AE1480000000, double 0x403693F7C0000000, double 0x407623C0C0000000, double 0x406D4E9E02EA960B, double 0x406D522A6357B906, double 0x40BACA3C1DC8C799, i8* getelementptr inbounds ([13 x i8]* @.str, i32 0, i32 0)) nounwind
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str2, i32 0, i32 0), i32 6) nounwind
  %3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str3, i32 0, i32 0), double 0x4074A6D320000000) nounwind
  %4 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str4, i32 0, i32 0), double 0x41B67B3D4A428C33) nounwind
  %5 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str5, i32 0, i32 0), i32 3) nounwind
  ret i32 0
}

declare i32 @printf(i8* nocapture, ...) nounwind
