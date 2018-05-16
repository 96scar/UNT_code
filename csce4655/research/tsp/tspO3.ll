; ModuleID = 'tsp.ll'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%"class.std::basic_istream" = type { i32 (...)**, i32, %"class.std::basic_ios" }
%"class.std::basic_ios" = type { %"class.std::ios_base", %"class.std::basic_ostream"*, i8, i8, %"class.std::basic_streambuf"*, %"class.std::ctype"*, %"class.std::num_put"*, %"class.std::num_get"* }
%"class.std::ios_base" = type { i32 (...)**, i32, i32, i32, i32, i32, %"struct.std::ios_base::_Callback_list"*, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, %"struct.std::ios_base::_Words"*, %"class.std::locale" }
%"struct.std::ios_base::_Callback_list" = type { %"struct.std::ios_base::_Callback_list"*, void (i32, %"class.std::ios_base"*, i32)*, i32, i32 }
%"struct.std::ios_base::_Words" = type { i8*, i32 }
%"class.std::locale" = type { %"class.std::locale::_Impl"* }
%"class.std::locale::_Impl" = type { i32, %"class.std::locale::facet"**, i32, %"class.std::locale::facet"**, i8** }
%"class.std::locale::facet" = type { i32 (...)**, i32 }
%"class.std::basic_ostream" = type { i32 (...)**, %"class.std::basic_ios" }
%"class.std::basic_streambuf" = type { i32 (...)**, i8*, i8*, i8*, i8*, i8*, i8*, %"class.std::locale" }
%"class.std::ctype" = type { %"class.std::locale::facet", %struct.__locale_struct*, i8, i32*, i32*, i16*, i8, [256 x i8], [256 x i8], i8 }
%struct.__locale_struct = type { [13 x %struct.__locale_data*], i16*, i32*, i32*, [13 x i8*] }
%struct.__locale_data = type opaque
%"class.std::num_put" = type { %"class.std::locale::facet" }
%"class.std::num_get" = type { %"class.std::locale::facet" }
%"class.std::basic_string" = type { %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" }
%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" = type { i8* }

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external global i8*
@_ZSt3cin = external global %"class.std::basic_istream"
@_ZSt4cout = external global %"class.std::basic_ostream"
@.str = private unnamed_addr constant [24 x i8] c"Must be an 'a' or a 'c'\00", align 1
@.str1 = private unnamed_addr constant [10 x i8] c"The tour \00", align 1
@.str2 = private unnamed_addr constant [2 x i8] c" \00", align 1
@.str3 = private unnamed_addr constant [7 x i8] c"costs \00", align 1
@.str4 = private unnamed_addr constant [28 x i8] c" is not in the cities array\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()* }] [{ i32, void ()* } { i32 65535, void ()* @_GLOBAL__I_a }]

declare void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*)

declare void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*)

declare i32 @__cxa_atexit(void (i8*)*, i8*, i8*) nounwind

