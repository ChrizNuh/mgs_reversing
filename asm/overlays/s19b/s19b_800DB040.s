	opt	c+, at+, e+, n-
	section overlay.text

	xdef s19b_800DB040
s19b_800DB040:
	dw 0x27BDFFE8 ; 800DB040
	dw 0xAFBF0010 ; 800DB044
	dw 0x8C840030 ; 800DB048
	dw 0x00000000 ; 800DB04C
	dw 0x10800003 ; 800DB050
	dw 0x00000000 ; 800DB054
	dw 0x0C005895 ; 800DB058
	dw 0x00000000 ; 800DB05C
	dw 0x8FBF0010 ; 800DB060
	dw 0x00000000 ; 800DB064
	dw 0x03E00008 ; 800DB068
	dw 0x27BD0018 ; 800DB06C
