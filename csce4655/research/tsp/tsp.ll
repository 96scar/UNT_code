; ModuleID = 'tsp.cpp'
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

define internal void @__cxx_global_var_init() {
  call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init"* @_ZStL8__ioinit, i32 0, i32 0), i8* bitcast (i8** @__dso_handle to i8*))
  ret void
}

declare void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*)

declare void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*)

declare i32 @__cxa_atexit(void (i8*)*, i8*, i8*) nounwind

define i32 @main() {
  %1 = alloca i32, align 4
  %str = alloca %"class.std::basic_string", align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %val = alloca i32, align 4
  %start = alloca i32, align 4
  %end = alloca i32, align 4
  %startPos = alloca i32, align 4
  %endPos = alloca i32, align 4
  %cities = alloca [15 x i32], align 4
  %copy = alloca [15 x i32], align 4
  %lowestCost = alloca [1 x i32], align 4
  %bestTour = alloca [15 x i32], align 4
  %length = alloca i32, align 4
  %cost = alloca [15 x [15 x i32]], align 4
  %type = alloca i8, align 1
  %2 = alloca i8*
  %3 = alloca i32
  %spacePos1 = alloca i32, align 4
  %arg1 = alloca %"class.std::basic_string", align 4
  %str2 = alloca %"class.std::basic_string", align 4
  %spacePos2 = alloca i32, align 4
  %arg2 = alloca %"class.std::basic_string", align 4
  %str3 = alloca %"class.std::basic_string", align 4
  %spacePos3 = alloca i32, align 4
  %arg3 = alloca %"class.std::basic_string", align 4
  %arg4 = alloca %"class.std::basic_string", align 4
  %arg21 = alloca %"class.std::basic_string", align 4
  %4 = alloca i32
  store i32 0, i32* %1
  call void @_ZNSsC1Ev(%"class.std::basic_string"* %str)
  store i32 0, i32* %length, align 4
  store i32 0, i32* %i, align 4
  br label %5

; <label>:5                                       ; preds = %13, %0
  %6 = load i32* %i, align 4
  %7 = icmp slt i32 %6, 15
  br i1 %7, label %8, label %16

; <label>:8                                       ; preds = %5
  %9 = load i32* %i, align 4
  %10 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 %9
  store i32 -1, i32* %10, align 4
  %11 = load i32* %i, align 4
  %12 = getelementptr inbounds [15 x i32]* %copy, i32 0, i32 %11
  store i32 -1, i32* %12, align 4
  br label %13

; <label>:13                                      ; preds = %8
  %14 = load i32* %i, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %i, align 4
  br label %5

; <label>:16                                      ; preds = %5
  store i32 0, i32* %i, align 4
  br label %17

; <label>:17                                      ; preds = %33, %16
  %18 = load i32* %i, align 4
  %19 = icmp slt i32 %18, 15
  br i1 %19, label %20, label %36

; <label>:20                                      ; preds = %17
  store i32 0, i32* %j, align 4
  br label %21

; <label>:21                                      ; preds = %29, %20
  %22 = load i32* %j, align 4
  %23 = icmp slt i32 %22, 15
  br i1 %23, label %24, label %32

; <label>:24                                      ; preds = %21
  %25 = load i32* %j, align 4
  %26 = load i32* %i, align 4
  %27 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %26
  %28 = getelementptr inbounds [15 x i32]* %27, i32 0, i32 %25
  store i32 -1, i32* %28, align 4
  br label %29

; <label>:29                                      ; preds = %24
  %30 = load i32* %j, align 4
  %31 = add nsw i32 %30, 1
  store i32 %31, i32* %j, align 4
  br label %21

; <label>:32                                      ; preds = %21
  br label %33

; <label>:33                                      ; preds = %32
  %34 = load i32* %i, align 4
  %35 = add nsw i32 %34, 1
  store i32 %35, i32* %i, align 4
  br label %17

; <label>:36                                      ; preds = %17
  br label %37

; <label>:37                                      ; preds = %202, %36
  %38 = invoke %"class.std::basic_istream"* @_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E(%"class.std::basic_istream"* @_ZSt3cin, %"class.std::basic_string"* %str)
          to label %39 unwind label %127

; <label>:39                                      ; preds = %37
  %40 = bitcast %"class.std::basic_istream"* %38 to i8**
  %41 = load i8** %40
  %42 = getelementptr i8* %41, i64 -12
  %43 = bitcast i8* %42 to i32*
  %44 = load i32* %43
  %45 = bitcast %"class.std::basic_istream"* %38 to i8*
  %46 = getelementptr i8* %45, i32 %44
  %47 = bitcast i8* %46 to %"class.std::basic_ios"*
  %48 = invoke i8* @_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv(%"class.std::basic_ios"* %47)
          to label %49 unwind label %127

; <label>:49                                      ; preds = %39
  %50 = icmp ne i8* %48, null
  br i1 %50, label %51, label %207

; <label>:51                                      ; preds = %49
  %52 = invoke i32 @_ZNKSs4findEcj(%"class.std::basic_string"* %str, i8 signext 32, i32 0)
          to label %53 unwind label %127

; <label>:53                                      ; preds = %51
  store i32 %52, i32* %spacePos1, align 4
  %54 = load i32* %spacePos1, align 4
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg1, %"class.std::basic_string"* %str, i32 0, i32 %54)
          to label %55 unwind label %127

