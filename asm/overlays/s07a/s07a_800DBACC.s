	opt	c+, at+, e+, n-
	section overlay.text

	xdef s07a_800DBACC
s07a_800DBACC:
	dw 0x27BDFFE8 ; 800DBACC
	dw 0xAFB00010 ; 800DBAD0
	dw 0x00808021 ; 800DBAD4
	dw 0xAFBF0014 ; 800DBAD8
	dw 0x92030B7C ; 800DBADC
	dw 0x240200FF ; 800DBAE0
	dw 0x14620007 ; 800DBAE4
	dw 0x24020001 ; 800DBAE8
	dw 0xA6020B20 ; 800DBAEC
	dw 0x24020008 ; 800DBAF0
	dw 0xA6020B22 ; 800DBAF4
	dw 0x24020013 ; 800DBAF8
	dw 0x08036EC8 ; 800DBAFC
	dw 0xA6020B24 ; 800DBB00
	dw 0xA6020B20 ; 800DBB04
	dw 0x2402000A ; 800DBB08
	dw 0xA6020B22 ; 800DBB0C
	dw 0x2402001C ; 800DBB10
	dw 0x02002021 ; 800DBB14
	dw 0x0C036DEA ; 800DBB18
	dw 0xA6020B24 ; 800DBB1C
	dw 0x24020001 ; 800DBB20
	dw 0xAE000B28 ; 800DBB24
	dw 0xAE020B3C ; 800DBB28
	dw 0x8FBF0014 ; 800DBB2C
	dw 0x8FB00010 ; 800DBB30
	dw 0x03E00008 ; 800DBB34
	dw 0x27BD0018 ; 800DBB38
