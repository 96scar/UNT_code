; ModuleID = 'hello.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

%"class.std::basic_ostream" = type { i32 (...)**, %"class.std::basic_ios" }
%"class.std::basic_ios" = type { %"class.std::ios_base", %"class.std::basic_ostream"*, i8, i8, %"class.std::basic_streambuf"*, %"class.std::ctype"*, %"class.std::num_put"*, %"class.std::num_get"* }
%"class.std::ios_base" = type { i32 (...)**, i32, i32, i32, i32, i32, %"struct.std::ios_base::_Callback_list"*, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, %"struct.std::ios_base::_Words"*, %"class.std::locale" }
%"struct.std::ios_base::_Callback_list" = type { %"struct.std::ios_base::_Callback_list"*, void (i32, %"class.std::ios_base"*, i32)*, i32, i32 }
%"struct.std::ios_base::_Words" = type { i8*, i32 }
%"class.std::locale" = type { %"class.std::locale::_Impl"* }
%"class.std::locale::_Impl" = type { i32, %"class.std::locale::facet"**, i32, %"class.std::locale::facet"**, i8** }
%"class.std::locale::facet" = type { i32 (...)**, i32 }
%"class.std::basic_streambuf" = type { i32 (...)**, i8*, i8*, i8*, i8*, i8*, i8*, %"class.std::locale" }
%"class.std::ctype" = type { %"class.std::locale::facet", %struct.__locale_struct*, i8, i32*, i32*, i16*, i8, [256 x i8], [256 x i8], i8 }
%struct.__locale_struct = type { [13 x %struct.__locale_data*], i16*, i32*, i32*, [13 x i8*] }
%struct.__locale_data = type opaque
%"class.std::num_put" = type { %"class.std::locale::facet" }
%"class.std::num_get" = type { %"class.std::locale::facet" }

@_ZSt4cout = external global %"class.std::basic_ostream"
@.str = external hidden unnamed_addr constant [13 x i8], align 1

define i32 @main() {
  %1 = tail call %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([13 x i8]* @.str, i32 0, i32 0), i32 12)
  %2 = load i8** bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8**), align 4
  %3 = getelementptr i8* %2, i32 -12
  %4 = bitcast i8* %3 to i32*
  %5 = load i32* %4, align 4
  %.sum = add i32 %5, 124
  %6 = getelementptr inbounds i8* bitcast (%"class.std::basic_ostream"* @_ZSt4cout to i8*), i32 %.sum
  %7 = bitcast i8* %6 to %"class.std::ctype"**
  %8 = load %"class.std::ctype"** %7, align 4, !tbaa !0
  %9 = icmp eq %"class.std::ctype"* %8, null
  br i1 %9, label %10, label %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit

; <label>:10                                      ; preds = %0
  tail call void @_ZSt16__throw_bad_castv() noreturn
  unreachable

_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit:    ; preds = %0
  %11 = getelementptr inbounds %"class.std::ctype"* %8, i32 0, i32 6
  %12 = load i8* %11, align 1, !tbaa !1
  %13 = icmp eq i8 %12, 0
  br i1 %13, label %17, label %14

; <label>:14                                      ; preds = %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
  %15 = getelementptr inbounds %"class.std::ctype"* %8, i32 0, i32 7, i32 10
  %16 = load i8* %15, align 1, !tbaa !1
  br label %_ZNKSt5ctypeIcE5widenEc.exit

; <label>:17                                      ; preds = %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
  tail call void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"* %8)
  %18 = bitcast %"class.std::ctype"* %8 to i8 (%"class.std::ctype"*, i8)***
  %19 = load i8 (%"class.std::ctype"*, i8)*** %18, align 4
  %20 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)** %19, i32 6
  %21 = load i8 (%"class.std::ctype"*, i8)** %20, align 4
  %22 = tail call signext i8 %21(%"class.std::ctype"* %8, i8 signext 10)
  br label %_ZNKSt5ctypeIcE5widenEc.exit

_ZNKSt5ctypeIcE5widenEc.exit:                     ; preds = %17, %14
  %.0.i = phi i8 [ %16, %14 ], [ %22, %17 ]
  %23 = tail call %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"* @_ZSt4cout, i8 signext %.0.i)
  %24 = tail call %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"* %23)
  ret i32 0
}

declare %"class.std::basic_ostream"* @_ZNSo3putEc(%"class.std::basic_ostream"*, i8 signext)

declare void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"*)

declare void @_ZSt16__throw_bad_castv() noreturn

declare %"class.std::basic_ostream"* @_ZNSo5flushEv(%"class.std::basic_ostream"*)

declare %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i(%"class.std::basic_ostream"*, i8*, i32)

!0 = metadata !{metadata !"any pointer", metadata !1}
!1 = metadata !{metadata !"omnipotent char", metadata !2}
!2 = metadata !{metadata !"Simple C/C++ TBAA", null}