; <label>:55                                      ; preds = %53
  %56 = load i32* %spacePos1, align 4
  %57 = add nsw i32 %56, 1
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %str2, %"class.std::basic_string"* %str, i32 %57, i32 -1)
          to label %58 unwind label %131

; <label>:58                                      ; preds = %55
  %59 = invoke i8* @_ZNSs2atEj(%"class.std::basic_string"* %arg1, i32 0)
          to label %60 unwind label %135

; <label>:60                                      ; preds = %58
  %61 = load i8* %59
  store i8 %61, i8* %type, align 1
  %62 = load i8* %type, align 1
  %63 = sext i8 %62 to i32
  %64 = icmp eq i32 %63, 97
  br i1 %64, label %65, label %175

; <label>:65                                      ; preds = %60
  %66 = invoke i32 @_ZNKSs4findEcj(%"class.std::basic_string"* %str2, i8 signext 32, i32 0)
          to label %67 unwind label %135

; <label>:67                                      ; preds = %65
  store i32 %66, i32* %spacePos2, align 4
  %68 = load i32* %spacePos2, align 4
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg2, %"class.std::basic_string"* %str2, i32 0, i32 %68)
          to label %69 unwind label %135

; <label>:69                                      ; preds = %67
  %70 = load i32* %spacePos2, align 4
  %71 = add nsw i32 %70, 1
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %str3, %"class.std::basic_string"* %str2, i32 %71, i32 -1)
          to label %72 unwind label %139

; <label>:72                                      ; preds = %69
  %73 = invoke i32 @_ZNKSs4findEcj(%"class.std::basic_string"* %str3, i8 signext 32, i32 0)
          to label %74 unwind label %143

; <label>:74                                      ; preds = %72
  store i32 %73, i32* %spacePos3, align 4
  %75 = load i32* %spacePos3, align 4
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg3, %"class.std::basic_string"* %str3, i32 0, i32 %75)
          to label %76 unwind label %143

; <label>:76                                      ; preds = %74
  %77 = load i32* %spacePos3, align 4
  %78 = add nsw i32 %77, 1
  invoke void @_ZNKSs6substrEjj(%"class.std::basic_string"* sret %arg4, %"class.std::basic_string"* %str3, i32 %78, i32 -1)
          to label %79 unwind label %147

; <label>:79                                      ; preds = %76
  %80 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg2)
          to label %81 unwind label %151

; <label>:81                                      ; preds = %79
  %82 = call i32 @atoi(i8* %80) nounwind readonly
  store i32 %82, i32* %start, align 4
  %83 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg3)
          to label %84 unwind label %151

; <label>:84                                      ; preds = %81
  %85 = call i32 @atoi(i8* %83) nounwind readonly
  store i32 %85, i32* %end, align 4
  %86 = load i32* %start, align 4
  %87 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 0
  %88 = load i32* %length, align 4
  %89 = invoke i32 @_Z11getPositioniPii(i32 %86, i32* %87, i32 %88)
          to label %90 unwind label %151

; <label>:90                                      ; preds = %84
  store i32 %89, i32* %startPos, align 4
  %91 = load i32* %end, align 4
  %92 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 0
  %93 = load i32* %length, align 4
  %94 = invoke i32 @_Z11getPositioniPii(i32 %91, i32* %92, i32 %93)
          to label %95 unwind label %151