define i32 @main() {
.preheader39:
  %str = alloca %"class.std::basic_string", align 4
  %cities = alloca [15 x i32], align 4
  %cities43 = bitcast [15 x i32]* %cities to i8*
  %copy = alloca [15 x i32], align 4
  %copy42 = bitcast [15 x i32]* %copy to i8*
  %lowestCost = alloca [1 x i32], align 4
  %bestTour = alloca [15 x i32], align 4
  %cost = alloca [15 x [15 x i32]], align 4
  %arg1 = alloca %"class.std::basic_string", align 4
  %str2 = alloca %"class.std::basic_string", align 4
  %arg2 = alloca %"class.std::basic_string", align 4
  %str3 = alloca %"class.std::basic_string", align 4
  %arg3 = alloca %"class.std::basic_string", align 4
  %arg4 = alloca %"class.std::basic_string", align 4
  %arg21 = alloca %"class.std::basic_string", align 4
  call void @_ZNSsC1Ev(%"class.std::basic_string"* %str)
  call void @llvm.memset.p0i8.i32(i8* %cities43, i8 -1, i32 60, i32 4, i1 false)
  call void @llvm.memset.p0i8.i32(i8* %copy42, i8 -1, i32 60, i32 4, i1 false)
  %cost59 = bitcast [15 x [15 x i32]]* %cost to i8*
  call void @llvm.memset.p0i8.i32(i8* %cost59, i8 -1, i32 900, i32 4, i1 false)
  br label %0

; <label>:0                                       ; preds = %.preheader39, %136
  %length.0 = phi i32 [ %length.1, %136 ], [ 0, %.preheader39 ]
  %1 = invoke %"class.std::basic_istream"* @_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E(%"class.std::basic_istream"* @_ZSt3cin, %"class.std::basic_string"* %str)
          to label %2 unwind label %.nonloopexit.loopexit

; <label>:2                                       ; preds = %0
  %3 = bitcast %"class.std::basic_istream"* %1 to i8**
  %4 = load i8** %3, align 4
  %5 = getelementptr i8* %4, i32 -12
  %6 = bitcast i8* %5 to i32*
  %7 = load i32* %6, align 4
  %8 = bitcast %"class.std::basic_istream"* %1 to i8*
  %9 = getelementptr i8* %8, i32 %7
  %10 = bitcast i8* %9 to %"class.std::basic_ios"*
  %11 = invoke i8* @_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv(%"class.std::basic_ios"* %10)
          to label %12 unwind label %.nonloopexit.loopexit

; <label>:12                                      ; preds = %2
  %13 = icmp eq i8* %11, null
  br i1 %13, label %.preheader17, label %20

.preheader17:                                     ; preds = %12
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %copy42, i8* %cities43, i32 60, i32 4, i1 false)
  %14 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 0
  %15 = add nsw i32 %length.0, -1
  %16 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 0
  %17 = getelementptr inbounds [15 x i32]* %copy, i32 0, i32 0
  %18 = getelementptr inbounds [1 x i32]* %lowestCost, i32 0, i32 0
  %19 = getelementptr inbounds [15 x i32]* %bestTour, i32 0, i32 0
  invoke void @_Z7permutePiiiPA15_iS_S_S_(i32* %14, i32 0, i32 %15, [15 x i32]* %16, i32* %17, i32* %18, i32* %19)
          to label %139 unwind label %.nonloopexit.nonloopexit

; <label>:20                                      ; preds = %12
  %21 = invoke i32 @_ZNKSs4findEcj(%"class.std::basic_string"* %str, i8 signext 32, i32 0)
          to label %22 unwind label %.nonloopexit.loopexit

; <label>:22                                      ; preds = %20
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg1, %"class.std::basic_string"* %str, i32 0, i32 %21)
          to label %23 unwind label %.nonloopexit.loopexit

; <label>:23                                      ; preds = %22
  %24 = add nsw i32 %21, 1
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %str2, %"class.std::basic_string"* %str, i32 %24, i32 -1)
          to label %25 unwind label %90

; <label>:25                                      ; preds = %23
  %26 = invoke i8* @_ZNSs2atEj(%"class.std::basic_string"* %arg1, i32 0)
          to label %27 unwind label %94

; <label>:27                                      ; preds = %25
  %28 = load i8* %26, align 1
  switch i8 %28, label %131 [
    i8 97, label %29
    i8 99, label %120
  ]

; <label>:29                                      ; preds = %27
  %30 = invoke i32 @_ZNKSs4findEcj(%"class.std::basic_string"* %str2, i8 signext 32, i32 0)
          to label %31 unwind label %94

; <label>:31                                      ; preds = %29
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg2, %"class.std::basic_string"* %str2, i32 0, i32 %30)
          to label %32 unwind label %94

; <label>:32                                      ; preds = %31
  %33 = add nsw i32 %30, 1
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %str3, %"class.std::basic_string"* %str2, i32 %33, i32 -1)
          to label %34 unwind label %98

; <label>:34                                      ; preds = %32
  %35 = invoke i32 @_ZNKSs4findEcj(%"class.std::basic_string"* %str3, i8 signext 32, i32 0)
          to label %36 unwind label %102

; <label>:36                                      ; preds = %34
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg3, %"class.std::basic_string"* %str3, i32 0, i32 %35)
          to label %37 unwind label %102

; <label>:37                                      ; preds = %36
  %38 = add nsw i32 %35, 1
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg4, %"class.std::basic_string"* %str3, i32 %38, i32 -1)
          to label %39 unwind label %106

; <label>:39                                      ; preds = %37
  %40 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg2)
          to label %41 unwind label %110

; <label>:41                                      ; preds = %39
  %42 = call i32 @atoi(i8* %40) nounwind readonly
  %43 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg3)
          to label %44 unwind label %110

