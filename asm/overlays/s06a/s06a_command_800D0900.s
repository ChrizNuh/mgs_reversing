	opt	c+, at+, e+, n-
	section overlay.text

	xdef s06a_command_800D0900
s06a_command_800D0900:
	dw 0x3C02800E ; 800D0900
	dw 0x244222C0 ; 800D0904
	dw 0x00042080 ; 800D0908
	dw 0x00822021 ; 800D090C
	dw 0x03E00008 ; 800D0910
	dw 0xAC850148 ; 800D0914