; <label>:95                                      ; preds = %90
  store i32 %94, i32* %endPos, align 4
  %96 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg4)
          to label %97 unwind label %151

; <label>:97                                      ; preds = %95
  %98 = call i32 @atoi(i8* %96) nounwind readonly
  store i32 %98, i32* %val, align 4
  %99 = load i32* %val, align 4
  %100 = load i32* %endPos, align 4
  %101 = load i32* %startPos, align 4
  %102 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %101
  %103 = getelementptr inbounds [15 x i32]* %102, i32 0, i32 %100
  store i32 %99, i32* %103, align 4
  %104 = load i32* %val, align 4
  %105 = load i32* %startPos, align 4
  %106 = load i32* %endPos, align 4
  %107 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %106
  %108 = getelementptr inbounds [15 x i32]* %107, i32 0, i32 %105
  store i32 %104, i32* %108, align 4
  store i32 0, i32* %i, align 4
  br label %109

; <label>:109                                     ; preds = %160, %97
  %110 = load i32* %i, align 4
  %111 = load i32* %length, align 4
  %112 = icmp slt i32 %110, %111
  br i1 %112, label %113, label %163

; <label>:113                                     ; preds = %109
  store i32 0, i32* %j, align 4
  br label %114

; <label>:114                                     ; preds = %156, %113
  %115 = load i32* %j, align 4
  %116 = load i32* %length, align 4
  %117 = icmp slt i32 %115, %116
  br i1 %117, label %118, label %159

; <label>:118                                     ; preds = %114
  %119 = load i32* %i, align 4
  %120 = load i32* %j, align 4
  %121 = icmp eq i32 %119, %120
  br i1 %121, label %122, label %155

; <label>:122                                     ; preds = %118
  %123 = load i32* %j, align 4
  %124 = load i32* %i, align 4
  %125 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 %124
  %126 = getelementptr inbounds [15 x i32]* %125, i32 0, i32 %123
  store i32 0, i32* %126, align 4
  br label %155

; <label>:127                                     ; preds = %258, %254, %252, %250, %246, %240, %235, %228, %220, %201, %53, %51, %39, %37
  %128 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %129 = extractvalue { i8*, i32 } %128, 0
  store i8* %129, i8** %2
  %130 = extractvalue { i8*, i32 } %128, 1
  store i32 %130, i32* %3
  br label %262

; <label>:131                                     ; preds = %200, %55
  %132 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %133 = extractvalue { i8*, i32 } %132, 0
  store i8* %133, i8** %2
  %134 = extractvalue { i8*, i32 } %132, 1
  store i32 %134, i32* %3
  br label %205

; <label>:135                                     ; preds = %196, %194, %182, %179, %166, %67, %65, %58
  %136 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %137 = extractvalue { i8*, i32 } %136, 0
  store i8* %137, i8** %2
  %138 = extractvalue { i8*, i32 } %136, 1
  store i32 %138, i32* %3
  br label %203

; <label>:139                                     ; preds = %165, %69
  %140 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %141 = extractvalue { i8*, i32 } %140, 0
  store i8* %141, i8** %2
  %142 = extractvalue { i8*, i32 } %140, 1
  store i32 %142, i32* %3
  br label %173

; <label>:143                                     ; preds = %164, %74, %72
  %144 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %145 = extractvalue { i8*, i32 } %144, 0
  store i8* %145, i8** %2
  %146 = extractvalue { i8*, i32 } %144, 1
  store i32 %146, i32* %3
  br label %171

; <label>:147                                     ; preds = %163, %76
  %148 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %149 = extractvalue { i8*, i32 } %148, 0
  store i8* %149, i8** %2
  %150 = extractvalue { i8*, i32 } %148, 1
  store i32 %150, i32* %3
  br label %169

; <label>:151                                     ; preds = %95, %90, %84, %81, %79
  %152 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %153 = extractvalue { i8*, i32 } %152, 0
  store i8* %153, i8** %2
  %154 = extractvalue { i8*, i32 } %152, 1
  store i32 %154, i32* %3
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg4)
          to label %168 unwind label %270

; <label>:155                                     ; preds = %122, %118
  br label %156

; <label>:156                                     ; preds = %155
  %157 = load i32* %j, align 4
  %158 = add nsw i32 %157, 1
  store i32 %158, i32* %j, align 4
  br label %114

