	.file	"redblack.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"went oom\n"
	.text
	.p2align 4
	.globl	insert_node
	.type	insert_node, @function
insert_node:
.LFB38:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi
	mov	edi, 32
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	ebx, esi
	sub	rsp, 8
	.cfi_def_cfa_offset 32
	call	malloc@PLT
	test	rax, rax
	je	.L51
	movdqu	xmm0, XMMWORD PTR 0[rbp]
	mov	r9, QWORD PTR 8[rbp]
	mov	DWORD PTR 28[rax], ebx
	mov	rdi, rax
	movq	QWORD PTR 16[rax], xmm0
	punpcklqdq	xmm0, xmm0
	movups	XMMWORD PTR [rax], xmm0
	mov	eax, 82
	mov	WORD PTR 24[rdi], ax
	cmp	BYTE PTR 25[r9], 0
	mov	rax, r9
	je	.L3
	jmp	.L52
	.p2align 4,,10
	.p2align 3
.L54:
	mov	rdx, QWORD PTR 16[rax]
	cmp	BYTE PTR 25[rdx], 0
	jne	.L53
.L6:
	mov	rax, rdx
.L3:
	cmp	ebx, DWORD PTR 28[rax]
	jg	.L54
	mov	rdx, QWORD PTR 8[rax]
	cmp	BYTE PTR 25[rdx], 0
	je	.L6
	mov	QWORD PTR 8[rax], rdi
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L53:
	mov	QWORD PTR 16[rax], rdi
.L9:
	mov	QWORD PTR [rdi], rax
	cmp	BYTE PTR 24[rax], 82
	jne	.L21
	mov	rsi, rdi
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L56:
	cmp	BYTE PTR 24[rdx], 82
	je	.L11
	mov	rdx, QWORD PTR 8[rcx]
	cmp	rax, rdx
	je	.L55
.L27:
	mov	rax, QWORD PTR [rsi]
	cmp	BYTE PTR 24[rax], 82
	jne	.L21
.L7:
	mov	rcx, QWORD PTR [rax]
	mov	rdx, QWORD PTR 16[rcx]
	cmp	rdx, rax
	jne	.L56
	mov	rdx, QWORD PTR 8[rcx]
	cmp	BYTE PTR 24[rdx], 82
	je	.L11
	cmp	rsi, QWORD PTR 16[rax]
	je	.L57
	mov	r8, QWORD PTR 8[rax]
	cmp	rsi, r8
	jne	.L27
	mov	rdx, QWORD PTR 16[r8]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR 8[rax], rdx
	jne	.L23
	mov	QWORD PTR [rdx], rax
	mov	rdx, QWORD PTR [rax]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR [r8], rdx
	jne	.L39
	cmp	rax, QWORD PTR 16[rdx]
	je	.L40
	mov	QWORD PTR 8[rdx], r8
	jmp	.L25
	.p2align 4,,10
	.p2align 3
.L11:
	mov	BYTE PTR 24[rdx], 66
	mov	BYTE PTR 24[rax], 66
	mov	rax, QWORD PTR [rcx]
	cmp	BYTE PTR 25[rax], 0
	jne	.L1
	mov	BYTE PTR 24[rcx], 82
	cmp	BYTE PTR 24[rax], 82
	mov	rsi, rcx
	je	.L7
.L21:
	mov	BYTE PTR 24[r9], 66
.L1:
	add	rsp, 8
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	mov	rax, rdi
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L55:
	.cfi_restore_state
	cmp	rsi, QWORD PTR 8[rdx]
	je	.L58
	mov	rdx, QWORD PTR 16[rax]
	cmp	rsi, rdx
	jne	.L27
	mov	rsi, QWORD PTR 8[rdx]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 16[rax], rsi
	jne	.L35
	mov	QWORD PTR [rsi], rax
	mov	rsi, QWORD PTR [rax]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rdx], rsi
	jne	.L41
	cmp	rax, QWORD PTR 8[rsi]
	je	.L42
	mov	QWORD PTR 16[rsi], rdx