; <label>:44                                      ; preds = %41
  %45 = call i32 @atoi(i8* %43) nounwind readonly
  br label %46

; <label>:46                                      ; preds = %52, %44
  %i.0.i = phi i32 [ 0, %44 ], [ %53, %52 ]
  %47 = icmp slt i32 %i.0.i, %length.0
  br i1 %47, label %48, label %54

; <label>:48                                      ; preds = %46
  %49 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 %i.0.i
  %50 = load i32* %49, align 4
  %51 = icmp eq i32 %50, %42
  br i1 %51, label %_Z11getPositioniPii.exit, label %52

; <label>:52                                      ; preds = %48
  %53 = add nsw i32 %i.0.i, 1
  br label %46

; <label>:54                                      ; preds = %46
  %55 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %.noexc unwind label %110

.noexc:                                           ; preds = %54
  %56 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %55, i32 %42)
          to label %.noexc7 unwind label %110

.noexc7:                                          ; preds = %.noexc
  %57 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %56, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
          to label %.noexc8 unwind label %110

.noexc8:                                          ; preds = %.noexc7
  %58 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %57, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %.noexc9 unwind label %110

.noexc9:                                          ; preds = %.noexc8
  %59 = add nsw i32 %42, -1
  br label %_Z11getPositioniPii.exit

_Z11getPositioniPii.exit:                         ; preds = %48, %.noexc9
  %.0.i = phi i32 [ %59, %.noexc9 ], [ %i.0.i, %48 ]
  br label %60

; <label>:60                                      ; preds = %66, %_Z11getPositioniPii.exit
  %i.0.i10 = phi i32 [ 0, %_Z11getPositioniPii.exit ], [ %67, %66 ]
  %61 = icmp slt i32 %i.0.i10, %length.0
  br i1 %61, label %62, label %68

; <label>:62                                      ; preds = %60
  %63 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 %i.0.i10
  %64 = load i32* %63, align 4
  %65 = icmp eq i32 %64, %45
  br i1 %65, label %_Z11getPositioniPii.exit16, label %66

; <label>:66                                      ; preds = %62
  %67 = add nsw i32 %i.0.i10, 1
  br label %60

; <label>:68                                      ; preds = %60
  %69 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %.noexc12 unwind label %110

.noexc12:                                         ; preds = %68
  %70 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %69, i32 %45)
          to label %.noexc13 unwind label %110

.noexc13:                                         ; preds = %.noexc12
  %71 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %70, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
          to label %.noexc14 unwind label %110

.noexc14:                                         ; preds = %.noexc13
  %72 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %71, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %.noexc15 unwind label %110

.noexc15:                                         ; preds = %.noexc14
  %73 = add nsw i32 %45, -1
  br label %_Z11getPositioniPii.exit16

_Z11getPositioniPii.exit16:                       ; preds = %62, %.noexc15
  %.0.i11 = phi i32 [ %73, %.noexc15 ], [ %i.0.i10, %62 ]
  %74 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg4)
          to label %75 unwind label %110

; <label>:75                                      ; preds = %_Z11getPositioniPii.exit16
  %76 = call i32 @atoi(i8* %74) nounwind readonly
  %77 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %.0.i, i32 %.0.i11
  store i32 %76, i32* %77, align 4
  %78 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %.0.i11, i32 %.0.i
  store i32 %76, i32* %78, align 4
  %79 = icmp sgt i32 %length.0, 0
  br i1 %79, label %.lr.ph.us, label %._crit_edge24

; <label>:80                                      ; preds = %82
  %81 = add nsw i32 %i.223.us, 1
  %exitcond44 = icmp eq i32 %81, %length.0
  br i1 %exitcond44, label %._crit_edge24, label %.lr.ph.us

; <label>:82                                      ; preds = %86, %84
  %83 = add nsw i32 %j.122.us, 1
  %exitcond = icmp eq i32 %83, %length.0
  br i1 %exitcond, label %80, label %86

; <label>:84                                      ; preds = %86
  %85 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %i.223.us, i32 %j.122.us
  store i32 0, i32* %85, align 4
  br label %82

; <label>:86                                      ; preds = %82, %.lr.ph.us
  %j.122.us = phi i32 [ 0, %.lr.ph.us ], [ %83, %82 ]
  %87 = icmp eq i32 %i.223.us, %j.122.us
  br i1 %87, label %84, label %82

