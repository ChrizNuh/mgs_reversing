	opt	c+, at+, e+, n-
	section overlay.text

	xdef d01a_command_800C82E0
d01a_command_800C82E0:
	dw 0x0085102A ; 800C82E0
	dw 0x10400002 ; 800C82E4
	dw 0x00000000 ; 800C82E8
	dw 0x00A02021 ; 800C82EC
	dw 0x03E00008 ; 800C82F0
	dw 0x00801021 ; 800C82F4