; <label>:159                                     ; preds = %114
  br label %160

; <label>:160                                     ; preds = %159
  %161 = load i32* %i, align 4
  %162 = add nsw i32 %161, 1
  store i32 %162, i32* %i, align 4
  br label %109

; <label>:163                                     ; preds = %109
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg4)
          to label %164 unwind label %147

; <label>:164                                     ; preds = %163
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg3)
          to label %165 unwind label %143

; <label>:165                                     ; preds = %164
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str3)
          to label %166 unwind label %139

; <label>:166                                     ; preds = %165
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg2)
          to label %167 unwind label %135

; <label>:167                                     ; preds = %166
  br label %200

; <label>:168                                     ; preds = %151
  br label %169

; <label>:169                                     ; preds = %168, %147
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg3)
          to label %170 unwind label %270

; <label>:170                                     ; preds = %169
  br label %171

; <label>:171                                     ; preds = %170, %143
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str3)
          to label %172 unwind label %270

; <label>:172                                     ; preds = %171
  br label %173

; <label>:173                                     ; preds = %172, %139
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg2)
          to label %174 unwind label %270

; <label>:174                                     ; preds = %173
  br label %203

; <label>:175                                     ; preds = %60
  %176 = load i8* %type, align 1
  %177 = sext i8 %176 to i32
  %178 = icmp eq i32 %177, 99
  br i1 %178, label %179, label %194

; <label>:179                                     ; preds = %175
  invoke void @_ZNSsC1ERKSs(%"class.std::basic_string"* %arg21, %"class.std::basic_string"* %str2)
          to label %180 unwind label %135

; <label>:180                                     ; preds = %179
  %181 = invoke i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %arg21)
          to label %182 unwind label %189

; <label>:182                                     ; preds = %180
  %183 = call i32 @atoi(i8* %181) nounwind readonly
  store i32 %183, i32* %val, align 4
  %184 = load i32* %val, align 4
  %185 = load i32* %length, align 4
  %186 = add nsw i32 %185, 1
  store i32 %186, i32* %length, align 4
  %187 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 %185
  store i32 %184, i32* %187, align 4
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg21)
          to label %188 unwind label %135

; <label>:188                                     ; preds = %182
  br label %199

; <label>:189                                     ; preds = %180
  %190 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %191 = extractvalue { i8*, i32 } %190, 0
  store i8* %191, i8** %2
  %192 = extractvalue { i8*, i32 } %190, 1
  store i32 %192, i32* %3
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg21)
          to label %193 unwind label %270

; <label>:193                                     ; preds = %189
  br label %203

; <label>:194                                     ; preds = %175
  %195 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([24 x i8]* @.str, i32 0, i32 0))
          to label %196 unwind label %135

; <label>:196                                     ; preds = %194
  %197 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %195, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %198 unwind label %135

; <label>:198                                     ; preds = %196
  br label %199

; <label>:199                                     ; preds = %198, %188
  br label %200

; <label>:200                                     ; preds = %199, %167
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str2)
          to label %201 unwind label %131

; <label>:201                                     ; preds = %200
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg1)
          to label %202 unwind label %127

; <label>:202                                     ; preds = %201
  br label %37

; <label>:203                                     ; preds = %193, %174, %135
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str2)
          to label %204 unwind label %270

; <label>:204                                     ; preds = %203
  br label %205

; <label>:205                                     ; preds = %204, %131
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %arg1)
          to label %206 unwind label %270

; <label>:206                                     ; preds = %205
  br label %262

; <label>:207                                     ; preds = %49
  store i32 0, i32* %i, align 4
  br label %208

; <label>:208                                     ; preds = %217, %207
  %209 = load i32* %i, align 4
  %210 = icmp slt i32 %209, 15
  br i1 %210, label %211, label %220

; <label>:211                                     ; preds = %208
  %212 = load i32* %i, align 4
  %213 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 %212
  %214 = load i32* %213, align 4
  %215 = load i32* %i, align 4
  %216 = getelementptr inbounds [15 x i32]* %copy, i32 0, i32 %215
  store i32 %214, i32* %216, align 4
  br label %217

; <label>:217                                     ; preds = %211
  %218 = load i32* %i, align 4
  %219 = add nsw i32 %218, 1
  store i32 %219, i32* %i, align 4
  br label %208