.lr.ph.us:                                        ; preds = %80, %75
  %i.223.us = phi i32 [ %81, %80 ], [ 0, %75 ]
  br label %86

.loopexit:                                        ; preds = %142, %146
  %lpad.loopexit = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  br label %.nonloopexit

.nonloopexit.loopexit:                            ; preds = %136, %22, %20, %2, %0
  %lpad.loopexit26 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  br label %.nonloopexit

.nonloopexit.nonloopexit:                         ; preds = %160, %157, %155, %153, %150, %139, %.preheader17
  %lpad.nonloopexit27 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  br label %.nonloopexit

.nonloopexit:                                     ; preds = %.nonloopexit.loopexit, %.nonloopexit.nonloopexit, %.loopexit
  %lpad.phi = phi { i8*, i32 } [ %lpad.loopexit, %.loopexit ], [ %lpad.loopexit26, %.nonloopexit.loopexit ], [ %lpad.nonloopexit27, %.nonloopexit.nonloopexit ]
  %88 = extractvalue { i8*, i32 } %lpad.phi, 0
  %89 = extractvalue { i8*, i32 } %lpad.phi, 1
  br label %163

; <label>:90                                      ; preds = %135, %23
  %91 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %92 = extractvalue { i8*, i32 } %91, 0
  %93 = extractvalue { i8*, i32 } %91, 1
  br label %138

; <label>:94                                      ; preds = %133, %131, %123, %120, %116, %31, %29, %25
  %95 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %96 = extractvalue { i8*, i32 } %95, 0
  %97 = extractvalue { i8*, i32 } %95, 1
  br label %137

; <label>:98                                      ; preds = %115, %32
  %99 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %100 = extractvalue { i8*, i32 } %99, 0
  %101 = extractvalue { i8*, i32 } %99, 1
  br label %119

; <label>:102                                     ; preds = %114, %36, %34
  %103 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %104 = extractvalue { i8*, i32 } %103, 0
  %105 = extractvalue { i8*, i32 } %103, 1
  br label %118

; <label>:106                                     ; preds = %._crit_edge24, %37
  %107 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %108 = extractvalue { i8*, i32 } %107, 0
  %109 = extractvalue { i8*, i32 } %107, 1
  br label %117

; <label>:110                                     ; preds = %.noexc14, %.noexc13, %.noexc12, %68, %.noexc8, %.noexc7, %.noexc, %54, %_Z11getPositioniPii.exit16, %41, %39
  %111 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %112 = extractvalue { i8*, i32 } %111, 0
  %113 = extractvalue { i8*, i32 } %111, 1
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg4)
          to label %117 unwind label %167

._crit_edge24:                                    ; preds = %80, %75
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg4)
          to label %114 unwind label %106

; <label>:114                                     ; preds = %._crit_edge24
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg3)
          to label %115 unwind label %102

; <label>:115                                     ; preds = %114
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str3)
          to label %116 unwind label %98

; <label>:116                                     ; preds = %115
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg2)
          to label %135 unwind label %94

; <label>:117                                     ; preds = %110, %106
  %.01 = phi i8* [ %108, %106 ], [ %112, %110 ]
  %.0 = phi i32 [ %109, %106 ], [ %113, %110 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg3)
          to label %118 unwind label %167

; <label>:118                                     ; preds = %117, %102
  %.12 = phi i8* [ %104, %102 ], [ %.01, %117 ]
  %.1 = phi i32 [ %105, %102 ], [ %.0, %117 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str3)
          to label %119 unwind label %167

; <label>:119                                     ; preds = %118, %98
  %.23 = phi i8* [ %100, %98 ], [ %.12, %118 ]
  %.2 = phi i32 [ %101, %98 ], [ %.1, %118 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg2)
          to label %137 unwind label %167

; <label>:120                                     ; preds = %27
  invoke void @_ZNSsC1ERKSs(%"class.std::basic_string"* %arg21, %"class.std::basic_string"* %str2)
          to label %121 unwind label %94

; <label>:121                                     ; preds = %120
  %122 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg21)
          to label %123 unwind label %127

; <label>:123                                     ; preds = %121
  %124 = call i32 @atoi(i8* %122) nounwind readonly
  %125 = add nsw i32 %length.0, 1
  %126 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 %length.0
  store i32 %124, i32* %126, align 4
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg21)
          to label %135 unwind label %94

