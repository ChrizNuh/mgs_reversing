	opt	c+, at+, e+, n-
	section overlay.text

	xdef s19b_800CAD90
s19b_800CAD90:
	dw 0x3C028000 ; 800CAD90
	dw 0x18A00007 ; 800CAD94
	dw 0x00822025 ; 800CAD98
	dw 0x14C40003 ; 800CAD9C
	dw 0x24A5FFFF ; 800CADA0
	dw 0x03E00008 ; 800CADA4
	dw 0x24020001 ; 800CADA8
	dw 0x1CA0FFFB ; 800CADAC
	dw 0x24C60030 ; 800CADB0
	dw 0x03E00008 ; 800CADB4
	dw 0x00001021 ; 800CADB8
