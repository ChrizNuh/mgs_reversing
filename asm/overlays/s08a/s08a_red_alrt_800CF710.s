	opt	c+, at+, e+, n-
	section overlay.text

	xdef s08a_red_alrt_800CF710
s08a_red_alrt_800CF710:
	dw 0x3C02800C ; 800CF710
	dw 0xAC50354C ; 800CF714
	dw 0x8FB00028 ; 800CF718
	dw 0x03E00008 ; 800CF71C
	dw 0x27BD0030 ; 800CF720