; <label>:127                                     ; preds = %121
  %128 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %129 = extractvalue { i8*, i32 } %128, 0
  %130 = extractvalue { i8*, i32 } %128, 1
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg21)
          to label %137 unwind label %167

; <label>:131                                     ; preds = %27
  %132 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([24 x i8]* @.str, i32 0, i32 0))
          to label %133 unwind label %94

; <label>:133                                     ; preds = %131
  %134 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %132, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %135 unwind label %94

; <label>:135                                     ; preds = %123, %133, %116
  %length.1 = phi i32 [ %length.0, %116 ], [ %125, %123 ], [ %length.0, %133 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str2)
          to label %136 unwind label %90

; <label>:136                                     ; preds = %135
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg1)
          to label %0 unwind label %.nonloopexit.loopexit

; <label>:137                                     ; preds = %127, %119, %94
  %.34 = phi i8* [ %96, %94 ], [ %.23, %119 ], [ %129, %127 ]
  %.3 = phi i32 [ %97, %94 ], [ %.2, %119 ], [ %130, %127 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str2)
          to label %138 unwind label %167

; <label>:138                                     ; preds = %137, %90
  %.45 = phi i8* [ %92, %90 ], [ %.34, %137 ]
  %.4 = phi i32 [ %93, %90 ], [ %.3, %137 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg1)
          to label %163 unwind label %167

; <label>:139                                     ; preds = %.preheader17
  %140 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([10 x i8]* @.str1, i32 0, i32 0))
          to label %.preheader unwind label %.nonloopexit.nonloopexit

.preheader:                                       ; preds = %139, %148
  %i.4 = phi i32 [ %149, %148 ], [ 0, %139 ]
  %141 = icmp slt i32 %i.4, %length.0
  br i1 %141, label %142, label %150

; <label>:142                                     ; preds = %.preheader
  %143 = getelementptr inbounds [15 x i32]* %bestTour, i32 0, i32 %i.4
  %144 = load i32* %143, align 4
  %145 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* @_ZSt4cout, i32 %144)
          to label %146 unwind label %.loopexit

; <label>:146                                     ; preds = %142
  %147 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %145, i8* getelementptr inbounds ([2 x i8]* @.str2, i32 0, i32 0))
          to label %148 unwind label %.loopexit

; <label>:148                                     ; preds = %146
  %149 = add nsw i32 %i.4, 1
  br label %.preheader

; <label>:150                                     ; preds = %.preheader
  %151 = load i32* %19, align 4
  %152 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* @_ZSt4cout, i32 %151)
          to label %153 unwind label %.nonloopexit.nonloopexit

; <label>:153                                     ; preds = %150
  %154 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %152, i8* getelementptr inbounds ([2 x i8]* @.str2, i32 0, i32 0))
          to label %155 unwind label %.nonloopexit.nonloopexit

; <label>:155                                     ; preds = %153
  %156 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([7 x i8]* @.str3, i32 0, i32 0))
          to label %157 unwind label %.nonloopexit.nonloopexit

; <label>:157                                     ; preds = %155
  %158 = load i32* %18, align 4
  %159 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %156, i32 %158)
          to label %160 unwind label %.nonloopexit.nonloopexit

; <label>:160                                     ; preds = %157
  %161 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %159, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %162 unwind label %.nonloopexit.nonloopexit

; <label>:162                                     ; preds = %160
  call void @_ZNSsD1Ev(%"class.std::basic_string"* %str)
  ret i32 0

; <label>:163                                     ; preds = %138, %.nonloopexit
  %.56 = phi i8* [ %88, %.nonloopexit ], [ %.45, %138 ]
  %.5 = phi i32 [ %89, %.nonloopexit ], [ %.4, %138 ]
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str)
          to label %164 unwind label %167

; <label>:164                                     ; preds = %163
  %165 = insertvalue { i8*, i32 } undef, i8* %.56, 0
  %166 = insertvalue { i8*, i32 } %165, i32 %.5, 1
  resume { i8*, i32 } %166

; <label>:167                                     ; preds = %163, %138, %137, %127, %119, %118, %117, %110
  %168 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  call void @_ZSt9terminatev() noreturn nounwind
  unreachable
}

declare void @_ZNSsC1Ev(%"class.std::basic_string"*)