.L37:
	mov	QWORD PTR 8[rdx], rax
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR 8[rcx]
	jmp	.L29
.L52:
	mov	QWORD PTR 8[rbp], rdi
	mov	rax, rdi
	mov	BYTE PTR 24[rdi], 66
	add	rsp, 8
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
.L57:
	.cfi_restore_state
	mov	rdx, rax
.L16:
	mov	rsi, QWORD PTR 8[rdx]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 16[rcx], rsi
	jne	.L17
	mov	QWORD PTR [rsi], rcx
.L17:
	mov	rsi, QWORD PTR [rcx]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rdx], rsi
	jne	.L59
	cmp	rcx, QWORD PTR 8[rsi]
	je	.L60
	mov	QWORD PTR 16[rsi], rdx
	mov	r9, QWORD PTR 8[rbp]
.L19:
	mov	QWORD PTR 8[rdx], rcx
	mov	QWORD PTR [rcx], rdx
	mov	BYTE PTR 24[rcx], 82
	mov	BYTE PTR 24[rax], 66
	mov	BYTE PTR 24[r9], 66
	jmp	.L1
.L58:
	mov	rax, rdx
.L29:
	mov	rsi, QWORD PTR 16[rax]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 8[rcx], rsi
	jne	.L30
	mov	QWORD PTR [rsi], rcx
.L30:
	mov	rsi, QWORD PTR [rcx]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rax], rsi
	jne	.L61
	cmp	rcx, QWORD PTR 16[rsi]
	je	.L62
	mov	QWORD PTR 8[rsi], rax
	mov	r9, QWORD PTR 8[rbp]
.L32:
	mov	QWORD PTR 16[rax], rcx
	mov	QWORD PTR [rcx], rax
	mov	BYTE PTR 24[rcx], 82
	mov	BYTE PTR 24[rdx], 66
	mov	BYTE PTR 24[r9], 66
	jmp	.L1
.L23:
	cmp	BYTE PTR 25[rcx], 0
	mov	QWORD PTR [r8], rcx
	mov	rdx, rcx
	jne	.L39
.L40:
	mov	QWORD PTR 16[rdx], r8
.L25:
	mov	QWORD PTR 16[r8], rax
	mov	rdx, QWORD PTR 16[rcx]
	mov	QWORD PTR [rax], r8
	mov	rax, r8
	jmp	.L16
.L62:
	mov	QWORD PTR 16[rsi], rax
	mov	r9, QWORD PTR 8[rbp]
	jmp	.L32
.L60:
	mov	QWORD PTR 8[rsi], rdx
	mov	r9, QWORD PTR 8[rbp]
	jmp	.L19
.L35:
	cmp	BYTE PTR 25[rcx], 0
	mov	QWORD PTR [rdx], rcx
	mov	rsi, rcx
	jne	.L41
.L42:
	mov	QWORD PTR 8[rsi], rdx
	jmp	.L37
.L39:
	mov	QWORD PTR 8[rbp], r8
	jmp	.L25
.L41:
	mov	QWORD PTR 8[rbp], rdx
	jmp	.L37
.L59:
	mov	QWORD PTR 8[rbp], rdx
	mov	r9, rdx
	jmp	.L19
.L61:
	mov	QWORD PTR 8[rbp], rax
	mov	r9, rax
	jmp	.L32
.L51:
	lea	rdi, .LC0[rip]
	call	perror@PLT
	mov	edi, 1
	call	exit@PLT
	.cfi_endproc
.LFE38:
	.size	insert_node, .-insert_node
	.p2align 4
	.globl	delete_node
	.type	delete_node, @function
delete_node:
.LFB42:
	.cfi_startproc
	mov	rax, QWORD PTR 16[rsi]
	mov	rdx, QWORD PTR 8[rsi]
	mov	rcx, rdi
	cmp	BYTE PTR 25[rax], 0
	movzx	edx, BYTE PTR 25[rdx]
	jne	.L131
	test	dl, dl
	jne	.L132
	.p2align 4,,10
	.p2align 3