; <label>:220                                     ; preds = %208
  %221 = getelementptr inbounds [15 x i32]* %cities, i32 0, i32 0
  %222 = load i32* %length, align 4
  %223 = sub nsw i32 %222, 1
  %224 = getelementptr inbounds [15 x [15 x i32]]* %cost, i32 0, i32 0
  %225 = getelementptr inbounds [15 x i32]* %copy, i32 0, i32 0
  %226 = getelementptr inbounds [1 x i32]* %lowestCost, i32 0, i32 0
  %227 = getelementptr inbounds [15 x i32]* %bestTour, i32 0, i32 0
  invoke void @_Z7permutePiiiPA15_iS_S_S_(i32* %221, i32 0, i32 %223, [15 x i32]* %224, i32* %225, i32* %226, i32* %227)
          to label %228 unwind label %127

; <label>:228                                     ; preds = %220
  %229 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([10 x i8]* @.str1, i32 0, i32 0))
          to label %230 unwind label %127

; <label>:230                                     ; preds = %228
  store i32 0, i32* %i, align 4
  br label %231

; <label>:231                                     ; preds = %243, %230
  %232 = load i32* %i, align 4
  %233 = load i32* %length, align 4
  %234 = icmp slt i32 %232, %233
  br i1 %234, label %235, label %246

; <label>:235                                     ; preds = %231
  %236 = load i32* %i, align 4
  %237 = getelementptr inbounds [15 x i32]* %bestTour, i32 0, i32 %236
  %238 = load i32* %237, align 4
  %239 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* @_ZSt4cout, i32 %238)
          to label %240 unwind label %127

; <label>:240                                     ; preds = %235
  %241 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %239, i8* getelementptr inbounds ([2 x i8]* @.str2, i32 0, i32 0))
          to label %242 unwind label %127

; <label>:242                                     ; preds = %240
  br label %243

; <label>:243                                     ; preds = %242
  %244 = load i32* %i, align 4
  %245 = add nsw i32 %244, 1
  store i32 %245, i32* %i, align 4
  br label %231

; <label>:246                                     ; preds = %231
  %247 = getelementptr inbounds [15 x i32]* %bestTour, i32 0, i32 0
  %248 = load i32* %247, align 4
  %249 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* @_ZSt4cout, i32 %248)
          to label %250 unwind label %127

; <label>:250                                     ; preds = %246
  %251 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %249, i8* getelementptr inbounds ([2 x i8]* @.str2, i32 0, i32 0))
          to label %252 unwind label %127

; <label>:252                                     ; preds = %250
  %253 = invoke %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* @_ZSt4cout, i8* getelementptr inbounds ([7 x i8]* @.str3, i32 0, i32 0))
          to label %254 unwind label %127

; <label>:254                                     ; preds = %252
  %255 = getelementptr inbounds [1 x i32]* %lowestCost, i32 0, i32 0
  %256 = load i32* %255, align 4
  %257 = invoke %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %253, i32 %256)
          to label %258 unwind label %127

; <label>:258                                     ; preds = %254
  %259 = invoke %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %257, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
          to label %260 unwind label %127

; <label>:260                                     ; preds = %258
  store i32 0, i32* %1
  store i32 1, i32* %4
  call void @_ZNSsD1Ev(%"class.std::basic_string"* %str)
  %261 = load i32* %1
  ret i32 %261

; <label>:262                                     ; preds = %206, %127
  invoke void @_ZNSsD1Ev(%"class.std::basic_string"* %str)
          to label %263 unwind label %270

; <label>:263                                     ; preds = %262
  br label %264

; <label>:264                                     ; preds = %263
  %265 = load i8** %2
  %266 = load i8** %2
  %267 = load i32* %3
  %268 = insertvalue { i8*, i32 } undef, i8* %266, 0
  %269 = insertvalue { i8*, i32 } %268, i32 %267, 1
  resume { i8*, i32 } %269

; <label>:270                                     ; preds = %262, %205, %203, %189, %173, %171, %169, %151
  %271 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
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

declare i32 @atoi(i8*) nounwind readonly

declare i8* @_ZNKSs5c_strEv(%"class.std::basic_string"*)

