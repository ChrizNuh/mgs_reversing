	opt	c+, at+, e+, n-
	section .text

	xdef DeliverEvent_8009945C
DeliverEvent_8009945C:
	dw 0x240A00B0 ; 0x8009945C
	dw 0x01400008 ; 0x80099460
	dw 0x24090007 ; 0x80099464
	dw 0x00000000 ; 0x80099468