.L66:
	mov	rdi, rax
	mov	rax, QWORD PTR 8[rax]
	cmp	BYTE PTR 25[rax], 0
	je	.L66
	mov	eax, DWORD PTR 28[rdi]
	mov	DWORD PTR 28[rsi], eax
	mov	rdx, QWORD PTR 16[rdi]
	cmp	BYTE PTR 25[rdx], 0
	mov	rax, rdx
	jne	.L64
.L65:
	mov	rax, QWORD PTR [rdi]
	cmp	BYTE PTR 25[rax], 0
	mov	QWORD PTR [rdx], rax
	jne	.L155
	cmp	rdi, QWORD PTR 16[rax]
	je	.L156
	mov	QWORD PTR 8[rax], rdx
.L69:
	mov	BYTE PTR 24[rdx], 66
.L71:
	jmp	free@PLT
	.p2align 4,,10
	.p2align 3
.L131:
	mov	rdi, rsi
	.p2align 4,,10
	.p2align 3
.L64:
	mov	rdx, QWORD PTR 8[rdi]
	cmp	BYTE PTR 25[rdx], 0
	je	.L65
	cmp	BYTE PTR 25[rax], 0
	movzx	r8d, BYTE PTR 24[rdi]
	je	.L157
	mov	rax, QWORD PTR [rdi]
	movzx	esi, BYTE PTR 25[rax]
	cmp	r8b, 82
	je	.L103
	test	sil, sil
	je	.L158
.L151:
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L71
	.p2align 4,,10
	.p2align 3
.L156:
	mov	QWORD PTR 16[rax], rdx
	jmp	.L69
	.p2align 4,,10
	.p2align 3
.L132:
	mov	rdx, rax
	mov	rdi, rsi
	jmp	.L65
	.p2align 4,,10
	.p2align 3
.L158:
	mov	r9, rdi
	cmp	r8b, 66
	jne	.L159
.L94:
	mov	rdx, QWORD PTR 16[rax]
	cmp	r9, rdx
	je	.L78
	cmp	BYTE PTR 24[rdx], 82
	je	.L160
.L79:
	mov	r10, QWORD PTR 8[rdx]
	movzx	esi, BYTE PTR 24[r10]
	cmp	sil, 66
	jne	.L89
	mov	rsi, QWORD PTR 16[rdx]
	cmp	BYTE PTR 24[rsi], 66
	je	.L161
	mov	r8, QWORD PTR 16[rax]
	cmp	rdx, r8
	je	.L96
.L104:
	movzx	r8d, BYTE PTR 24[rax]
	mov	BYTE PTR 24[rsi], r8b
	mov	r8, QWORD PTR 8[rsi]
	cmp	BYTE PTR 25[r8], 0
	mov	QWORD PTR 16[rdx], r8
	jne	.L117
	mov	QWORD PTR [r8], rdx
.L117:
	mov	r8, QWORD PTR [rdx]
	cmp	BYTE PTR 25[r8], 0
	mov	QWORD PTR [rsi], r8
	jne	.L162
	cmp	rdx, QWORD PTR 8[r8]
	je	.L163
	mov	QWORD PTR 16[r8], rsi
.L119:
	mov	QWORD PTR 8[rsi], rdx
	mov	QWORD PTR [rdx], rsi
	mov	rdx, QWORD PTR 8[rax]
	mov	rsi, QWORD PTR 16[rdx]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 8[rax], rsi
	jne	.L121
	mov	QWORD PTR [rsi], rax
.L121:
	mov	rsi, QWORD PTR [rax]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rdx], rsi
	jne	.L164
	cmp	rax, QWORD PTR 16[rsi]
	je	.L165
	mov	QWORD PTR 8[rsi], rdx
.L123:
	mov	QWORD PTR 16[rdx], rax
