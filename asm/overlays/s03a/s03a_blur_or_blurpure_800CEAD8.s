	opt	c+, at+, e+, n-
	section overlay.text

	xdef s03a_blur_or_blurpure_800CEAD8
s03a_blur_or_blurpure_800CEAD8:
	dw 0x3C02800C ; 800CEAD8
	dw 0x8C42356C ; 800CEADC
	dw 0x00000000 ; 800CEAE0
	dw 0x10400002 ; 800CEAE4
	dw 0x00000000 ; 800CEAE8
	dw 0xAC40005C ; 800CEAEC
	dw 0x03E00008 ; 800CEAF0
	dw 0x00000000 ; 800CEAF4