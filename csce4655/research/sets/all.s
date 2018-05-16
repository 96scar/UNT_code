	.file	"all.bc"
	.text
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
.Ltmp1:
	.cfi_startproc
# BB#0:
	subl	$12, %esp
.Ltmp2:
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, (%esp)
	calll	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	$_ZNSt8ios_base4InitD1Ev, (%esp)
	calll	__cxa_atexit
	addl	$12, %esp
	ret
.Ltmp3:
	.size	__cxx_global_var_init, .Ltmp3-__cxx_global_var_init
.Ltmp4:
	.cfi_endproc
.Leh_func_end0:

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp167:
	.cfi_startproc
	.cfi_personality 0, __gxx_personality_v0
.Leh_func_begin1:
	.cfi_lsda 0, .Lexception1
# BB#0:
	pushl	%ebp
.Ltmp168:
	.cfi_def_cfa_offset 8
	pushl	%ebx
.Ltmp169:
	.cfi_def_cfa_offset 12
	pushl	%edi
.Ltmp170:
	.cfi_def_cfa_offset 16
	pushl	%esi
.Ltmp171:
	.cfi_def_cfa_offset 20
	subl	$172, %esp
.Ltmp172:
	.cfi_def_cfa_offset 192
.Ltmp173:
	.cfi_offset %esi, -20
.Ltmp174:
	.cfi_offset %edi, -16
.Ltmp175:
	.cfi_offset %ebx, -12
.Ltmp176:
	.cfi_offset %ebp, -8
	movl	$0, 168(%esp)
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	calll	_ZN3SetC1Ev
.Ltmp5:
	leal	136(%esp), %esi
	movl	%esi, (%esp)
	calll	_ZN3SetC1Ev
.Ltmp6:
# BB#1:
.Ltmp7:
	leal	112(%esp), %edi
	movl	%edi, (%esp)
	calll	_ZN3SetC1Ev
.Ltmp8:
# BB#2:
.Ltmp9:
	leal	96(%esp), %ebx
	movl	%ebx, (%esp)
	calll	_ZN3SetC1Ev
.Ltmp10:
# BB#3:
.Ltmp11:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp12:
# BB#4:
.Ltmp13:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp14:
# BB#5:
.Ltmp15:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$2, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp16:
# BB#6:
.Ltmp17:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$48, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp18:
# BB#7:
.Ltmp19:
	movl	$.L.str, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp20:
# BB#8:
.Ltmp21:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp22:
# BB#9:
.Ltmp23:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 4(%esp)
	calll	_ZN3Set6removeEi
.Ltmp24:
# BB#10:
.Ltmp25:
	movl	$.L.str, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp26:
# BB#11:
.Ltmp27:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp28:
# BB#12:
.Ltmp29:
	movl	%esi, (%esp)
	movl	$27, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp30:
# BB#13:
.Ltmp31:
	movl	%esi, (%esp)
	movl	$0, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp32:
# BB#14:
.Ltmp33:
	movl	%esi, (%esp)
	movl	$109, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp34:
# BB#15:
.Ltmp35:
	movl	%esi, (%esp)
	movl	$2, 4(%esp)
	calll	_ZN3Set3addEi
.Ltmp36:
# BB#16:
.Ltmp37:
	movl	$.L.str1, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp38:
# BB#17:
.Ltmp39:
	movl	%esi, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp40:
# BB#18:
.Ltmp41:
	movl	%esi, (%esp)
	movl	$109, 4(%esp)
	calll	_ZN3Set6removeEi
.Ltmp42:
# BB#19:
.Ltmp43:
	movl	$.L.str1, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp44:
# BB#20:
.Ltmp45:
	movl	%esi, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp46:
# BB#21:
.Ltmp47:
	movl	%esi, 8(%esp)
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	leal	72(%esp), %ebp
	movl	%ebp, (%esp)
	calll	_ZN3SetanERKS_
	subl	$4, %esp
.Ltmp48:
# BB#22:
.Ltmp49:
	movl	%ebp, 4(%esp)
	movl	%edi, (%esp)
	calll	_ZN3SetaSERKS_
.Ltmp50:
# BB#23:
.Ltmp54:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp55:
# BB#24:
.Ltmp56:
	movl	$.L.str2, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp57:
# BB#25:
.Ltmp58:
	movl	%edi, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp59:
# BB#26:
.Ltmp60:
	movl	%esi, 8(%esp)
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	leal	56(%esp), %ebp
	movl	%ebp, (%esp)
	calll	_ZN3SetorERKS_
	subl	$4, %esp
.Ltmp61:
# BB#27:
.Ltmp62:
	movl	%ebp, 4(%esp)
	movl	%ebx, (%esp)
	calll	_ZN3SetaSERKS_
.Ltmp63:
# BB#28:
.Ltmp67:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp68:
# BB#29:
.Ltmp69:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp70:
# BB#30:
.Ltmp71:
	movl	%eax, (%esp)
	movl	$.L.str3, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp72:
# BB#31:
.Ltmp73:
	movl	%ebx, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp74:
# BB#32:
.Ltmp75:
	movl	%esi, 8(%esp)
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	leal	40(%esp), %ebp
	movl	%ebp, (%esp)
	calll	_ZN3SeteoERKS_
	subl	$4, %esp
.Ltmp76:
# BB#33:
.Ltmp77:
	movl	%ebp, 4(%esp)
	movl	%edi, (%esp)
	calll	_ZN3SetaSERKS_
