	opt	c+, at+, e+, n-
	section overlay.text

	xdef s11g_red_alrt_800CD11C
s11g_red_alrt_800CD11C:
	dw 0x3C02800C ; 800CD11C
	dw 0xAC503584 ; 800CD120
	dw 0x8FB00028 ; 800CD124
	dw 0x03E00008 ; 800CD128
	dw 0x27BD0030 ; 800CD12C