.L150:
	mov	QWORD PTR [rax], rdx
	mov	BYTE PTR 24[rax], 66
	mov	rax, QWORD PTR [rdi]
	mov	rdx, QWORD PTR 8[rdi]
	movzx	esi, BYTE PTR 25[rax]
.L103:
	test	sil, sil
	jne	.L151
.L125:
	cmp	rdi, QWORD PTR 16[rax]
	je	.L166
	mov	QWORD PTR 8[rax], rdx
	jmp	free@PLT
	.p2align 4,,10
	.p2align 3
.L166:
	mov	QWORD PTR 16[rax], rdx
	jmp	free@PLT
.L155:
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L69
.L163:
	mov	QWORD PTR 8[r8], rsi
	jmp	.L119
.L78:
	mov	rdx, QWORD PTR 8[rax]
	cmp	BYTE PTR 24[rdx], 82
	jne	.L79
	mov	BYTE PTR 24[rax], 82
	mov	rsi, QWORD PTR 16[rdx]
	mov	BYTE PTR 24[rdx], 66
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 8[rax], rsi
	jne	.L128
	mov	QWORD PTR [rsi], rax
.L128:
	mov	rsi, QWORD PTR [rax]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rdx], rsi
	jne	.L167
	cmp	rax, QWORD PTR 16[rsi]
	je	.L168
	mov	QWORD PTR 8[rsi], rdx
.L83:
	mov	QWORD PTR 16[rdx], rax
.L85:
	mov	QWORD PTR [rax], rdx
	mov	rsi, QWORD PTR [r9]
	mov	rdx, QWORD PTR 16[rsi]
	cmp	r9, rdx
	jne	.L79
	mov	rdx, QWORD PTR 8[rsi]
	jmp	.L79
.L160:
	mov	BYTE PTR 24[rax], 82
	mov	rsi, QWORD PTR 8[rdx]
	mov	BYTE PTR 24[rdx], 66
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 16[rax], rsi
	jne	.L80
	mov	QWORD PTR [rsi], rax
.L80:
	mov	rsi, QWORD PTR [rax]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rdx], rsi
	jne	.L169
	cmp	rax, QWORD PTR 8[rsi]
	je	.L170
	mov	QWORD PTR 16[rsi], rdx
.L87:
	mov	QWORD PTR 8[rdx], rax
	jmp	.L85
.L161:
	mov	BYTE PTR 24[rdx], 82
	mov	r9, QWORD PTR [r9]
	cmp	BYTE PTR 24[r9], 66
	jne	.L93
	mov	rax, QWORD PTR [r9]
	cmp	BYTE PTR 25[rax], 0
	je	.L94
.L93:
	mov	rax, QWORD PTR [rdi]
	mov	rdx, QWORD PTR 8[rdi]
	movzx	esi, BYTE PTR 25[rax]
	mov	BYTE PTR 24[r9], 66
	jmp	.L103
.L165:
	mov	QWORD PTR 16[rsi], rdx
	jmp	.L123
.L164:
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L123
.L162:
	mov	QWORD PTR 8[rcx], rsi
	jmp	.L119
.L170:
	mov	QWORD PTR 8[rsi], rdx
	jmp	.L87
.L169:
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L87
.L168:
	mov	QWORD PTR 16[rsi], rdx
	jmp	.L83
.L89:
	mov	r8, QWORD PTR 16[rax]
	cmp	rdx, r8
	je	.L171
	mov	r9, QWORD PTR 8[rax]
	cmp	rdx, r9
	jne	.L149
	cmp	sil, 82
	jne	.L149
.L97:
	mov	BYTE PTR 24[r10], 66
	movzx	esi, BYTE PTR 24[rax]
	mov	BYTE PTR 24[rdx], sil
	mov	BYTE PTR 24[rax], 66
	mov	rdx, QWORD PTR 16[r9]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR 8[rax], rdx
	jne	.L105
	mov	QWORD PTR [rdx], rax