.Ltmp78:
# BB#34:
.Ltmp82:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp83:
# BB#35:
.Ltmp84:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp85:
# BB#36:
.Ltmp86:
	movl	%eax, (%esp)
	movl	$.L.str4, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp87:
# BB#37:
.Ltmp88:
	movl	%edi, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp89:
# BB#38:
.Ltmp90:
	movl	%esi, 8(%esp)
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %ebp
	movl	%ebp, (%esp)
	calll	_ZN3SetmiERKS_
	subl	$4, %esp
.Ltmp91:
# BB#39:
.Ltmp92:
	movl	%ebp, 4(%esp)
	movl	%edi, (%esp)
	calll	_ZN3SetaSERKS_
.Ltmp93:
# BB#40:
.Ltmp97:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp98:
# BB#41:
.Ltmp99:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp100:
# BB#42:
.Ltmp101:
	movl	%eax, (%esp)
	movl	$.L.str5, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp102:
# BB#43:
.Ltmp103:
	movl	%edi, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp104:
# BB#44:
.Ltmp105:
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	calll	_ZN3SetaSERKS_
.Ltmp106:
# BB#45:
.Ltmp107:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp108:
# BB#46:
.Ltmp109:
	movl	%eax, (%esp)
	movl	$.L.str6, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp110:
# BB#47:
.Ltmp111:
	movl	%ebx, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp112:
# BB#48:
.Ltmp113:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp114:
# BB#49:
.Ltmp115:
	movl	%eax, (%esp)
	movl	$.L.str7, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp116:
# BB#50:
.Ltmp117:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	calll	_ZN3Set8printSetEv
.Ltmp118:
# BB#51:
.Ltmp119:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$2, 4(%esp)
	calll	_ZN3Set9is_memberEi
.Ltmp120:
# BB#52:
	movl	%eax, 92(%esp)
	testl	%eax, %eax
	je	.LBB1_61
# BB#53:
.Ltmp127:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp128:
# BB#54:
.Ltmp129:
	movl	%eax, (%esp)
	movl	$.L.str8, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp130:
# BB#55:
.Ltmp131:
	movl	%eax, (%esp)
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp132:
	jmp	.LBB1_64
.LBB1_56:
.Ltmp158:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
	jmp	.LBB1_79
.LBB1_57:
.Ltmp51:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.Ltmp52:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp53:
	jmp	.LBB1_74
.LBB1_58:
.Ltmp64:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.Ltmp65:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp66:
	jmp	.LBB1_74
.LBB1_59:
.Ltmp79:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.Ltmp80:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp81:
	jmp	.LBB1_74
.LBB1_60:
.Ltmp94:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.Ltmp95:
	movl	%ebp, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp96:
	jmp	.LBB1_74
.LBB1_61:
.Ltmp121:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp122:
# BB#62:
.Ltmp123:
	movl	%eax, (%esp)
	movl	$.L.str9, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp124:
# BB#63:
.Ltmp125:
	movl	%eax, (%esp)
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp126:
.LBB1_64:
.Ltmp133:
	movl	%ebx, (%esp)
	calll	_ZN3Set4sizeEv
.Ltmp134:
# BB#65:
	movl	%eax, 88(%esp)
.Ltmp135:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp136:
# BB#66:
.Ltmp137:
	movl	%eax, (%esp)
	movl	$.L.str10, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.Ltmp138:
# BB#67:
	movl	88(%esp), %ecx
.Ltmp139:
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	calll	_ZNSolsEi
.Ltmp140:
# BB#68:
.Ltmp141:
	movl	%eax, (%esp)
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	calll	_ZNSolsEPFRSoS_E
.Ltmp142:
# BB#69:
	movl	$0, 168(%esp)
	movl	$1, 20(%esp)
.Ltmp146:
	movl	%ebx, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp147:
# BB#70:
.Ltmp151:
	movl	%edi, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp152:
# BB#71:
.Ltmp156:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp157:
# BB#72:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	calll	_ZN3SetD1Ev
	movl	168(%esp), %eax
	addl	$172, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	ret
.LBB1_73:
.Ltmp143:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.LBB1_74:
.Ltmp144:
	movl	%ebx, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp145:
	jmp	.LBB1_76
.LBB1_75:
.Ltmp148:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.LBB1_76:
.Ltmp149:
	movl	%edi, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp150:
	jmp	.LBB1_78
.LBB1_77:
.Ltmp153:
	movl	%eax, 132(%esp)
	movl	%edx, 128(%esp)
.LBB1_78:
.Ltmp154:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp155:
.LBB1_79:
.Ltmp159:
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	calll	_ZN3SetD1Ev
.Ltmp160:
# BB#80:
	movl	132(%esp), %eax
	movl	%eax, (%esp)
	calll	_Unwind_Resume
.LBB1_81:
.Ltmp161:
	calll	_ZSt9terminatev
.Ltmp177:
	.size	main, .Ltmp177-main
.Ltmp178:
	.cfi_endproc
.Leh_func_end1:
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table1:
.Lexception1:
	.byte	255                     # @LPStart Encoding = omit
	.byte	0                       # @TType Encoding = absptr
	.byte	154                     # @TType base offset
	.byte	130
	.zero	1,128
	.zero	1
	.byte	3                       # Call site Encoding = udata4
	.ascii	 "\221\002"             # Call site table length
.Lset0 = .Leh_func_begin1-.Leh_func_begin1 # >> Call Site 1 <<
	.long	.Lset0
.Lset1 = .Ltmp5-.Leh_func_begin1        #   Call between .Leh_func_begin1 and .Ltmp5
	.long	.Lset1
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lset2 = .Ltmp5-.Leh_func_begin1        # >> Call Site 2 <<
	.long	.Lset2