declare %"class.std::basic_istream"* @_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E(%"class.std::basic_istream"*, %"class.std::basic_string"*)

declare i32 @__gxx_personality_v0(...)

declare i8* @_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv(%"class.std::basic_ios"*)

declare i32 @_ZNKSs4findEcj(%"class.std::basic_string"*, i8 signext, i32)

declare void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret, %"class.std::basic_string"*, i32, i32)

declare i8* @_ZNSs2atEj(%"class.std::basic_string"*, i32)

declare i32 @atoi(i8* nocapture) nounwind readonly

declare i8* @_ZNKSs5c_strEv(%"class.std::basic_string"*)

define i32 @_Z11getPositioniPii(i32 %input, i32* nocapture %array, i32 %length) {
  br label %1

; <label>:1                                       ; preds = %7, %0
  %i.0 = phi i32 [ 0, %0 ], [ %8, %7 ]
  %2 = icmp slt i32 %i.0, %length
  br i1 %2, label %3, label %9

; <label>:3                                       ; preds = %1
  %4 = getelementptr inbounds i32* %array, i32 %i.0
  %5 = load i32* %4, align 4
  %6 = icmp eq i32 %5, %input
  br i1 %6, label %.loopexit, label %7

; <label>:7                                       ; preds = %3
  %8 = add nsw i32 %i.0, 1
  br label %1

; <label>:9                                       ; preds = %1
  %10 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %11 = tail call %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %10, i32 %input)
  %12 = tail call %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %11, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
  %13 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %12, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %14 = add nsw i32 %input, -1
  br label %.loopexit

.loopexit:                                        ; preds = %3, %9
  %.0 = phi i32 [ %14, %9 ], [ %i.0, %3 ]
  ret i32 %.0
}

declare void @_ZNSsD1Ev(%"class.std::basic_string"*)

declare void @_ZSt9terminatev()

declare void @_ZNSsC1ERKSs(%"class.std::basic_string"*, %"class.std::basic_string"*)

declare %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"*, i8*)

declare %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"*, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)*)

declare %"class.std::basic_ostream"* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%"class.std::basic_ostream"*)

define void @_Z7permutePiiiPA15_iS_S_S_(i32* %array, i32 %start, i32 %end, [15 x i32]* %costs, i32* %copy, i32* %finalCost, i32* %finalTour) {
  %1 = icmp eq i32 %start, %end
  br i1 %1, label %5, label %.preheader

.preheader:                                       ; preds = %0
  %2 = icmp sgt i32 %start, %end
  br i1 %2, label %.loopexit, label %.lr.ph

.lr.ph:                                           ; preds = %.preheader
  %3 = getelementptr inbounds i32* %array, i32 %start
  %4 = add nsw i32 %start, 1
  br label %24

; <label>:5                                       ; preds = %0
  %6 = add nsw i32 %end, 1
  %7 = tail call i32 @_Z7getCostPiPA15_iiS_(i32* %array, [15 x i32]* %costs, i32 %6, i32* %copy)
  %8 = load i32* %finalCost, align 4
  %9 = icmp eq i32 %8, 0
  br i1 %9, label %10, label %16

; <label>:10                                      ; preds = %5
  store i32 %7, i32* %finalCost, align 4
  %11 = icmp sgt i32 %6, 0
  br i1 %11, label %.lr.ph7, label %.loopexit

.lr.ph7:                                          ; preds = %10, %.lr.ph7
  %i.06 = phi i32 [ %15, %.lr.ph7 ], [ 0, %10 ]
  %12 = getelementptr inbounds i32* %array, i32 %i.06
  %13 = load i32* %12, align 4
  %14 = getelementptr inbounds i32* %finalTour, i32 %i.06
  store i32 %13, i32* %14, align 4
  %15 = add nsw i32 %i.06, 1
  %exitcond9 = icmp eq i32 %15, %6
  br i1 %exitcond9, label %.loopexit, label %.lr.ph7

; <label>:16                                      ; preds = %5
  %17 = icmp slt i32 %7, %8
  br i1 %17, label %18, label %.loopexit

; <label>:18                                      ; preds = %16
  store i32 %7, i32* %finalCost, align 4
  %19 = icmp sgt i32 %6, 0
  br i1 %19, label %.lr.ph4, label %.loopexit

.lr.ph4:                                          ; preds = %18, %.lr.ph4
  %i.13 = phi i32 [ %23, %.lr.ph4 ], [ 0, %18 ]
  %20 = getelementptr inbounds i32* %array, i32 %i.13
  %21 = load i32* %20, align 4
  %22 = getelementptr inbounds i32* %finalTour, i32 %i.13
  store i32 %21, i32* %22, align 4
  %23 = add nsw i32 %i.13, 1
  %exitcond = icmp eq i32 %23, %6
  br i1 %exitcond, label %.loopexit, label %.lr.ph4

; <label>:24                                      ; preds = %.lr.ph, %24
  %i.21 = phi i32 [ %start, %.lr.ph ], [ %30, %24 ]
  %25 = getelementptr inbounds i32* %array, i32 %i.21
  %26 = load i32* %3, align 4
  %27 = load i32* %25, align 4
  store i32 %27, i32* %3, align 4
  store i32 %26, i32* %25, align 4
  tail call void @_Z7permutePiiiPA15_iS_S_S_(i32* %array, i32 %4, i32 %end, [15 x i32]* %costs, i32* %copy, i32* %finalCost, i32* %finalTour)
  %28 = load i32* %3, align 4
  %29 = load i32* %25, align 4
  store i32 %29, i32* %3, align 4
  store i32 %28, i32* %25, align 4
  %30 = add nsw i32 %i.21, 1
  %31 = icmp sgt i32 %30, %end
  br i1 %31, label %.loopexit, label %24

.loopexit:                                        ; preds = %10, %.lr.ph7, %18, %.lr.ph4, %.preheader, %24, %16
  ret void
}

