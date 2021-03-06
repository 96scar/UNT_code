// Generated by llvm2cpp - DO NOT MODIFY!

#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Constants.h>
#include <llvm/GlobalVariable.h>
#include <llvm/Function.h>
#include <llvm/CallingConv.h>
#include <llvm/BasicBlock.h>
#include <llvm/Instructions.h>
#include <llvm/InlineAsm.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>
#include <llvm/Pass.h>
#include <llvm/PassManager.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <algorithm>
using namespace llvm;

Module* makeLLVMModule();

int main(int argc, char**argv) {
  Module* Mod = makeLLVMModule();
  verifyModule(*Mod, PrintMessageAction);
  PassManager PM;
  PM.add(createPrintModulePass(&outs()));
  PM.run(*Mod);
  return 0;
}


Module* makeLLVMModule() {
 // Module Construction
 Module* mod = new Module("hello.ll", getGlobalContext());
 mod->setDataLayout("e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128");
 mod->setTargetTriple("i386-pc-linux-gnu");
 
 // Type Definitions
 StructType *StructTy_class_std__ios_base__Init = mod->getTypeByName("class.std::ios_base::Init");
 if (!StructTy_class_std__ios_base__Init) {
 StructTy_class_std__ios_base__Init = StructType::create(mod->getContext(), "class.std::ios_base::Init");
 }
 std::vector<Type*>StructTy_class_std__ios_base__Init_fields;
 StructTy_class_std__ios_base__Init_fields.push_back(IntegerType::get(mod->getContext(), 8));
 if (StructTy_class_std__ios_base__Init->isOpaque()) {
 StructTy_class_std__ios_base__Init->setBody(StructTy_class_std__ios_base__Init_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_0 = PointerType::get(StructTy_class_std__ios_base__Init, 0);
 
 PointerType* PointerTy_2 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);
 
 PointerType* PointerTy_1 = PointerType::get(PointerTy_2, 0);
 
 StructType *StructTy_class_std__basic_ostream = mod->getTypeByName("class.std::basic_ostream");
 if (!StructTy_class_std__basic_ostream) {
 StructTy_class_std__basic_ostream = StructType::create(mod->getContext(), "class.std::basic_ostream");
 }
 std::vector<Type*>StructTy_class_std__basic_ostream_fields;
 std::vector<Type*>FuncTy_6_args;
 FunctionType* FuncTy_6 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 32),
  /*Params=*/FuncTy_6_args,
  /*isVarArg=*/true);
 
 PointerType* PointerTy_5 = PointerType::get(FuncTy_6, 0);
 
 PointerType* PointerTy_4 = PointerType::get(PointerTy_5, 0);
 
 StructTy_class_std__basic_ostream_fields.push_back(PointerTy_4);
 StructType *StructTy_class_std__basic_ios = mod->getTypeByName("class.std::basic_ios");
 if (!StructTy_class_std__basic_ios) {
 StructTy_class_std__basic_ios = StructType::create(mod->getContext(), "class.std::basic_ios");
 }
 std::vector<Type*>StructTy_class_std__basic_ios_fields;
 StructType *StructTy_class_std__ios_base = mod->getTypeByName("class.std::ios_base");
 if (!StructTy_class_std__ios_base) {
 StructTy_class_std__ios_base = StructType::create(mod->getContext(), "class.std::ios_base");
 }
 std::vector<Type*>StructTy_class_std__ios_base_fields;
 StructTy_class_std__ios_base_fields.push_back(PointerTy_4);
 StructTy_class_std__ios_base_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructTy_class_std__ios_base_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructTy_class_std__ios_base_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructTy_class_std__ios_base_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructTy_class_std__ios_base_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructType *StructTy_struct_std__ios_base___Callback_list = mod->getTypeByName("struct.std::ios_base::_Callback_list");
 if (!StructTy_struct_std__ios_base___Callback_list) {
 StructTy_struct_std__ios_base___Callback_list = StructType::create(mod->getContext(), "struct.std::ios_base::_Callback_list");
 }
 std::vector<Type*>StructTy_struct_std__ios_base___Callback_list_fields;
 PointerType* PointerTy_7 = PointerType::get(StructTy_struct_std__ios_base___Callback_list, 0);
 
 StructTy_struct_std__ios_base___Callback_list_fields.push_back(PointerTy_7);
 std::vector<Type*>FuncTy_9_args;
 FuncTy_9_args.push_back(IntegerType::get(mod->getContext(), 32));
 PointerType* PointerTy_10 = PointerType::get(StructTy_class_std__ios_base, 0);
 
 FuncTy_9_args.push_back(PointerTy_10);
 FuncTy_9_args.push_back(IntegerType::get(mod->getContext(), 32));
 FunctionType* FuncTy_9 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_9_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_8 = PointerType::get(FuncTy_9, 0);
 
 StructTy_struct_std__ios_base___Callback_list_fields.push_back(PointerTy_8);
 StructTy_struct_std__ios_base___Callback_list_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructTy_struct_std__ios_base___Callback_list_fields.push_back(IntegerType::get(mod->getContext(), 32));
 if (StructTy_struct_std__ios_base___Callback_list->isOpaque()) {
 StructTy_struct_std__ios_base___Callback_list->setBody(StructTy_struct_std__ios_base___Callback_list_fields, /*isPacked=*/false);
 }
 
 
 StructTy_class_std__ios_base_fields.push_back(PointerTy_7);
 StructType *StructTy_struct_std__ios_base___Words = mod->getTypeByName("struct.std::ios_base::_Words");
 if (!StructTy_struct_std__ios_base___Words) {
 StructTy_struct_std__ios_base___Words = StructType::create(mod->getContext(), "struct.std::ios_base::_Words");
 }
 std::vector<Type*>StructTy_struct_std__ios_base___Words_fields;
 StructTy_struct_std__ios_base___Words_fields.push_back(PointerTy_2);
 StructTy_struct_std__ios_base___Words_fields.push_back(IntegerType::get(mod->getContext(), 32));
 if (StructTy_struct_std__ios_base___Words->isOpaque()) {
 StructTy_struct_std__ios_base___Words->setBody(StructTy_struct_std__ios_base___Words_fields, /*isPacked=*/false);
 }
 
 StructTy_class_std__ios_base_fields.push_back(StructTy_struct_std__ios_base___Words);
 ArrayType* ArrayTy_11 = ArrayType::get(StructTy_struct_std__ios_base___Words, 8);
 
 StructTy_class_std__ios_base_fields.push_back(ArrayTy_11);
 StructTy_class_std__ios_base_fields.push_back(IntegerType::get(mod->getContext(), 32));
 PointerType* PointerTy_12 = PointerType::get(StructTy_struct_std__ios_base___Words, 0);
 
 StructTy_class_std__ios_base_fields.push_back(PointerTy_12);
 StructType *StructTy_class_std__locale = mod->getTypeByName("class.std::locale");
 if (!StructTy_class_std__locale) {
 StructTy_class_std__locale = StructType::create(mod->getContext(), "class.std::locale");
 }
 std::vector<Type*>StructTy_class_std__locale_fields;
 StructType *StructTy_class_std__locale___Impl = mod->getTypeByName("class.std::locale::_Impl");
 if (!StructTy_class_std__locale___Impl) {
 StructTy_class_std__locale___Impl = StructType::create(mod->getContext(), "class.std::locale::_Impl");
 }
 std::vector<Type*>StructTy_class_std__locale___Impl_fields;
 StructTy_class_std__locale___Impl_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructType *StructTy_class_std__locale__facet = mod->getTypeByName("class.std::locale::facet");
 if (!StructTy_class_std__locale__facet) {
 StructTy_class_std__locale__facet = StructType::create(mod->getContext(), "class.std::locale::facet");
 }
 std::vector<Type*>StructTy_class_std__locale__facet_fields;
 StructTy_class_std__locale__facet_fields.push_back(PointerTy_4);
 StructTy_class_std__locale__facet_fields.push_back(IntegerType::get(mod->getContext(), 32));
 if (StructTy_class_std__locale__facet->isOpaque()) {
 StructTy_class_std__locale__facet->setBody(StructTy_class_std__locale__facet_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_15 = PointerType::get(StructTy_class_std__locale__facet, 0);
 
 PointerType* PointerTy_14 = PointerType::get(PointerTy_15, 0);
 
 StructTy_class_std__locale___Impl_fields.push_back(PointerTy_14);
 StructTy_class_std__locale___Impl_fields.push_back(IntegerType::get(mod->getContext(), 32));
 StructTy_class_std__locale___Impl_fields.push_back(PointerTy_14);
 StructTy_class_std__locale___Impl_fields.push_back(PointerTy_1);
 if (StructTy_class_std__locale___Impl->isOpaque()) {
 StructTy_class_std__locale___Impl->setBody(StructTy_class_std__locale___Impl_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_13 = PointerType::get(StructTy_class_std__locale___Impl, 0);
 
 StructTy_class_std__locale_fields.push_back(PointerTy_13);
 if (StructTy_class_std__locale->isOpaque()) {
 StructTy_class_std__locale->setBody(StructTy_class_std__locale_fields, /*isPacked=*/false);
 }
 
 StructTy_class_std__ios_base_fields.push_back(StructTy_class_std__locale);
 if (StructTy_class_std__ios_base->isOpaque()) {
 StructTy_class_std__ios_base->setBody(StructTy_class_std__ios_base_fields, /*isPacked=*/false);
 }
 
 StructTy_class_std__basic_ios_fields.push_back(StructTy_class_std__ios_base);
 PointerType* PointerTy_3 = PointerType::get(StructTy_class_std__basic_ostream, 0);
 
 StructTy_class_std__basic_ios_fields.push_back(PointerTy_3);
 StructTy_class_std__basic_ios_fields.push_back(IntegerType::get(mod->getContext(), 8));
 StructTy_class_std__basic_ios_fields.push_back(IntegerType::get(mod->getContext(), 8));
 StructType *StructTy_class_std__basic_streambuf = mod->getTypeByName("class.std::basic_streambuf");
 if (!StructTy_class_std__basic_streambuf) {
 StructTy_class_std__basic_streambuf = StructType::create(mod->getContext(), "class.std::basic_streambuf");
 }
 std::vector<Type*>StructTy_class_std__basic_streambuf_fields;
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_4);
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_2);
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_2);
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_2);
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_2);
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_2);
 StructTy_class_std__basic_streambuf_fields.push_back(PointerTy_2);
 StructTy_class_std__basic_streambuf_fields.push_back(StructTy_class_std__locale);
 if (StructTy_class_std__basic_streambuf->isOpaque()) {
 StructTy_class_std__basic_streambuf->setBody(StructTy_class_std__basic_streambuf_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_16 = PointerType::get(StructTy_class_std__basic_streambuf, 0);
 
 StructTy_class_std__basic_ios_fields.push_back(PointerTy_16);
 StructType *StructTy_class_std__ctype = mod->getTypeByName("class.std::ctype");
 if (!StructTy_class_std__ctype) {
 StructTy_class_std__ctype = StructType::create(mod->getContext(), "class.std::ctype");
 }
 std::vector<Type*>StructTy_class_std__ctype_fields;
 StructTy_class_std__ctype_fields.push_back(StructTy_class_std__locale__facet);
 StructType *StructTy_struct___locale_struct = mod->getTypeByName("struct.__locale_struct");
 if (!StructTy_struct___locale_struct) {
 StructTy_struct___locale_struct = StructType::create(mod->getContext(), "struct.__locale_struct");
 }
 std::vector<Type*>StructTy_struct___locale_struct_fields;
 StructType *StructTy_struct___locale_data = mod->getTypeByName("struct.__locale_data");
 if (!StructTy_struct___locale_data) {
 StructTy_struct___locale_data = StructType::create(mod->getContext(), "struct.__locale_data");
 }
 std::vector<Type*>StructTy_struct___locale_data_fields;
 if (StructTy_struct___locale_data->isOpaque()) {
 StructTy_struct___locale_data->setBody(StructTy_struct___locale_data_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_20 = PointerType::get(StructTy_struct___locale_data, 0);
 
 ArrayType* ArrayTy_19 = ArrayType::get(PointerTy_20, 13);
 
 StructTy_struct___locale_struct_fields.push_back(ArrayTy_19);
 PointerType* PointerTy_21 = PointerType::get(IntegerType::get(mod->getContext(), 16), 0);
 
 StructTy_struct___locale_struct_fields.push_back(PointerTy_21);
 PointerType* PointerTy_22 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);
 
 StructTy_struct___locale_struct_fields.push_back(PointerTy_22);
 StructTy_struct___locale_struct_fields.push_back(PointerTy_22);
 ArrayType* ArrayTy_23 = ArrayType::get(PointerTy_2, 13);
 
 StructTy_struct___locale_struct_fields.push_back(ArrayTy_23);
 if (StructTy_struct___locale_struct->isOpaque()) {
 StructTy_struct___locale_struct->setBody(StructTy_struct___locale_struct_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_18 = PointerType::get(StructTy_struct___locale_struct, 0);
 
 StructTy_class_std__ctype_fields.push_back(PointerTy_18);
 StructTy_class_std__ctype_fields.push_back(IntegerType::get(mod->getContext(), 8));
 StructTy_class_std__ctype_fields.push_back(PointerTy_22);
 StructTy_class_std__ctype_fields.push_back(PointerTy_22);
 StructTy_class_std__ctype_fields.push_back(PointerTy_21);
 StructTy_class_std__ctype_fields.push_back(IntegerType::get(mod->getContext(), 8));
 ArrayType* ArrayTy_24 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 256);
 
 StructTy_class_std__ctype_fields.push_back(ArrayTy_24);
 StructTy_class_std__ctype_fields.push_back(ArrayTy_24);
 StructTy_class_std__ctype_fields.push_back(IntegerType::get(mod->getContext(), 8));
 if (StructTy_class_std__ctype->isOpaque()) {
 StructTy_class_std__ctype->setBody(StructTy_class_std__ctype_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_17 = PointerType::get(StructTy_class_std__ctype, 0);
 
 StructTy_class_std__basic_ios_fields.push_back(PointerTy_17);
 StructType *StructTy_class_std__num_put = mod->getTypeByName("class.std::num_put");
 if (!StructTy_class_std__num_put) {
 StructTy_class_std__num_put = StructType::create(mod->getContext(), "class.std::num_put");
 }
 std::vector<Type*>StructTy_class_std__num_put_fields;
 StructTy_class_std__num_put_fields.push_back(StructTy_class_std__locale__facet);
 if (StructTy_class_std__num_put->isOpaque()) {
 StructTy_class_std__num_put->setBody(StructTy_class_std__num_put_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_25 = PointerType::get(StructTy_class_std__num_put, 0);
 
 StructTy_class_std__basic_ios_fields.push_back(PointerTy_25);
 StructType *StructTy_class_std__num_get = mod->getTypeByName("class.std::num_get");
 if (!StructTy_class_std__num_get) {
 StructTy_class_std__num_get = StructType::create(mod->getContext(), "class.std::num_get");
 }
 std::vector<Type*>StructTy_class_std__num_get_fields;
 StructTy_class_std__num_get_fields.push_back(StructTy_class_std__locale__facet);
 if (StructTy_class_std__num_get->isOpaque()) {
 StructTy_class_std__num_get->setBody(StructTy_class_std__num_get_fields, /*isPacked=*/false);
 }
 
 PointerType* PointerTy_26 = PointerType::get(StructTy_class_std__num_get, 0);
 
 StructTy_class_std__basic_ios_fields.push_back(PointerTy_26);
 if (StructTy_class_std__basic_ios->isOpaque()) {
 StructTy_class_std__basic_ios->setBody(StructTy_class_std__basic_ios_fields, /*isPacked=*/false);
 }
 
 StructTy_class_std__basic_ostream_fields.push_back(StructTy_class_std__basic_ios);
 if (StructTy_class_std__basic_ostream->isOpaque()) {
 StructTy_class_std__basic_ostream->setBody(StructTy_class_std__basic_ostream_fields, /*isPacked=*/false);
 }
 
 
 ArrayType* ArrayTy_27 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 13);
 
 PointerType* PointerTy_28 = PointerType::get(ArrayTy_27, 0);
 
 std::vector<Type*>StructTy_30_fields;
 StructTy_30_fields.push_back(IntegerType::get(mod->getContext(), 32));
 std::vector<Type*>FuncTy_32_args;
 FunctionType* FuncTy_32 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_32_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_31 = PointerType::get(FuncTy_32, 0);
 
 StructTy_30_fields.push_back(PointerTy_31);
 StructType *StructTy_30 = StructType::get(mod->getContext(), StructTy_30_fields, /*isPacked=*/false);
 
 ArrayType* ArrayTy_29 = ArrayType::get(StructTy_30, 1);
 
 PointerType* PointerTy_33 = PointerType::get(ArrayTy_29, 0);
 
 std::vector<Type*>FuncTy_34_args;
 FuncTy_34_args.push_back(PointerTy_0);
 FunctionType* FuncTy_34 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_34_args,
  /*isVarArg=*/false);
 
 std::vector<Type*>FuncTy_35_args;
 std::vector<Type*>FuncTy_37_args;
 FuncTy_37_args.push_back(PointerTy_2);
 FunctionType* FuncTy_37 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_37_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_36 = PointerType::get(FuncTy_37, 0);
 
 FuncTy_35_args.push_back(PointerTy_36);
 FuncTy_35_args.push_back(PointerTy_2);
 FuncTy_35_args.push_back(PointerTy_2);
 FunctionType* FuncTy_35 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 32),
  /*Params=*/FuncTy_35_args,
  /*isVarArg=*/false);
 
 std::vector<Type*>FuncTy_38_args;
 FunctionType* FuncTy_38 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 32),
  /*Params=*/FuncTy_38_args,
  /*isVarArg=*/false);
 
 std::vector<Type*>FuncTy_40_args;
 FuncTy_40_args.push_back(PointerTy_3);
 FuncTy_40_args.push_back(PointerTy_2);
 FuncTy_40_args.push_back(IntegerType::get(mod->getContext(), 32));
 FunctionType* FuncTy_40 = FunctionType::get(
  /*Result=*/PointerTy_3,
  /*Params=*/FuncTy_40_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_39 = PointerType::get(FuncTy_40, 0);
 
 PointerType* PointerTy_41 = PointerType::get(PointerTy_17, 0);
 
 std::vector<Type*>FuncTy_43_args;
 FuncTy_43_args.push_back(PointerTy_17);
 FunctionType* FuncTy_43 = FunctionType::get(
  /*Result=*/Type::getVoidTy(mod->getContext()),
  /*Params=*/FuncTy_43_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_42 = PointerType::get(FuncTy_43, 0);
 
 std::vector<Type*>FuncTy_47_args;
 FuncTy_47_args.push_back(PointerTy_17);
 FuncTy_47_args.push_back(IntegerType::get(mod->getContext(), 8));
 FunctionType* FuncTy_47 = FunctionType::get(
  /*Result=*/IntegerType::get(mod->getContext(), 8),
  /*Params=*/FuncTy_47_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_46 = PointerType::get(FuncTy_47, 0);
 
 PointerType* PointerTy_45 = PointerType::get(PointerTy_46, 0);
 
 PointerType* PointerTy_44 = PointerType::get(PointerTy_45, 0);
 
 std::vector<Type*>FuncTy_49_args;
 FuncTy_49_args.push_back(PointerTy_3);
 FuncTy_49_args.push_back(IntegerType::get(mod->getContext(), 8));
 FunctionType* FuncTy_49 = FunctionType::get(
  /*Result=*/PointerTy_3,
  /*Params=*/FuncTy_49_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_48 = PointerType::get(FuncTy_49, 0);
 
 std::vector<Type*>FuncTy_51_args;
 FuncTy_51_args.push_back(PointerTy_3);
 FunctionType* FuncTy_51 = FunctionType::get(
  /*Result=*/PointerTy_3,
  /*Params=*/FuncTy_51_args,
  /*isVarArg=*/false);
 
 PointerType* PointerTy_50 = PointerType::get(FuncTy_51, 0);
 
 PointerType* PointerTy_52 = PointerType::get(FuncTy_34, 0);
 
 PointerType* PointerTy_53 = PointerType::get(FuncTy_35, 0);
 
 
 // Function Declarations
 
 Function* func__ZNSt8ios_base4InitC1Ev = mod->getFunction("_ZNSt8ios_base4InitC1Ev");
 if (!func__ZNSt8ios_base4InitC1Ev) {
 func__ZNSt8ios_base4InitC1Ev = Function::Create(
  /*Type=*/FuncTy_34,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZNSt8ios_base4InitC1Ev", mod); // (external, no body)
 func__ZNSt8ios_base4InitC1Ev->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZNSt8ios_base4InitC1Ev_PAL;
 func__ZNSt8ios_base4InitC1Ev->setAttributes(func__ZNSt8ios_base4InitC1Ev_PAL);
 
 Function* func__ZNSt8ios_base4InitD1Ev = mod->getFunction("_ZNSt8ios_base4InitD1Ev");
 if (!func__ZNSt8ios_base4InitD1Ev) {
 func__ZNSt8ios_base4InitD1Ev = Function::Create(
  /*Type=*/FuncTy_34,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZNSt8ios_base4InitD1Ev", mod); // (external, no body)
 func__ZNSt8ios_base4InitD1Ev->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZNSt8ios_base4InitD1Ev_PAL;
 func__ZNSt8ios_base4InitD1Ev->setAttributes(func__ZNSt8ios_base4InitD1Ev_PAL);
 
 Function* func___cxa_atexit = mod->getFunction("__cxa_atexit");
 if (!func___cxa_atexit) {
 func___cxa_atexit = Function::Create(
  /*Type=*/FuncTy_35,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"__cxa_atexit", mod); // (external, no body)
 func___cxa_atexit->setCallingConv(CallingConv::C);
 }
 AttrListPtr func___cxa_atexit_PAL;
 {
  SmallVector<AttributeWithIndex, 4> Attrs;
  AttributeWithIndex PAWI;
  PAWI.Index = 4294967295U; PAWI.Attrs = 0  | Attribute::NoUnwind;
  Attrs.push_back(PAWI);
  func___cxa_atexit_PAL = AttrListPtr::get(Attrs.begin(), Attrs.end());
  
 }
 func___cxa_atexit->setAttributes(func___cxa_atexit_PAL);
 
 Function* func_main = mod->getFunction("main");
 if (!func_main) {
 func_main = Function::Create(
  /*Type=*/FuncTy_38,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"main", mod); 
 func_main->setCallingConv(CallingConv::C);
 }
 AttrListPtr func_main_PAL;
 func_main->setAttributes(func_main_PAL);
 
 Function* func__ZNSo3putEc = mod->getFunction("_ZNSo3putEc");
 if (!func__ZNSo3putEc) {
 func__ZNSo3putEc = Function::Create(
  /*Type=*/FuncTy_49,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZNSo3putEc", mod); // (external, no body)
 func__ZNSo3putEc->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZNSo3putEc_PAL;
 {
  SmallVector<AttributeWithIndex, 4> Attrs;
  AttributeWithIndex PAWI;
  PAWI.Index = 2U; PAWI.Attrs = 0  | Attribute::SExt;
  Attrs.push_back(PAWI);
  func__ZNSo3putEc_PAL = AttrListPtr::get(Attrs.begin(), Attrs.end());
  
 }
 func__ZNSo3putEc->setAttributes(func__ZNSo3putEc_PAL);
 
 Function* func__ZNKSt5ctypeIcE13_M_widen_initEv = mod->getFunction("_ZNKSt5ctypeIcE13_M_widen_initEv");
 if (!func__ZNKSt5ctypeIcE13_M_widen_initEv) {
 func__ZNKSt5ctypeIcE13_M_widen_initEv = Function::Create(
  /*Type=*/FuncTy_43,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZNKSt5ctypeIcE13_M_widen_initEv", mod); // (external, no body)
 func__ZNKSt5ctypeIcE13_M_widen_initEv->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZNKSt5ctypeIcE13_M_widen_initEv_PAL;
 func__ZNKSt5ctypeIcE13_M_widen_initEv->setAttributes(func__ZNKSt5ctypeIcE13_M_widen_initEv_PAL);
 
 Function* func__ZSt16__throw_bad_castv = mod->getFunction("_ZSt16__throw_bad_castv");
 if (!func__ZSt16__throw_bad_castv) {
 func__ZSt16__throw_bad_castv = Function::Create(
  /*Type=*/FuncTy_32,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZSt16__throw_bad_castv", mod); // (external, no body)
 func__ZSt16__throw_bad_castv->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZSt16__throw_bad_castv_PAL;
 {
  SmallVector<AttributeWithIndex, 4> Attrs;
  AttributeWithIndex PAWI;
  PAWI.Index = 4294967295U; PAWI.Attrs = 0  | Attribute::NoReturn;
  Attrs.push_back(PAWI);
  func__ZSt16__throw_bad_castv_PAL = AttrListPtr::get(Attrs.begin(), Attrs.end());
  
 }
 func__ZSt16__throw_bad_castv->setAttributes(func__ZSt16__throw_bad_castv_PAL);
 
 Function* func__ZNSo5flushEv = mod->getFunction("_ZNSo5flushEv");
 if (!func__ZNSo5flushEv) {
 func__ZNSo5flushEv = Function::Create(
  /*Type=*/FuncTy_51,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZNSo5flushEv", mod); // (external, no body)
 func__ZNSo5flushEv->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZNSo5flushEv_PAL;
 func__ZNSo5flushEv->setAttributes(func__ZNSo5flushEv_PAL);
 
 Function* func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i = mod->getFunction("_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i");
 if (!func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i) {
 func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i = Function::Create(
  /*Type=*/FuncTy_40,
  /*Linkage=*/GlobalValue::ExternalLinkage,
  /*Name=*/"_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i", mod); // (external, no body)
 func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i_PAL;
 func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i->setAttributes(func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i_PAL);
 
 Function* func__GLOBAL__I_a = mod->getFunction("_GLOBAL__I_a");
 if (!func__GLOBAL__I_a) {
 func__GLOBAL__I_a = Function::Create(
  /*Type=*/FuncTy_32,
  /*Linkage=*/GlobalValue::InternalLinkage,
  /*Name=*/"_GLOBAL__I_a", mod); 
 func__GLOBAL__I_a->setCallingConv(CallingConv::C);
 }
 AttrListPtr func__GLOBAL__I_a_PAL;
 func__GLOBAL__I_a->setAttributes(func__GLOBAL__I_a_PAL);
 
 // Global Variable Declarations

 
 GlobalVariable* gvar_struct__ZStL8__ioinit = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/StructTy_class_std__ios_base__Init,
 /*isConstant=*/false,
 /*Linkage=*/GlobalValue::InternalLinkage,
 /*Initializer=*/0, // has initializer, specified below
 /*Name=*/"_ZStL8__ioinit");
 gvar_struct__ZStL8__ioinit->setAlignment(1);
 
 GlobalVariable* gvar_ptr___dso_handle = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/PointerTy_2,
 /*isConstant=*/false,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Initializer=*/0, 
 /*Name=*/"__dso_handle");
 
 GlobalVariable* gvar_struct__ZSt4cout = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/StructTy_class_std__basic_ostream,
 /*isConstant=*/false,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Initializer=*/0, 
 /*Name=*/"_ZSt4cout");
 
 GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/ArrayTy_27,
 /*isConstant=*/true,
 /*Linkage=*/GlobalValue::PrivateLinkage,
 /*Initializer=*/0, // has initializer, specified below
 /*Name=*/".str");
 gvar_array__str->setAlignment(1);
 
 GlobalVariable* gvar_array_llvm_global_ctors = new GlobalVariable(/*Module=*/*mod, 
 /*Type=*/ArrayTy_29,
 /*isConstant=*/false,
 /*Linkage=*/GlobalValue::AppendingLinkage,
 /*Initializer=*/0, // has initializer, specified below
 /*Name=*/"llvm.global_ctors");
 
 // Constant Definitions
 ConstantAggregateZero* const_struct_54 = ConstantAggregateZero::get(StructTy_class_std__ios_base__Init);
 Constant* const_array_55 = ConstantArray::get(mod->getContext(), "Hello world!", true);
 std::vector<Constant*> const_array_56_elems;
 std::vector<Constant*> const_struct_57_fields;
 ConstantInt* const_int32_58 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("65535"), 10));
 const_struct_57_fields.push_back(const_int32_58);
 const_struct_57_fields.push_back(func__GLOBAL__I_a);
 Constant* const_struct_57 = ConstantStruct::get(StructTy_30, const_struct_57_fields);
 const_array_56_elems.push_back(const_struct_57);
 Constant* const_array_56 = ConstantArray::get(ArrayTy_29, const_array_56_elems);
 std::vector<Constant*> const_ptr_59_indices;
 ConstantInt* const_int32_60 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
 const_ptr_59_indices.push_back(const_int32_60);
 const_ptr_59_indices.push_back(const_int32_60);
 Constant* const_ptr_59 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_59_indices);
 ConstantInt* const_int32_61 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("12"), 10));
 Constant* const_ptr_62 = ConstantExpr::getCast(Instruction::BitCast, gvar_struct__ZSt4cout, PointerTy_1);
 ConstantInt* const_int32_63 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("-12"), 10));
 ConstantInt* const_int32_64 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("124"), 10));
 Constant* const_ptr_65 = ConstantExpr::getCast(Instruction::BitCast, gvar_struct__ZSt4cout, PointerTy_2);
 ConstantPointerNull* const_ptr_66 = ConstantPointerNull::get(PointerTy_17);
 ConstantInt* const_int32_67 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("6"), 10));
 ConstantInt* const_int8_68 = ConstantInt::get(mod->getContext(), APInt(8, StringRef("0"), 10));
 ConstantInt* const_int32_69 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("7"), 10));
 ConstantInt* const_int32_70 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("10"), 10));
 ConstantInt* const_int8_71 = ConstantInt::get(mod->getContext(), APInt(8, StringRef("10"), 10));
 Constant* const_ptr_72 = ConstantExpr::getCast(Instruction::BitCast, func__ZNSt8ios_base4InitD1Ev, PointerTy_36);
 std::vector<Constant*> const_ptr_73_indices;
 const_ptr_73_indices.push_back(const_int32_60);
 const_ptr_73_indices.push_back(const_int32_60);
 Constant* const_ptr_73 = ConstantExpr::getGetElementPtr(gvar_struct__ZStL8__ioinit, const_ptr_73_indices);
 Constant* const_ptr_74 = ConstantExpr::getCast(Instruction::BitCast, gvar_ptr___dso_handle, PointerTy_2);
 
 // Global Variable Definitions
 gvar_struct__ZStL8__ioinit->setInitializer(const_struct_54);
 gvar_array__str->setInitializer(const_array_55);
 gvar_array_llvm_global_ctors->setInitializer(const_array_56);
 
 // Function Definitions
 
 // Function: main (func_main)
 {
  
  BasicBlock* label_75 = BasicBlock::Create(mod->getContext(), "",func_main,0);
  BasicBlock* label_76 = BasicBlock::Create(mod->getContext(), "",func_main,0);
  BasicBlock* label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit = BasicBlock::Create(mod->getContext(), "_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit",func_main,0);
  BasicBlock* label_77 = BasicBlock::Create(mod->getContext(), "",func_main,0);
  BasicBlock* label_78 = BasicBlock::Create(mod->getContext(), "",func_main,0);
  BasicBlock* label__ZNKSt5ctypeIcE5widenEc_exit = BasicBlock::Create(mod->getContext(), "_ZNKSt5ctypeIcE5widenEc.exit",func_main,0);
  
  // Block  (label_75)
  std::vector<Value*> ptr_79_params;
  ptr_79_params.push_back(gvar_struct__ZSt4cout);
  ptr_79_params.push_back(const_ptr_59);
  ptr_79_params.push_back(const_int32_61);
  CallInst* ptr_79 = CallInst::Create(func__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i, ptr_79_params, "", label_75);
  ptr_79->setCallingConv(CallingConv::C);
  ptr_79->setTailCall(true);
  AttrListPtr ptr_79_PAL;
  ptr_79->setAttributes(ptr_79_PAL);
  
  LoadInst* ptr_80 = new LoadInst(const_ptr_62, "", false, label_75);
  ptr_80->setAlignment(4);
  GetElementPtrInst* ptr_81 = GetElementPtrInst::Create(ptr_80, const_int32_63, "", label_75);
  CastInst* ptr_82 = new BitCastInst(ptr_81, PointerTy_22, "", label_75);
  LoadInst* int32_83 = new LoadInst(ptr_82, "", false, label_75);
  int32_83->setAlignment(4);
  BinaryOperator* int32__sum = BinaryOperator::Create(Instruction::Add, int32_83, const_int32_64, ".sum", label_75);
  GetElementPtrInst* ptr_84 = GetElementPtrInst::Create(const_ptr_65, int32__sum, "", label_75);
  CastInst* ptr_85 = new BitCastInst(ptr_84, PointerTy_41, "", label_75);
  LoadInst* ptr_86 = new LoadInst(ptr_85, "", false, label_75);
  ptr_86->setAlignment(4);
  ICmpInst* int1_87 = new ICmpInst(*label_75, ICmpInst::ICMP_EQ, ptr_86, const_ptr_66, "");
  BranchInst::Create(label_76, label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit, int1_87, label_75);
  
  // Block  (label_76)
  CallInst* void_89 = CallInst::Create(func__ZSt16__throw_bad_castv, "", label_76);
  void_89->setCallingConv(CallingConv::C);
  void_89->setTailCall(true);
  AttrListPtr void_89_PAL;
  {
   SmallVector<AttributeWithIndex, 4> Attrs;
   AttributeWithIndex PAWI;
   PAWI.Index = 4294967295U; PAWI.Attrs = 0  | Attribute::NoReturn;
   Attrs.push_back(PAWI);
   void_89_PAL = AttrListPtr::get(Attrs.begin(), Attrs.end());
   
  }
  void_89->setAttributes(void_89_PAL);
  
  new UnreachableInst(mod->getContext(), label_76);
  
  // Block _ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit (label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit)
  std::vector<Value*> ptr_91_indices;
  ptr_91_indices.push_back(const_int32_60);
  ptr_91_indices.push_back(const_int32_67);
  Instruction* ptr_91 = GetElementPtrInst::Create(ptr_86, ptr_91_indices, "", label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit);
  LoadInst* int8_92 = new LoadInst(ptr_91, "", false, label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit);
  int8_92->setAlignment(1);
  ICmpInst* int1_93 = new ICmpInst(*label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit, ICmpInst::ICMP_EQ, int8_92, const_int8_68, "");
  BranchInst::Create(label_78, label_77, int1_93, label__ZSt13__check_facetISt5ctypeIcEERKT_PS3__exit);
  
  // Block  (label_77)
  std::vector<Value*> ptr_95_indices;
  ptr_95_indices.push_back(const_int32_60);
  ptr_95_indices.push_back(const_int32_69);
  ptr_95_indices.push_back(const_int32_70);
  Instruction* ptr_95 = GetElementPtrInst::Create(ptr_86, ptr_95_indices, "", label_77);
  LoadInst* int8_96 = new LoadInst(ptr_95, "", false, label_77);
  int8_96->setAlignment(1);
  BranchInst::Create(label__ZNKSt5ctypeIcE5widenEc_exit, label_77);
  
  // Block  (label_78)
  CallInst* void_98 = CallInst::Create(func__ZNKSt5ctypeIcE13_M_widen_initEv, ptr_86, "", label_78);
  void_98->setCallingConv(CallingConv::C);
  void_98->setTailCall(true);
  AttrListPtr void_98_PAL;
  void_98->setAttributes(void_98_PAL);
  
  CastInst* ptr_99 = new BitCastInst(ptr_86, PointerTy_44, "", label_78);
  LoadInst* ptr_100 = new LoadInst(ptr_99, "", false, label_78);
  ptr_100->setAlignment(4);
  GetElementPtrInst* ptr_101 = GetElementPtrInst::Create(ptr_100, const_int32_67, "", label_78);
  LoadInst* ptr_102 = new LoadInst(ptr_101, "", false, label_78);
  ptr_102->setAlignment(4);
  std::vector<Value*> int8_103_params;
  int8_103_params.push_back(ptr_86);
  int8_103_params.push_back(const_int8_71);
  CallInst* int8_103 = CallInst::Create(ptr_102, int8_103_params, "", label_78);
  int8_103->setCallingConv(CallingConv::C);
  int8_103->setTailCall(true);
  AttrListPtr int8_103_PAL;
  {
   SmallVector<AttributeWithIndex, 4> Attrs;
   AttributeWithIndex PAWI;
   PAWI.Index = 0U; PAWI.Attrs = 0  | Attribute::SExt;
   Attrs.push_back(PAWI);
   PAWI.Index = 2U; PAWI.Attrs = 0  | Attribute::SExt;
   Attrs.push_back(PAWI);
   int8_103_PAL = AttrListPtr::get(Attrs.begin(), Attrs.end());
   
  }
  int8_103->setAttributes(int8_103_PAL);
  
  BranchInst::Create(label__ZNKSt5ctypeIcE5widenEc_exit, label_78);
  
  // Block _ZNKSt5ctypeIcE5widenEc.exit (label__ZNKSt5ctypeIcE5widenEc_exit)
  PHINode* int8__0_i = PHINode::Create(IntegerType::get(mod->getContext(), 8), 2, ".0.i", label__ZNKSt5ctypeIcE5widenEc_exit);
  int8__0_i->addIncoming(int8_96, label_77);
  int8__0_i->addIncoming(int8_103, label_78);
  
  std::vector<Value*> ptr_105_params;
  ptr_105_params.push_back(gvar_struct__ZSt4cout);
  ptr_105_params.push_back(int8__0_i);
  CallInst* ptr_105 = CallInst::Create(func__ZNSo3putEc, ptr_105_params, "", label__ZNKSt5ctypeIcE5widenEc_exit);
  ptr_105->setCallingConv(CallingConv::C);
  ptr_105->setTailCall(true);
  AttrListPtr ptr_105_PAL;
  {
   SmallVector<AttributeWithIndex, 4> Attrs;
   AttributeWithIndex PAWI;
   PAWI.Index = 2U; PAWI.Attrs = 0  | Attribute::SExt;
   Attrs.push_back(PAWI);
   ptr_105_PAL = AttrListPtr::get(Attrs.begin(), Attrs.end());
   
  }
  ptr_105->setAttributes(ptr_105_PAL);
  
  CallInst* ptr_106 = CallInst::Create(func__ZNSo5flushEv, ptr_105, "", label__ZNKSt5ctypeIcE5widenEc_exit);
  ptr_106->setCallingConv(CallingConv::C);
  ptr_106->setTailCall(true);
  AttrListPtr ptr_106_PAL;
  ptr_106->setAttributes(ptr_106_PAL);
  
  ReturnInst::Create(mod->getContext(), const_int32_60, label__ZNKSt5ctypeIcE5widenEc_exit);
  
 }
 
 // Function: _GLOBAL__I_a (func__GLOBAL__I_a)
 {
  
  BasicBlock* label_108 = BasicBlock::Create(mod->getContext(), "",func__GLOBAL__I_a,0);
  
  // Block  (label_108)
  CallInst* void_109 = CallInst::Create(func__ZNSt8ios_base4InitC1Ev, gvar_struct__ZStL8__ioinit, "", label_108);
  void_109->setCallingConv(CallingConv::C);
  void_109->setTailCall(true);
  AttrListPtr void_109_PAL;
  void_109->setAttributes(void_109_PAL);
  
  std::vector<Value*> int32_110_params;
  int32_110_params.push_back(const_ptr_72);
  int32_110_params.push_back(const_ptr_73);
  int32_110_params.push_back(const_ptr_74);
  CallInst* int32_110 = CallInst::Create(func___cxa_atexit, int32_110_params, "", label_108);
  int32_110->setCallingConv(CallingConv::C);
  int32_110->setTailCall(true);
  AttrListPtr int32_110_PAL;
  int32_110->setAttributes(int32_110_PAL);
  
  ReturnInst::Create(mod->getContext(), label_108);
  
 }
 
 return mod;
}