.Lset3 = .Ltmp6-.Ltmp5                  #   Call between .Ltmp5 and .Ltmp6
	.long	.Lset3
.Lset4 = .Ltmp158-.Leh_func_begin1      #     jumps to .Ltmp158
	.long	.Lset4
	.byte	0                       #   On action: cleanup
.Lset5 = .Ltmp7-.Leh_func_begin1        # >> Call Site 3 <<
	.long	.Lset5
.Lset6 = .Ltmp8-.Ltmp7                  #   Call between .Ltmp7 and .Ltmp8
	.long	.Lset6
.Lset7 = .Ltmp153-.Leh_func_begin1      #     jumps to .Ltmp153
	.long	.Lset7
	.byte	0                       #   On action: cleanup
.Lset8 = .Ltmp9-.Leh_func_begin1        # >> Call Site 4 <<
	.long	.Lset8
.Lset9 = .Ltmp10-.Ltmp9                 #   Call between .Ltmp9 and .Ltmp10
	.long	.Lset9
.Lset10 = .Ltmp148-.Leh_func_begin1     #     jumps to .Ltmp148
	.long	.Lset10
	.byte	0                       #   On action: cleanup
.Lset11 = .Ltmp11-.Leh_func_begin1      # >> Call Site 5 <<
	.long	.Lset11
.Lset12 = .Ltmp48-.Ltmp11               #   Call between .Ltmp11 and .Ltmp48
	.long	.Lset12
.Lset13 = .Ltmp143-.Leh_func_begin1     #     jumps to .Ltmp143
	.long	.Lset13
	.byte	0                       #   On action: cleanup
.Lset14 = .Ltmp49-.Leh_func_begin1      # >> Call Site 6 <<
	.long	.Lset14
.Lset15 = .Ltmp50-.Ltmp49               #   Call between .Ltmp49 and .Ltmp50
	.long	.Lset15
.Lset16 = .Ltmp51-.Leh_func_begin1      #     jumps to .Ltmp51
	.long	.Lset16
	.byte	0                       #   On action: cleanup
.Lset17 = .Ltmp54-.Leh_func_begin1      # >> Call Site 7 <<
	.long	.Lset17
.Lset18 = .Ltmp61-.Ltmp54               #   Call between .Ltmp54 and .Ltmp61
	.long	.Lset18
.Lset19 = .Ltmp143-.Leh_func_begin1     #     jumps to .Ltmp143
	.long	.Lset19
	.byte	0                       #   On action: cleanup
.Lset20 = .Ltmp62-.Leh_func_begin1      # >> Call Site 8 <<
	.long	.Lset20
.Lset21 = .Ltmp63-.Ltmp62               #   Call between .Ltmp62 and .Ltmp63
	.long	.Lset21
.Lset22 = .Ltmp64-.Leh_func_begin1      #     jumps to .Ltmp64
	.long	.Lset22
	.byte	0                       #   On action: cleanup
.Lset23 = .Ltmp67-.Leh_func_begin1      # >> Call Site 9 <<
	.long	.Lset23
.Lset24 = .Ltmp76-.Ltmp67               #   Call between .Ltmp67 and .Ltmp76
	.long	.Lset24
.Lset25 = .Ltmp143-.Leh_func_begin1     #     jumps to .Ltmp143
	.long	.Lset25
	.byte	0                       #   On action: cleanup
.Lset26 = .Ltmp77-.Leh_func_begin1      # >> Call Site 10 <<
	.long	.Lset26
.Lset27 = .Ltmp78-.Ltmp77               #   Call between .Ltmp77 and .Ltmp78
	.long	.Lset27
.Lset28 = .Ltmp79-.Leh_func_begin1      #     jumps to .Ltmp79
	.long	.Lset28
	.byte	0                       #   On action: cleanup
.Lset29 = .Ltmp82-.Leh_func_begin1      # >> Call Site 11 <<
	.long	.Lset29
.Lset30 = .Ltmp91-.Ltmp82               #   Call between .Ltmp82 and .Ltmp91
	.long	.Lset30
.Lset31 = .Ltmp143-.Leh_func_begin1     #     jumps to .Ltmp143
	.long	.Lset31
	.byte	0                       #   On action: cleanup
.Lset32 = .Ltmp92-.Leh_func_begin1      # >> Call Site 12 <<
	.long	.Lset32
.Lset33 = .Ltmp93-.Ltmp92               #   Call between .Ltmp92 and .Ltmp93
	.long	.Lset33
.Lset34 = .Ltmp94-.Leh_func_begin1      #     jumps to .Ltmp94
	.long	.Lset34
	.byte	0                       #   On action: cleanup
.Lset35 = .Ltmp97-.Leh_func_begin1      # >> Call Site 13 <<
	.long	.Lset35
.Lset36 = .Ltmp132-.Ltmp97              #   Call between .Ltmp97 and .Ltmp132
	.long	.Lset36
.Lset37 = .Ltmp143-.Leh_func_begin1     #     jumps to .Ltmp143
	.long	.Lset37
	.byte	0                       #   On action: cleanup
.Lset38 = .Ltmp52-.Leh_func_begin1      # >> Call Site 14 <<
	.long	.Lset38
.Lset39 = .Ltmp96-.Ltmp52               #   Call between .Ltmp52 and .Ltmp96
	.long	.Lset39
.Lset40 = .Ltmp161-.Leh_func_begin1     #     jumps to .Ltmp161
	.long	.Lset40
	.byte	1                       #   On action: 1