define i32 @_Z11getPositioniPii(i32 %input, i32* %array, i32 %length) {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32*, align 4
  %4 = alloca i32, align 4
  %position = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 %input, i32* %2, align 4
  store i32* %array, i32** %3, align 4
  store i32 %length, i32* %4, align 4
  store i32 0, i32* %i, align 4
  br label %5

; <label>:5                                       ; preds = %20, %0
  %6 = load i32* %i, align 4
  %7 = load i32* %4, align 4
  %8 = icmp slt i32 %6, %7
  br i1 %8, label %9, label %23

; <label>:9                                       ; preds = %5
  %10 = load i32* %i, align 4
  %11 = load i32** %3, align 4
  %12 = getelementptr inbounds i32* %11, i32 %10
  %13 = load i32* %12
  %14 = load i32* %2, align 4
  %15 = icmp eq i32 %13, %14
  br i1 %15, label %16, label %19

; <label>:16                                      ; preds = %9
  %17 = load i32* %i, align 4
  store i32 %17, i32* %position, align 4
  %18 = load i32* %position, align 4
  store i32 %18, i32* %1
  br label %31

; <label>:19                                      ; preds = %9
  br label %20

; <label>:20                                      ; preds = %19
  %21 = load i32* %i, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, i32* %i, align 4
  br label %5

; <label>:23                                      ; preds = %5
  %24 = call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* @_ZSt4cout, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %25 = load i32* %2, align 4
  %26 = call %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* %24, i32 %25)
  %27 = call %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"* %26, i8* getelementptr inbounds ([28 x i8]* @.str4, i32 0, i32 0))
  %28 = call %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"* %27, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
  %29 = load i32* %2, align 4
  %30 = sub nsw i32 %29, 1
  store i32 %30, i32* %1
  br label %31

; <label>:31                                      ; preds = %23, %16
  %32 = load i32* %1
  ret i32 %32
}

declare void @_ZNSsD1Ev(%"class.std::basic_string"*)

declare void @_ZSt9terminatev()

declare void @_ZNSsC1ERKSs(%"class.std::basic_string"*, %"class.std::basic_string"*)

declare %"class.std::basic_ostream"* @_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(%"class.std::basic_ostream"*, i8*)

declare %"class.std::basic_ostream"* @_ZNSolsEPFRSoS_E(%"class.std::basic_ostream"*, %"class.std::basic_ostream"* (%"class.std::basic_ostream"*)*)

declare %"class.std::basic_ostream"* @_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%"class.std::basic_ostream"*)