declare %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"*, i32)

define i32 @_Z7getCostPiPA15_iiS_(i32* nocapture %tour, [15 x i32]* nocapture %costs, i32 %length, i32* nocapture %cities) {
  %1 = add nsw i32 %length, -1
  %2 = icmp sgt i32 %1, 0
  br i1 %2, label %.lr.ph, label %._crit_edge

.lr.ph:                                           ; preds = %0, %_Z11getPositioniPii.exit3
  %i.015 = phi i32 [ %3, %_Z11getPositioniPii.exit3 ], [ 0, %0 ]
  %cost.014 = phi i32 [ %38, %_Z11getPositioniPii.exit3 ], [ 0, %0 ]
  %3 = add nsw i32 %i.015, 1
  %4 = getelementptr inbounds i32* %tour, i32 %3
  %5 = load i32* %4, align 4
  br label %6

; <label>:6                                       ; preds = %12, %.lr.ph
  %i.0.i = phi i32 [ 0, %.lr.ph ], [ %13, %12 ]
  %7 = icmp slt i32 %i.0.i, %length
  br i1 %7, label %8, label %14

; <label>:8                                       ; preds = %6
  %9 = getelementptr inbounds i32* %cities, i32 %i.0.i
  %10 = load i32* %9, align 4
  %11 = icmp eq i32 %10, %5
  br i1 %11, label %_Z11getPositioniPii.exit, label %12

; <label>:12                                      ; preds = %8
  %13 = add nsw i32 %i.0.i, 1
  br label %6

; <label>:14                                      ; preds = %6
  %15 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %16 = tail call %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %15, i32 %5)
  %17 = tail call %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %16, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
  %18 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %17, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %19 = add nsw i32 %5, -1
  br label %_Z11getPositioniPii.exit

_Z11getPositioniPii.exit:                         ; preds = %8, %14
  %.0.i = phi i32 [ %19, %14 ], [ %i.0.i, %8 ]
  %20 = getelementptr inbounds i32* %tour, i32 %i.015
  %21 = load i32* %20, align 4
  br label %22

; <label>:22                                      ; preds = %28, %_Z11getPositioniPii.exit
  %i.0.i1 = phi i32 [ 0, %_Z11getPositioniPii.exit ], [ %29, %28 ]
  %23 = icmp slt i32 %i.0.i1, %length
  br i1 %23, label %24, label %30

; <label>:24                                      ; preds = %22
  %25 = getelementptr inbounds i32* %cities, i32 %i.0.i1
  %26 = load i32* %25, align 4
  %27 = icmp eq i32 %26, %21
  br i1 %27, label %_Z11getPositioniPii.exit3, label %28

; <label>:28                                      ; preds = %24
  %29 = add nsw i32 %i.0.i1, 1
  br label %22