.Lset41 = .Ltmp121-.Leh_func_begin1     # >> Call Site 15 <<
	.long	.Lset41
.Lset42 = .Ltmp142-.Ltmp121             #   Call between .Ltmp121 and .Ltmp142
	.long	.Lset42
.Lset43 = .Ltmp143-.Leh_func_begin1     #     jumps to .Ltmp143
	.long	.Lset43
	.byte	0                       #   On action: cleanup
.Lset44 = .Ltmp146-.Leh_func_begin1     # >> Call Site 16 <<
	.long	.Lset44
.Lset45 = .Ltmp147-.Ltmp146             #   Call between .Ltmp146 and .Ltmp147
	.long	.Lset45
.Lset46 = .Ltmp148-.Leh_func_begin1     #     jumps to .Ltmp148
	.long	.Lset46
	.byte	0                       #   On action: cleanup
.Lset47 = .Ltmp151-.Leh_func_begin1     # >> Call Site 17 <<
	.long	.Lset47
.Lset48 = .Ltmp152-.Ltmp151             #   Call between .Ltmp151 and .Ltmp152
	.long	.Lset48
.Lset49 = .Ltmp153-.Leh_func_begin1     #     jumps to .Ltmp153
	.long	.Lset49
	.byte	0                       #   On action: cleanup
.Lset50 = .Ltmp156-.Leh_func_begin1     # >> Call Site 18 <<
	.long	.Lset50
.Lset51 = .Ltmp157-.Ltmp156             #   Call between .Ltmp156 and .Ltmp157
	.long	.Lset51
.Lset52 = .Ltmp158-.Leh_func_begin1     #     jumps to .Ltmp158
	.long	.Lset52
	.byte	0                       #   On action: cleanup
.Lset53 = .Ltmp157-.Leh_func_begin1     # >> Call Site 19 <<
	.long	.Lset53
.Lset54 = .Ltmp144-.Ltmp157             #   Call between .Ltmp157 and .Ltmp144
	.long	.Lset54
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lset55 = .Ltmp144-.Leh_func_begin1     # >> Call Site 20 <<
	.long	.Lset55
.Lset56 = .Ltmp160-.Ltmp144             #   Call between .Ltmp144 and .Ltmp160
	.long	.Lset56
.Lset57 = .Ltmp161-.Leh_func_begin1     #     jumps to .Ltmp161
	.long	.Lset57
	.byte	1                       #   On action: 1
.Lset58 = .Ltmp160-.Leh_func_begin1     # >> Call Site 21 <<
	.long	.Lset58
.Lset59 = .Leh_func_end1-.Ltmp160       #   Call between .Ltmp160 and .Leh_func_end1
	.long	.Lset59
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.byte	1                       # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                       #   No further actions
                                        # >> Catch TypeInfos <<
	.long	0                       # TypeInfo 1
	.align	4

	.text
	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
.Ltmp180:
	.cfi_startproc
# BB#0:
	subl	$12, %esp
.Ltmp181:
	.cfi_def_cfa_offset 16
	calll	__cxx_global_var_init
	addl	$12, %esp
	ret
.Ltmp182:
	.size	_GLOBAL__I_a, .Ltmp182-_GLOBAL__I_a
.Ltmp183:
	.cfi_endproc
.Leh_func_end2:

	.align	16, 0x90
	.type	__cxx_global_var_init15,@function
__cxx_global_var_init15:                # @__cxx_global_var_init15
.Ltmp185:
	.cfi_startproc
# BB#0:
	subl	$12, %esp
.Ltmp186:
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit1, (%esp)
	calll	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit1, 4(%esp)
	movl	$_ZNSt8ios_base4InitD1Ev, (%esp)
	calll	__cxa_atexit
	addl	$12, %esp
	ret
.Ltmp187:
	.size	__cxx_global_var_init15, .Ltmp187-__cxx_global_var_init15
.Ltmp188:
	.cfi_endproc
.Leh_func_end3:

	.globl	_ZN3SetC2Ev
	.align	16, 0x90
	.type	_ZN3SetC2Ev,@function