define void @_Z7permutePiiiPA15_iS_S_S_(i32* %array, i32 %start, i32 %end, [15 x i32]* %costs, i32* %copy, i32* %finalCost, i32* %finalTour) {
  %1 = alloca i32*, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca [15 x i32]*, align 4
  %5 = alloca i32*, align 4
  %6 = alloca i32*, align 4
  %7 = alloca i32*, align 4
  %i = alloca i32, align 4
  %cost = alloca i32, align 4
  store i32* %array, i32** %1, align 4
  store i32 %start, i32* %2, align 4
  store i32 %end, i32* %3, align 4
  store [15 x i32]* %costs, [15 x i32]** %4, align 4
  store i32* %copy, i32** %5, align 4
  store i32* %finalCost, i32** %6, align 4
  store i32* %finalTour, i32** %7, align 4
  %8 = load i32* %2, align 4
  %9 = load i32* %3, align 4
  %10 = icmp eq i32 %8, %9
  br i1 %10, label %11, label %72

; <label>:11                                      ; preds = %0
  %12 = load i32** %1, align 4
  %13 = load [15 x i32]** %4, align 4
  %14 = load i32* %3, align 4
  %15 = add nsw i32 %14, 1
  %16 = load i32** %5, align 4
  %17 = call i32 @_Z7getCostPiPA15_iiS_(i32* %12, [15 x i32]* %13, i32 %15, i32* %16)
  store i32 %17, i32* %cost, align 4
  %18 = load i32** %6, align 4
  %19 = getelementptr inbounds i32* %18, i32 0
  %20 = load i32* %19
  %21 = icmp eq i32 %20, 0
  br i1 %21, label %22, label %43

; <label>:22                                      ; preds = %11
  %23 = load i32* %cost, align 4
  %24 = load i32** %6, align 4
  %25 = getelementptr inbounds i32* %24, i32 0
  store i32 %23, i32* %25
  store i32 0, i32* %i, align 4
  br label %26

; <label>:26                                      ; preds = %39, %22
  %27 = load i32* %i, align 4
  %28 = load i32* %3, align 4
  %29 = add nsw i32 %28, 1
  %30 = icmp slt i32 %27, %29
  br i1 %30, label %31, label %42

; <label>:31                                      ; preds = %26
  %32 = load i32* %i, align 4
  %33 = load i32** %1, align 4
  %34 = getelementptr inbounds i32* %33, i32 %32
  %35 = load i32* %34
  %36 = load i32* %i, align 4
  %37 = load i32** %7, align 4
  %38 = getelementptr inbounds i32* %37, i32 %36
  store i32 %35, i32* %38
  br label %39

; <label>:39                                      ; preds = %31
  %40 = load i32* %i, align 4
  %41 = add nsw i32 %40, 1
  store i32 %41, i32* %i, align 4
  br label %26

; <label>:42                                      ; preds = %26
  br label %71

; <label>:43                                      ; preds = %11
  %44 = load i32* %cost, align 4
  %45 = load i32** %6, align 4
  %46 = getelementptr inbounds i32* %45, i32 0
  %47 = load i32* %46
  %48 = icmp slt i32 %44, %47
  br i1 %48, label %49, label %70

; <label>:49                                      ; preds = %43
  %50 = load i32* %cost, align 4
  %51 = load i32** %6, align 4
  %52 = getelementptr inbounds i32* %51, i32 0
  store i32 %50, i32* %52
  store i32 0, i32* %i, align 4
  br label %53

; <label>:53                                      ; preds = %66, %49
  %54 = load i32* %i, align 4
  %55 = load i32* %3, align 4
  %56 = add nsw i32 %55, 1
  %57 = icmp slt i32 %54, %56
  br i1 %57, label %58, label %69

; <label>:58                                      ; preds = %53
  %59 = load i32* %i, align 4
  %60 = load i32** %1, align 4
  %61 = getelementptr inbounds i32* %60, i32 %59
  %62 = load i32* %61
  %63 = load i32* %i, align 4
  %64 = load i32** %7, align 4
  %65 = getelementptr inbounds i32* %64, i32 %63
  store i32 %62, i32* %65
  br label %66

; <label>:66                                      ; preds = %58
  %67 = load i32* %i, align 4
  %68 = add nsw i32 %67, 1
  store i32 %68, i32* %i, align 4
  br label %53

; <label>:69                                      ; preds = %53
  br label %70

; <label>:70                                      ; preds = %69, %43
  br label %71

; <label>:71                                      ; preds = %70, %42
  br label %103

; <label>:72                                      ; preds = %0
  %73 = load i32* %2, align 4
  store i32 %73, i32* %i, align 4
  br label %74

; <label>:74                                      ; preds = %99, %72
  %75 = load i32* %i, align 4
  %76 = load i32* %3, align 4
  %77 = icmp sle i32 %75, %76
  br i1 %77, label %78, label %102

; <label>:78                                      ; preds = %74
  %79 = load i32** %1, align 4
  %80 = load i32* %2, align 4
  %81 = getelementptr inbounds i32* %79, i32 %80
  %82 = load i32** %1, align 4
  %83 = load i32* %i, align 4
  %84 = getelementptr inbounds i32* %82, i32 %83
  call void @_Z4swapPiS_(i32* %81, i32* %84)
  %85 = load i32** %1, align 4
  %86 = load i32* %2, align 4
  %87 = add nsw i32 %86, 1
  %88 = load i32* %3, align 4
  %89 = load [15 x i32]** %4, align 4
  %90 = load i32** %5, align 4
  %91 = load i32** %6, align 4
  %92 = load i32** %7, align 4
  call void @_Z7permutePiiiPA15_iS_S_S_(i32* %85, i32 %87, i32 %88, [15 x i32]* %89, i32* %90, i32* %91, i32* %92)
  %93 = load i32** %1, align 4
  %94 = load i32* %2, align 4
  %95 = getelementptr inbounds i32* %93, i32 %94
  %96 = load i32** %1, align 4
  %97 = load i32* %i, align 4
  %98 = getelementptr inbounds i32* %96, i32 %97
  call void @_Z4swapPiS_(i32* %95, i32* %98)
  br label %99

; <label>:99                                      ; preds = %78
  %100 = load i32* %i, align 4
  %101 = add nsw i32 %100, 1
  store i32 %101, i32* %i, align 4
  br label %74

; <label>:102                                     ; preds = %74
  br label %103

; <label>:103                                     ; preds = %102, %71
  ret void
}