.L105:
	mov	rdx, QWORD PTR [rax]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR [r9], rdx
	jne	.L172
	cmp	rax, QWORD PTR 16[rdx]
	je	.L173
	mov	QWORD PTR 8[rdx], r9
.L107:
	mov	QWORD PTR 16[r9], rax
	mov	rdx, QWORD PTR 8[rdi]
	mov	QWORD PTR [rax], r9
	mov	rax, QWORD PTR [rdi]
	movzx	esi, BYTE PTR 25[rax]
	jmp	.L103
.L96:
	mov	BYTE PTR 24[rsi], 66
	movzx	edx, BYTE PTR 24[rax]
	mov	BYTE PTR 24[r8], dl
	mov	BYTE PTR 24[rax], 66
	mov	rdx, QWORD PTR 8[r8]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR 16[rax], rdx
	jne	.L99
	mov	QWORD PTR [rdx], rax
.L99:
	mov	rdx, QWORD PTR [rax]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR [r8], rdx
	jne	.L174
	cmp	rax, QWORD PTR 8[rdx]
	je	.L175
	mov	QWORD PTR 16[rdx], r8
.L101:
	mov	QWORD PTR 8[r8], rax
	mov	rdx, QWORD PTR 8[rdi]
	mov	QWORD PTR [rax], r8
	mov	rax, QWORD PTR [rdi]
	movzx	esi, BYTE PTR 25[rax]
	jmp	.L103
.L159:
	mov	BYTE PTR 24[rdi], 66
	jmp	.L125
.L167:
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L83
.L171:
	mov	rsi, QWORD PTR 16[r8]
	cmp	BYTE PTR 24[rsi], 82
	je	.L96
	mov	r9, QWORD PTR 8[rax]
	cmp	r8, r9
	je	.L97
	movzx	edx, BYTE PTR 24[rax]
	mov	BYTE PTR 24[r10], dl
	mov	rdx, QWORD PTR 16[r10]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR 8[r8], rdx
	jne	.L109
	mov	QWORD PTR [rdx], r8
.L109:
	mov	rdx, QWORD PTR [r8]
	cmp	BYTE PTR 25[rdx], 0
	mov	QWORD PTR [r10], rdx
	jne	.L176
	cmp	r8, QWORD PTR 16[rdx]
	je	.L177
	mov	QWORD PTR 8[rdx], r10
.L111:
	mov	QWORD PTR 16[r10], r8
	mov	rdx, QWORD PTR 16[rax]
	mov	QWORD PTR [r8], r10
	mov	rsi, QWORD PTR 8[rdx]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR 16[rax], rsi
	jne	.L113
	mov	QWORD PTR [rsi], rax
.L113:
	mov	rsi, QWORD PTR [rax]
	cmp	BYTE PTR 25[rsi], 0
	mov	QWORD PTR [rdx], rsi
	jne	.L178
	cmp	rax, QWORD PTR 8[rsi]
	je	.L179
	mov	QWORD PTR 16[rsi], rdx
.L115:
	mov	QWORD PTR 8[rdx], rax
	jmp	.L150
.L177:
	mov	QWORD PTR 16[rdx], r10
	jmp	.L111
.L179:
	mov	QWORD PTR 8[rsi], rdx
	jmp	.L115
.L176:
	mov	QWORD PTR 8[rcx], r10
	jmp	.L111
.L178:
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L115
.L173:
	mov	QWORD PTR 16[rdx], r9
	jmp	.L107
.L175:
	mov	QWORD PTR 8[rdx], r8
	jmp	.L101
.L172:
	mov	QWORD PTR 8[rcx], r9
	jmp	.L107
.L174:
	mov	QWORD PTR 8[rcx], r8
	jmp	.L101
.L157:
	mov	rdx, rax
	jmp	.L65
.L149:
	mov	rsi, QWORD PTR 16[rdx]
	jmp	.L104
	.cfi_endproc
.LFE42:
	.size	delete_node, .-delete_node
	.ident	"GCC: (GNU) 14.1.0"
	.section	.note.GNU-stack,"",@progbits