_ZN3SetC2Ev:                            # @_ZN3SetC2Ev
# BB#0:
	subl	$8, %esp
	movl	12(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	jmp	.LBB4_1
	.align	16, 0x90
.LBB4_2:                                #   in Loop: Header=BB4_1 Depth=1
	movl	(%esp), %ecx
	movl	$0, (%eax,%ecx,4)
	incl	(%esp)
.LBB4_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$3, (%esp)
	jle	.LBB4_2
# BB#3:
	addl	$8, %esp
	ret
.Ltmp189:
	.size	_ZN3SetC2Ev, .Ltmp189-_ZN3SetC2Ev

	.globl	_ZN3SetC2ERKS_
	.align	16, 0x90
	.type	_ZN3SetC2ERKS_,@function
_ZN3SetC2ERKS_:                         # @_ZN3SetC2ERKS_
# BB#0:
	subl	$8, %esp
	movl	12(%esp), %eax
	movl	%eax, 4(%esp)
	movl	16(%esp), %eax
	movl	%eax, (%esp)
	addl	$8, %esp
	ret
.Ltmp190:
	.size	_ZN3SetC2ERKS_, .Ltmp190-_ZN3SetC2ERKS_

	.globl	_ZN3SetD2Ev
	.align	16, 0x90
	.type	_ZN3SetD2Ev,@function
_ZN3SetD2Ev:                            # @_ZN3SetD2Ev
# BB#0:
	pushl	%eax
	movl	8(%esp), %eax
	movl	%eax, (%esp)
	popl	%eax
	ret
.Ltmp191:
	.size	_ZN3SetD2Ev, .Ltmp191-_ZN3SetD2Ev

	.globl	_ZN3Set3addEi
	.align	16, 0x90
	.type	_ZN3Set3addEi,@function
_ZN3Set3addEi:                          # @_ZN3Set3addEi
# BB#0:
	subl	$20, %esp
	movl	24(%esp), %eax
	movl	%eax, 16(%esp)
	movl	28(%esp), %eax
	movl	%eax, 12(%esp)
	movl	%eax, %ecx
	sarl	$31, %ecx
	shrl	$27, %ecx
	addl	%eax, %ecx
	sarl	$5, %ecx
	movl	16(%esp), %eax
	movl	%ecx, (%esp)
	movl	12(%esp), %ecx
	movl	%ecx, %edx
	sarl	$31, %edx
	shrl	$27, %edx
	addl	%ecx, %edx
	andl	$-32, %edx
	subl	%edx, %ecx
	movl	%ecx, 4(%esp)
	movb	4(%esp), %cl
	movl	$1, %edx
	shll	%cl, %edx
	movl	%edx, 8(%esp)
	movl	(%esp), %ecx
	orl	%edx, (%eax,%ecx,4)
	addl	$20, %esp
	ret
.Ltmp192:
	.size	_ZN3Set3addEi, .Ltmp192-_ZN3Set3addEi

	.globl	_ZN3Set6removeEi
	.align	16, 0x90
	.type	_ZN3Set6removeEi,@function
_ZN3Set6removeEi:                       # @_ZN3Set6removeEi
# BB#0:
	subl	$20, %esp
	movl	24(%esp), %eax
	movl	%eax, 16(%esp)
	movl	28(%esp), %eax
	movl	%eax, 12(%esp)
	movl	%eax, %ecx
	sarl	$31, %ecx
	shrl	$27, %ecx
	addl	%eax, %ecx
	sarl	$5, %ecx
	movl	16(%esp), %eax
	movl	%ecx, (%esp)
	movl	12(%esp), %ecx
	movl	%ecx, %edx
	sarl	$31, %edx
	shrl	$27, %edx
	addl	%ecx, %edx
	andl	$-32, %edx
	subl	%edx, %ecx
	movl	%ecx, 4(%esp)
	movb	4(%esp), %cl
	movl	$1, %edx
	shll	%cl, %edx
	movl	%edx, 8(%esp)
	notl	%edx
	movl	(%esp), %ecx
	andl	%edx, (%eax,%ecx,4)
	addl	$20, %esp
	ret
.Ltmp193:
	.size	_ZN3Set6removeEi, .Ltmp193-_ZN3Set6removeEi

	.globl	_ZN3Set4sizeEv
	.align	16, 0x90
	.type	_ZN3Set4sizeEv,@function
_ZN3Set4sizeEv:                         # @_ZN3Set4sizeEv
# BB#0:
	pushl	%edi
	pushl	%esi
	subl	$20, %esp
	movl	32(%esp), %edx
	movl	%edx, 16(%esp)
	movl	$0, (%esp)
	movl	$0, 8(%esp)
	jmp	.LBB9_1
	.align	16, 0x90
.LBB9_4:                                #   in Loop: Header=BB9_3 Depth=2
	movl	8(%esp), %eax
	movl	(%edx,%eax,4), %esi
	movl	4(%esp), %eax
	movb	%al, %cl
	movl	%esi, %edi
	shrl	%cl, %edi
	movl	%edi, 12(%esp)
	andl	$1, %edi
	movl	%edi, 12(%esp)
	btl	%eax, %esi
	jae	.LBB9_6
# BB#5:                                 #   in Loop: Header=BB9_3 Depth=2
	incl	(%esp)
.LBB9_6:                                #   in Loop: Header=BB9_3 Depth=2
	incl	4(%esp)
.LBB9_3:                                #   Parent Loop BB9_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$31, 4(%esp)
	jle	.LBB9_4
# BB#7:                                 #   in Loop: Header=BB9_1 Depth=1
	incl	8(%esp)
.LBB9_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB9_3 Depth 2
	cmpl	$3, 8(%esp)
	jg	.LBB9_8
# BB#2:                                 #   in Loop: Header=BB9_1 Depth=1
	movl	$0, 4(%esp)
	jmp	.LBB9_3
.LBB9_8:
	movl	(%esp), %eax
	addl	$20, %esp
	popl	%esi
	popl	%edi
	ret
.Ltmp194:
	.size	_ZN3Set4sizeEv, .Ltmp194-_ZN3Set4sizeEv

	.globl	_ZN3Set9is_memberEi
	.align	16, 0x90
	.type	_ZN3Set9is_memberEi,@function
_ZN3Set9is_memberEi:                    # @_ZN3Set9is_memberEi
# BB#0:
	pushl	%esi
	subl	$24, %esp
	movl	32(%esp), %eax
	movl	%eax, 16(%esp)
	movl	36(%esp), %eax
	movl	%eax, 12(%esp)
	movl	%eax, %ecx
	sarl	$31, %ecx
	shrl	$27, %ecx
	addl	%eax, %ecx
	sarl	$5, %ecx
	movl	16(%esp), %eax
	movl	%ecx, 4(%esp)
	movl	12(%esp), %ecx
	movl	%ecx, %edx
	sarl	$31, %edx
	shrl	$27, %edx
	addl	%ecx, %edx
	andl	$-32, %edx
	subl	%edx, %ecx
	movl	%ecx, 8(%esp)
	movl	4(%esp), %ecx
	movl	(%eax,%ecx,4), %edx
	movl	8(%esp), %eax
	movb	%al, %cl
	movl	%edx, %esi
	shrl	%cl, %esi
	movl	%esi, (%esp)
	andl	$1, %esi
	movl	%esi, (%esp)
	btl	%eax, %edx
	jae	.LBB10_2
# BB#1:
	movl	$1, 20(%esp)
	jmp	.LBB10_3
.LBB10_2:
	movl	$0, 20(%esp)
.LBB10_3:
	movl	20(%esp), %eax
	addl	$24, %esp
	popl	%esi
	ret
.Ltmp195:
	.size	_ZN3Set9is_memberEi, .Ltmp195-_ZN3Set9is_memberEi

	.globl	_ZN3SetaSERKS_
	.align	16, 0x90
	.type	_ZN3SetaSERKS_,@function
_ZN3SetaSERKS_:                         # @_ZN3SetaSERKS_
.Ltmp199:
	.cfi_startproc
# BB#0:
	pushl	%edi
.Ltmp200:
	.cfi_def_cfa_offset 8
	pushl	%esi
.Ltmp201:
	.cfi_def_cfa_offset 12
	subl	$36, %esp
.Ltmp202:
	.cfi_def_cfa_offset 48
.Ltmp203:
	.cfi_offset %esi, -12
.Ltmp204:
	.cfi_offset %edi, -8
	movl	48(%esp), %eax
	movl	%eax, 32(%esp)
	movl	52(%esp), %eax
	movl	%eax, 28(%esp)
	movl	32(%esp), %edi
	leal	8(%esp), %esi
	movl	%esi, (%esp)
	calll	_ZN3SetC1Ev
	movl	$0, 4(%esp)
	jmp	.LBB11_1
	.align	16, 0x90
.LBB11_2:                               #   in Loop: Header=BB11_1 Depth=1
	movl	4(%esp), %ecx
	movl	28(%esp), %eax
	movl	(%eax,%ecx,4), %eax
	movl	%eax, (%edi,%ecx,4)
	movl	4(%esp), %ecx
	movl	%eax, 8(%esp,%ecx,4)
	incl	4(%esp)
.LBB11_1:                               # =>This Inner Loop Header: Depth=1
	cmpl	$3, 4(%esp)
	jle	.LBB11_2
# BB#3:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
	addl	$36, %esp
	popl	%esi
	popl	%edi
	ret
.Ltmp205:
	.size	_ZN3SetaSERKS_, .Ltmp205-_ZN3SetaSERKS_
.Ltmp206:
	.cfi_endproc
.Leh_func_end11:

	.globl	_ZN3SetanERKS_
	.align	16, 0x90
	.type	_ZN3SetanERKS_,@function
_ZN3SetanERKS_:                         # @_ZN3SetanERKS_
.Ltmp210:
	.cfi_startproc
# BB#0:
	pushl	%edi
.Ltmp211:
	.cfi_def_cfa_offset 8
	pushl	%esi
.Ltmp212:
	.cfi_def_cfa_offset 12
	subl	$36, %esp
.Ltmp213:
	.cfi_def_cfa_offset 48
.Ltmp214:
	.cfi_offset %esi, -12
.Ltmp215:
	.cfi_offset %edi, -8
	movl	52(%esp), %eax
	movl	%eax, 32(%esp)
	movl	56(%esp), %eax
	movl	%eax, 28(%esp)
	movl	32(%esp), %edi
	movb	$0, 27(%esp)
	movl	48(%esp), %esi
	movl	%esi, (%esp)
	calll	_ZN3SetC1Ev
	movl	$0, 20(%esp)
	jmp	.LBB12_1
	.align	16, 0x90
.LBB12_2:                               #   in Loop: Header=BB12_1 Depth=1
	movl	20(%esp), %eax
	movl	(%edi,%eax,4), %ecx
	movl	28(%esp), %edx
	andl	(%edx,%eax,4), %ecx
	movl	%ecx, (%esi,%eax,4)
	incl	20(%esp)
.LBB12_1:                               # =>This Inner Loop Header: Depth=1
	cmpl	$3, 20(%esp)
	jle	.LBB12_2
# BB#3:
	movb	$1, 27(%esp)
	movl	$1, 16(%esp)
	movb	27(%esp), %al
	testb	%al, %al
	jne	.LBB12_5
# BB#4:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
.LBB12_5:
	addl	$36, %esp
	popl	%esi
	popl	%edi
	ret	$4
.Ltmp216:
	.size	_ZN3SetanERKS_, .Ltmp216-_ZN3SetanERKS_
.Ltmp217:
	.cfi_endproc
.Leh_func_end12:

	.globl	_ZN3SetorERKS_
	.align	16, 0x90
	.type	_ZN3SetorERKS_,@function
_ZN3SetorERKS_:                         # @_ZN3SetorERKS_
.Ltmp221:
	.cfi_startproc
# BB#0:
	pushl	%edi
.Ltmp222:
	.cfi_def_cfa_offset 8
	pushl	%esi
.Ltmp223:
	.cfi_def_cfa_offset 12
	subl	$36, %esp
.Ltmp224:
	.cfi_def_cfa_offset 48
.Ltmp225:
	.cfi_offset %esi, -12
.Ltmp226:
	.cfi_offset %edi, -8
	movl	52(%esp), %eax
	movl	%eax, 32(%esp)
	movl	56(%esp), %eax
	movl	%eax, 28(%esp)
	movl	32(%esp), %edi
	movb	$0, 27(%esp)
	movl	48(%esp), %esi
	movl	%esi, (%esp)
	calll	_ZN3SetC1Ev
	movl	$0, 20(%esp)
	jmp	.LBB13_1
	.align	16, 0x90
.LBB13_2:                               #   in Loop: Header=BB13_1 Depth=1
	movl	20(%esp), %eax
	movl	(%edi,%eax,4), %ecx
	movl	28(%esp), %edx
	orl	(%edx,%eax,4), %ecx
	movl	%ecx, (%esi,%eax,4)
	incl	20(%esp)
.LBB13_1:                               # =>This Inner Loop Header: Depth=1
	cmpl	$3, 20(%esp)
	jle	.LBB13_2
# BB#3:
	movb	$1, 27(%esp)
	movl	$1, 16(%esp)
	movb	27(%esp), %al
	testb	%al, %al
	jne	.LBB13_5
# BB#4:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
.LBB13_5:
	addl	$36, %esp
	popl	%esi
	popl	%edi
	ret	$4
.Ltmp227:
	.size	_ZN3SetorERKS_, .Ltmp227-_ZN3SetorERKS_
.Ltmp228:
	.cfi_endproc
.Leh_func_end13:

	.globl	_ZN3SeteoERKS_
	.align	16, 0x90
	.type	_ZN3SeteoERKS_,@function
_ZN3SeteoERKS_:                         # @_ZN3SeteoERKS_
.Ltmp232:
	.cfi_startproc
# BB#0:
	pushl	%edi
.Ltmp233:
	.cfi_def_cfa_offset 8
	pushl	%esi
.Ltmp234:
	.cfi_def_cfa_offset 12
	subl	$36, %esp
.Ltmp235:
	.cfi_def_cfa_offset 48
.Ltmp236:
	.cfi_offset %esi, -12
.Ltmp237:
	.cfi_offset %edi, -8
	movl	52(%esp), %eax
	movl	%eax, 32(%esp)
	movl	56(%esp), %eax
	movl	%eax, 28(%esp)
	movl	32(%esp), %edi
	movb	$0, 27(%esp)
	movl	48(%esp), %esi
	movl	%esi, (%esp)
	calll	_ZN3SetC1Ev
	movl	$0, 20(%esp)
	jmp	.LBB14_1
	.align	16, 0x90
.LBB14_2:                               #   in Loop: Header=BB14_1 Depth=1
	movl	20(%esp), %eax
	movl	(%edi,%eax,4), %ecx
	movl	28(%esp), %edx
	xorl	(%edx,%eax,4), %ecx
	movl	%ecx, (%esi,%eax,4)
	incl	20(%esp)
.LBB14_1:                               # =>This Inner Loop Header: Depth=1
	cmpl	$3, 20(%esp)
	jle	.LBB14_2
# BB#3:
	movb	$1, 27(%esp)
	movl	$1, 16(%esp)
	movb	27(%esp), %al
	testb	%al, %al
	jne	.LBB14_5
# BB#4:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
.LBB14_5:
	addl	$36, %esp
	popl	%esi
	popl	%edi
	ret	$4
.Ltmp238:
	.size	_ZN3SeteoERKS_, .Ltmp238-_ZN3SeteoERKS_
.Ltmp239:
	.cfi_endproc
.Leh_func_end14:

	.globl	_ZN3SetmiERKS_
	.align	16, 0x90
	.type	_ZN3SetmiERKS_,@function
_ZN3SetmiERKS_:                         # @_ZN3SetmiERKS_
.Ltmp243:
	.cfi_startproc
# BB#0:
	pushl	%edi
.Ltmp244:
	.cfi_def_cfa_offset 8
	pushl	%esi
.Ltmp245:
	.cfi_def_cfa_offset 12
	subl	$36, %esp
.Ltmp246:
	.cfi_def_cfa_offset 48
.Ltmp247:
	.cfi_offset %esi, -12
.Ltmp248:
	.cfi_offset %edi, -8
	movl	52(%esp), %eax
	movl	%eax, 32(%esp)
	movl	56(%esp), %eax
	movl	%eax, 28(%esp)
	movl	32(%esp), %edi
	movb	$0, 27(%esp)
	movl	48(%esp), %esi
	movl	%esi, (%esp)
	calll	_ZN3SetC1Ev
	movl	$0, 20(%esp)
	jmp	.LBB15_1
	.align	16, 0x90
.LBB15_2:                               #   in Loop: Header=BB15_1 Depth=1
	movl	20(%esp), %eax
	movl	28(%esp), %ecx
	movl	(%ecx,%eax,4), %ecx
	notl	%ecx
	andl	(%edi,%eax,4), %ecx
	movl	%ecx, (%esi,%eax,4)
	incl	20(%esp)
.LBB15_1:                               # =>This Inner Loop Header: Depth=1
	cmpl	$3, 20(%esp)
	jle	.LBB15_2
# BB#3:
	movb	$1, 27(%esp)
	movl	$1, 16(%esp)
	movb	27(%esp), %al
	testb	%al, %al
	jne	.LBB15_5
# BB#4:
	movl	%esi, (%esp)
	calll	_ZN3SetD1Ev
.LBB15_5:
	addl	$36, %esp
	popl	%esi
	popl	%edi
	ret	$4
.Ltmp249:
	.size	_ZN3SetmiERKS_, .Ltmp249-_ZN3SetmiERKS_
.Ltmp250:
	.cfi_endproc
.Leh_func_end15:

	.globl	_ZN3Set8printSetEv
	.align	16, 0x90
	.type	_ZN3Set8printSetEv,@function
_ZN3Set8printSetEv:                     # @_ZN3Set8printSetEv
.Ltmp254:
	.cfi_startproc
# BB#0:
	pushl	%edi
.Ltmp255:
	.cfi_def_cfa_offset 8
	pushl	%esi
.Ltmp256:
	.cfi_def_cfa_offset 12
	subl	$36, %esp
.Ltmp257:
	.cfi_def_cfa_offset 48
.Ltmp258:
	.cfi_offset %esi, -12
.Ltmp259:
	.cfi_offset %edi, -8
	movl	48(%esp), %esi
	movl	%esi, 32(%esp)
	movl	$.L.str11, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, 24(%esp)
	jmp	.LBB16_1
	.align	16, 0x90
.LBB16_4:                               #   in Loop: Header=BB16_3 Depth=2
	movl	24(%esp), %eax
	movl	(%esi,%eax,4), %edx
	movl	20(%esp), %eax
	movb	%al, %cl
	movl	%edx, %edi
	shrl	%cl, %edi
	movl	%edi, 28(%esp)
	andl	$1, %edi
	movl	%edi, 28(%esp)
	btl	%eax, %edx
	jae	.LBB16_6
# BB#5:                                 #   in Loop: Header=BB16_3 Depth=2
	movl	$.L.str112, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	24(%esp), %edx
	shll	$5, %edx
	movl	20(%esp), %ecx
	addl	%edx, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	calll	_ZNSolsEi
	movl	%eax, (%esp)
	movl	$.L.str112, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.LBB16_6:                               #   in Loop: Header=BB16_3 Depth=2
	incl	20(%esp)
.LBB16_3:                               #   Parent Loop BB16_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$31, 20(%esp)
	jle	.LBB16_4
# BB#7:                                 #   in Loop: Header=BB16_1 Depth=1
	incl	24(%esp)
.LBB16_1:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB16_3 Depth 2
	cmpl	$3, 24(%esp)
	jg	.LBB16_8
# BB#2:                                 #   in Loop: Header=BB16_1 Depth=1
	movl	$0, 20(%esp)
	jmp	.LBB16_3
.LBB16_8:
	movl	$.L.str213, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	calll	_ZNSolsEPFRSoS_E
	addl	$36, %esp
	popl	%esi
	popl	%edi
	ret
.Ltmp260:
	.size	_ZN3Set8printSetEv, .Ltmp260-_ZN3Set8printSetEv
.Ltmp261:
	.cfi_endproc
.Leh_func_end16:

	.align	16, 0x90
	.type	_GLOBAL__I_a36,@function
_GLOBAL__I_a36:                         # @_GLOBAL__I_a36
.Ltmp263:
	.cfi_startproc
# BB#0:
	subl	$12, %esp
.Ltmp264:
	.cfi_def_cfa_offset 16
	calll	__cxx_global_var_init15
	addl	$12, %esp
	ret
.Ltmp265:
	.size	_GLOBAL__I_a36, .Ltmp265-_GLOBAL__I_a36
.Ltmp266:
	.cfi_endproc
.Leh_func_end17:

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "s1 = "
	.size	.L.str, 6

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "s2 = "
	.size	.L.str1, 6

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "\nThe intersection of s1 and s2 is \n"
	.size	.L.str2, 36

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	 "\nThe union of s1 and s2 is \n"
	.size	.L.str3, 29

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	 "Exclusive Or: "
	.size	.L.str4, 15

	.type	.L.str5,@object         # @.str5
.L.str5:
	.asciz	 "set difference: "
	.size	.L.str5, 17

	.type	.L.str6,@object         # @.str6
.L.str6:
	.asciz	 "s4: "
	.size	.L.str6, 5

	.type	.L.str7,@object         # @.str7
.L.str7:
	.asciz	 "s1: "
	.size	.L.str7, 5

	.type	.L.str8,@object         # @.str8
.L.str8:
	.asciz	 "Yes, it's a member"
	.size	.L.str8, 19

	.type	.L.str9,@object         # @.str9
.L.str9:
	.asciz	 "No, it's not a member"
	.size	.L.str9, 22

	.type	.L.str10,@object        # @.str10
.L.str10:
	.asciz	 "Size: "
	.size	.L.str10, 7

	.section	.ctors,"aw",@progbits
	.align	4
	.long	_GLOBAL__I_a
	.long	_GLOBAL__I_a36
	.type	_ZStL8__ioinit1,@object # @_ZStL8__ioinit1
	.local	_ZStL8__ioinit1
	.comm	_ZStL8__ioinit1,1,1
	.type	.L.str11,@object        # @.str11
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str11:
	.asciz	 "{"
	.size	.L.str11, 2

	.type	.L.str112,@object       # @.str112
.L.str112:
	.asciz	 " "
	.size	.L.str112, 2

	.type	.L.str213,@object       # @.str213
.L.str213:
	.asciz	 "}"
	.size	.L.str213, 2


	.globl	_ZN3SetC1Ev
_ZN3SetC1Ev = _ZN3SetC2Ev
	.globl	_ZN3SetC1ERKS_
_ZN3SetC1ERKS_ = _ZN3SetC2ERKS_
	.globl	_ZN3SetD1Ev
_ZN3SetD1Ev = _ZN3SetD2Ev
	.section	".note.GNU-stack","",@progbits