; <label>:30                                      ; preds = %22
  %31 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %32 = tail call %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %31, i32 %21)
  %33 = tail call %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %32, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
  %34 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %33, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %35 = add nsw i32 %21, -1
  br label %_Z11getPositioniPii.exit3

_Z11getPositioniPii.exit3:                        ; preds = %24, %30
  %.0.i2 = phi i32 [ %35, %30 ], [ %i.0.i1, %24 ]
  %36 = getelementptr inbounds [15 x i32]* %costs, i32 %.0.i2, i32 %.0.i
  %37 = load i32* %36, align 4
  %38 = add nsw i32 %37, %cost.014
  %exitcond = icmp eq i32 %3, %1
  br i1 %exitcond, label %._crit_edge, label %.lr.ph

._crit_edge:                                      ; preds = %_Z11getPositioniPii.exit3, %0
  %cost.0.lcssa = phi i32 [ 0, %0 ], [ %38, %_Z11getPositioniPii.exit3 ]
  %39 = load i32* %tour, align 4
  br label %40

; <label>:40                                      ; preds = %46, %._crit_edge
  %i.0.i4 = phi i32 [ 0, %._crit_edge ], [ %47, %46 ]
  %41 = icmp slt i32 %i.0.i4, %length
  br i1 %41, label %42, label %48

; <label>:42                                      ; preds = %40
  %43 = getelementptr inbounds i32* %cities, i32 %i.0.i4
  %44 = load i32* %43, align 4
  %45 = icmp eq i32 %44, %39
  br i1 %45, label %_Z11getPositioniPii.exit6, label %46

; <label>:46                                      ; preds = %42
  %47 = add nsw i32 %i.0.i4, 1
  br label %40

; <label>:48                                      ; preds = %40
  %49 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %50 = tail call %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %49, i32 %39)
  %51 = tail call %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %50, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
  %52 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %51, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %53 = add nsw i32 %39, -1
  br label %_Z11getPositioniPii.exit6

_Z11getPositioniPii.exit6:                        ; preds = %42, %48
  %.0.i5 = phi i32 [ %53, %48 ], [ %i.0.i4, %42 ]
  %54 = getelementptr inbounds i32* %tour, i32 %1
  %55 = load i32* %54, align 4
  br label %56

; <label>:56                                      ; preds = %62, %_Z11getPositioniPii.exit6
  %i.0.i7 = phi i32 [ 0, %_Z11getPositioniPii.exit6 ], [ %63, %62 ]
  %57 = icmp slt i32 %i.0.i7, %length
  br i1 %57, label %58, label %64

; <label>:58                                      ; preds = %56
  %59 = getelementptr inbounds i32* %cities, i32 %i.0.i7
  %60 = load i32* %59, align 4
  %61 = icmp eq i32 %60, %55
  br i1 %61, label %_Z11getPositioniPii.exit9, label %62

; <label>:62                                      ; preds = %58
  %63 = add nsw i32 %i.0.i7, 1
  br label %56

; <label>:64                                      ; preds = %56
  %65 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %66 = tail call %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %65, i32 %55)
  %67 = tail call %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %66, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
  %68 = tail call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %67, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %69 = add nsw i32 %55, -1
  br label %_Z11getPositioniPii.exit9

_Z11getPositioniPii.exit9:                        ; preds = %58, %64
  %.0.i8 = phi i32 [ %69, %64 ], [ %i.0.i7, %58 ]
  %70 = getelementptr inbounds [15 x i32]* %costs, i32 %.0.i8, i32 %.0.i5
  %71 = load i32* %70, align 4
  %72 = add nsw i32 %71, %cost.0.lcssa
  ret i32 %72
}

define void @_Z4swapPiS_(i32* nocapture %a, i32* nocapture %b) nounwind {
  %1 = load i32* %a, align 4
  %2 = load i32* %b, align 4
  store i32 %2, i32* %a, align 4
  store i32 %1, i32* %b, align 4
  ret void
}

define internal void @_GLOBAL__I_a() {
  tail call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = tail call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init"* @_ZStL8__ioinit, i32 0, i32 0), i8* bitcast (i8** @__dso_handle to i8*))
  ret void
}

declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture, i32, i32, i1) nounwind

declare void @llvm.memset.p0i8.i32(i8* nocapture, i8, i32, i32, i1) nounwind