declare %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"*, i32)

define i32 @_Z7getCostPiPA15_iiS_(i32* %tour, [15 x i32]* %costs, i32 %length, i32* %cities) {
  %1 = alloca i32*, align 4
  %2 = alloca [15 x i32]*, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32*, align 4
  %cost = alloca i32, align 4
  %i = alloca i32, align 4
  store i32* %tour, i32** %1, align 4
  store [15 x i32]* %costs, [15 x i32]** %2, align 4
  store i32 %length, i32* %3, align 4
  store i32* %cities, i32** %4, align 4
  store i32 0, i32* %cost, align 4
  store i32 0, i32* %i, align 4
  br label %5

; <label>:5                                       ; preds = %32, %0
  %6 = load i32* %i, align 4
  %7 = load i32* %3, align 4
  %8 = sub nsw i32 %7, 1
  %9 = icmp slt i32 %6, %8
  br i1 %9, label %10, label %35

; <label>:10                                      ; preds = %5
  %11 = load i32* %i, align 4
  %12 = add nsw i32 %11, 1
  %13 = load i32** %1, align 4
  %14 = getelementptr inbounds i32* %13, i32 %12
  %15 = load i32* %14
  %16 = load i32** %4, align 4
  %17 = load i32* %3, align 4
  %18 = call i32 @_Z11getPositioniPii(i32 %15, i32* %16, i32 %17)
  %19 = load i32* %i, align 4
  %20 = load i32** %1, align 4
  %21 = getelementptr inbounds i32* %20, i32 %19
  %22 = load i32* %21
  %23 = load i32** %4, align 4
  %24 = load i32* %3, align 4
  %25 = call i32 @_Z11getPositioniPii(i32 %22, i32* %23, i32 %24)
  %26 = load [15 x i32]** %2, align 4
  %27 = getelementptr inbounds [15 x i32]* %26, i32 %25
  %28 = getelementptr inbounds [15 x i32]* %27, i32 0, i32 %18
  %29 = load i32* %28
  %30 = load i32* %cost, align 4
  %31 = add nsw i32 %30, %29
  store i32 %31, i32* %cost, align 4
  br label %32

; <label>:32                                      ; preds = %10
  %33 = load i32* %i, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %i, align 4
  br label %5

; <label>:35                                      ; preds = %5
  %36 = load i32** %1, align 4
  %37 = getelementptr inbounds i32* %36, i32 0
  %38 = load i32* %37
  %39 = load i32** %4, align 4
  %40 = load i32* %3, align 4
  %41 = call i32 @_Z11getPositioniPii(i32 %38, i32* %39, i32 %40)
  %42 = load i32* %3, align 4
  %43 = sub nsw i32 %42, 1
  %44 = load i32** %1, align 4
  %45 = getelementptr inbounds i32* %44, i32 %43
  %46 = load i32* %45
  %47 = load i32** %4, align 4
  %48 = load i32* %3, align 4
  %49 = call i32 @_Z11getPositioniPii(i32 %46, i32* %47, i32 %48)
  %50 = load [15 x i32]** %2, align 4
  %51 = getelementptr inbounds [15 x i32]* %50, i32 %49
  %52 = getelementptr inbounds [15 x i32]* %51, i32 0, i32 %41
  %53 = load i32* %52
  %54 = load i32* %cost, align 4
  %55 = add nsw i32 %54, %53
  store i32 %55, i32* %cost, align 4
  %56 = load i32* %cost, align 4
  ret i32 %56
}

define void @_Z4swapPiS_(i32* %a, i32* %b) nounwind {
  %1 = alloca i32*, align 4
  %2 = alloca i32*, align 4
  %temp = alloca i32, align 4
  store i32* %a, i32** %1, align 4
  store i32* %b, i32** %2, align 4
  %3 = load i32** %1, align 4
  %4 = load i32* %3
  store i32 %4, i32* %temp, align 4
  %5 = load i32** %2, align 4
  %6 = load i32* %5
  %7 = load i32** %1, align 4
  store i32 %6, i32* %7
  %8 = load i32* %temp, align 4
  %9 = load i32** %2, align 4
  store i32 %8, i32* %9
  ret void
}

define internal void @_GLOBAL__I_a() {
  call void @__cxx_global_var_init()
  ret void
}
