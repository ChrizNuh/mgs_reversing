	opt	c+, at+, e+, n-
	section overlay.text

	xdef roll_800C512C
roll_800C512C:
	dw 0x3C0800FF ; 800C512C
	dw 0x3508FFFF ; 800C5130
	dw 0x240E0004 ; 800C5134
	dw 0x240D0064 ; 800C5138
	dw 0x240C0018 ; 800C513C
	dw 0x240A0100 ; 800C5140
	dw 0x240B00A0 ; 800C5144
	dw 0xA08E0003 ; 800C5148
	dw 0x8C830000 ; 800C514C
	dw 0x3C09FF00 ; 800C5150
	dw 0xA08D0007 ; 800C5154
	dw 0xA0870004 ; 800C5158
	dw 0xA0870005 ; 800C515C
	dw 0xA0870006 ; 800C5160
	dw 0xA4800008 ; 800C5164
	dw 0xA48C000A ; 800C5168
	dw 0xA080000C ; 800C516C
	dw 0xA080000D ; 800C5170
	dw 0xA48A0010 ; 800C5174
	dw 0xA48B0012 ; 800C5178
	dw 0x8CC20000 ; 800C517C
	dw 0x00691824 ; 800C5180
	dw 0x00481024 ; 800C5184
	dw 0x00621825 ; 800C5188
	dw 0xAC830000 ; 800C518C
	dw 0x00881824 ; 800C5190
	dw 0x8CC20000 ; 800C5194
	dw 0x24840014 ; 800C5198
	dw 0x00491024 ; 800C519C
	dw 0x00431025 ; 800C51A0
	dw 0xACC20000 ; 800C51A4
	dw 0x8CA30000 ; 800C51A8
	dw 0x00481024 ; 800C51AC
	dw 0x00691824 ; 800C51B0
	dw 0x00621825 ; 800C51B4
	dw 0xACA30000 ; 800C51B8
	dw 0x00A81824 ; 800C51BC
	dw 0x8CC20000 ; 800C51C0
	dw 0x24A50008 ; 800C51C4
	dw 0x00491024 ; 800C51C8
	dw 0x00431025 ; 800C51CC
	dw 0xACC20000 ; 800C51D0
	dw 0xA08E0003 ; 800C51D4
	dw 0x8C830000 ; 800C51D8
	dw 0x24020040 ; 800C51DC
	dw 0xA08D0007 ; 800C51E0
	dw 0xA0870004 ; 800C51E4
	dw 0xA0870005 ; 800C51E8
	dw 0xA0870006 ; 800C51EC
	dw 0xA48A0008 ; 800C51F0
	dw 0xA48C000A ; 800C51F4
	dw 0xA080000C ; 800C51F8
	dw 0xA080000D ; 800C51FC
	dw 0xA4820010 ; 800C5200
	dw 0xA48B0012 ; 800C5204
	dw 0x8CC20000 ; 800C5208
	dw 0x00691824 ; 800C520C
	dw 0x00481024 ; 800C5210
	dw 0x00621825 ; 800C5214
	dw 0xAC830000 ; 800C5218
	dw 0x8CC20000 ; 800C521C
	dw 0x00882024 ; 800C5220
	dw 0x00491024 ; 800C5224
	dw 0x00441025 ; 800C5228
	dw 0xACC20000 ; 800C522C
	dw 0x8CA30000 ; 800C5230
	dw 0x00481024 ; 800C5234
	dw 0x00691824 ; 800C5238
	dw 0x00621825 ; 800C523C
	dw 0xACA30000 ; 800C5240
	dw 0x8CC20000 ; 800C5244
	dw 0x00A82824 ; 800C5248
	dw 0x00491024 ; 800C524C
	dw 0x00451025 ; 800C5250
	dw 0x03E00008 ; 800C5254
	dw 0xACC20000 ; 800C5258
	dw 0x27BDFFE0 ; 800C525C
	dw 0xAFB00010 ; 800C5260
	dw 0x00808021 ; 800C5264
	dw 0x3C02800B ; 800C5268
	dw 0xAFB10014 ; 800C526C
	dw 0x8C44B920 ; 800C5270
	dw 0x3C02800D ; 800C5274
	dw 0x24429BC8 ; 800C5278
	dw 0xAFBF0018 ; 800C527C
	dw 0x000418C0 ; 800C5280
	dw 0x00641823 ; 800C5284
	dw 0x000318C0 ; 800C5288
	dw 0x00621821 ; 800C528C
	dw 0x3C02800B ; 800C5290
	dw 0x244219EC ; 800C5294
	dw 0x00042080 ; 800C5298
	dw 0x00441021 ; 800C529C
	dw 0x24680010 ; 800C52A0
	dw 0x00602821 ; 800C52A4
	dw 0x8E040024 ; 800C52A8
	dw 0x8C4601EC ; 800C52AC
	dw 0x24840001 ; 800C52B0
	dw 0x2C830006 ; 800C52B4
	dw 0x10600081 ; 800C52B8
	dw 0x00008821 ; 800C52BC
	dw 0x3C02800D ; 800C52C0
	dw 0x24429A90 ; 800C52C4
	dw 0x00041880 ; 800C52C8
	dw 0x00621821 ; 800C52CC
	dw 0x8C620000 ; 800C52D0
	dw 0x00000000 ; 800C52D4
	dw 0x00400008 ; 800C52D8
	dw 0x00000000 ; 800C52DC
	dw 0x8E040040 ; 800C52E0
	dw 0x0C0313EE ; 800C52E4
	dw 0x00002821 ; 800C52E8
	dw 0x8E030030 ; 800C52EC
	dw 0xAE020040 ; 800C52F0
	dw 0x080314F6 ; 800C52F4
	dw 0x24020001 ; 800C52F8
	dw 0x8E03002C ; 800C52FC
	dw 0x8E020030 ; 800C5300
	dw 0x2463FFFF ; 800C5304
	dw 0x00033840 ; 800C5308
	dw 0x00E33821 ; 800C530C
	dw 0x00073980 ; 800C5310
	dw 0x00E2001A ; 800C5314
	dw 0x14400002 ; 800C5318
	dw 0x00000000 ; 800C531C
	dw 0x0007000D ; 800C5320
	dw 0x2401FFFF ; 800C5324
	dw 0x14410004 ; 800C5328
	dw 0x3C018000 ; 800C532C
	dw 0x14E10002 ; 800C5330
	dw 0x00000000 ; 800C5334
	dw 0x0006000D ; 800C5338
	dw 0x00003812 ; 800C533C
	dw 0x01002021 ; 800C5340
	dw 0x240200C0 ; 800C5344
	dw 0xAE03002C ; 800C5348
	dw 0x0C03144B ; 800C534C
	dw 0x00473823 ; 800C5350
	dw 0x8E02002C ; 800C5354
	dw 0x00000000 ; 800C5358
	dw 0x1C400058 ; 800C535C
	dw 0x24020002 ; 800C5360
	dw 0x8E030034 ; 800C5364
	dw 0x080314F7 ; 800C5368
	dw 0xAE020024 ; 800C536C
	dw 0x01002021 ; 800C5370
	dw 0x8E02002C ; 800C5374
	dw 0x240700C0 ; 800C5378
	dw 0x2442FFFF ; 800C537C
	dw 0x0C03144B ; 800C5380
	dw 0xAE02002C ; 800C5384
	dw 0x8E02002C ; 800C5388
	dw 0x00000000 ; 800C538C
	dw 0x1C400006 ; 800C5390
	dw 0x2402FFFF ; 800C5394
	dw 0x8E030034 ; 800C5398
	dw 0x00000000 ; 800C539C
	dw 0x10620002 ; 800C53A0
	dw 0x00000000 ; 800C53A4
	dw 0x24110001 ; 800C53A8
	dw 0x96040020 ; 800C53AC
	dw 0x24050001 ; 800C53B0
	dw 0x3C06800C ; 800C53B4
	dw 0x0C031616 ; 800C53B8
	dw 0x24C63240 ; 800C53BC
	dw 0x14400002 ; 800C53C0
	dw 0x00000000 ; 800C53C4
	dw 0x24110001 ; 800C53C8
	dw 0x1220003C ; 800C53CC
	dw 0x24020003 ; 800C53D0
	dw 0x8E030030 ; 800C53D4
	dw 0xAE020024 ; 800C53D8
	dw 0x08031530 ; 800C53DC
	dw 0xAE03002C ; 800C53E0
	dw 0x8E03002C ; 800C53E4
	dw 0x8E020030 ; 800C53E8
	dw 0x2463FFFF ; 800C53EC
	dw 0x00033840 ; 800C53F0
	dw 0x00E33821 ; 800C53F4
	dw 0x00073980 ; 800C53F8
	dw 0x00E2001A ; 800C53FC
	dw 0x14400002 ; 800C5400
	dw 0x00000000 ; 800C5404
	dw 0x0007000D ; 800C5408
	dw 0x2401FFFF ; 800C540C
	dw 0x14410004 ; 800C5410
	dw 0x3C018000 ; 800C5414
	dw 0x14E10002 ; 800C5418
	dw 0x00000000 ; 800C541C
	dw 0x0006000D ; 800C5420
	dw 0x00003812 ; 800C5424
	dw 0x01002021 ; 800C5428
	dw 0x0C03144B ; 800C542C
	dw 0xAE03002C ; 800C5430
	dw 0x8E02002C ; 800C5434
	dw 0x00000000 ; 800C5438
	dw 0x1C400020 ; 800C543C
	dw 0x00000000 ; 800C5440
	dw 0x8E020028 ; 800C5444
	dw 0x8E03003C ; 800C5448
	dw 0x24420001 ; 800C544C
	dw 0xAE020028 ; 800C5450
	dw 0x8C630000 ; 800C5454
	dw 0x00000000 ; 800C5458
	dw 0x0043102A ; 800C545C
	dw 0x14400004 ; 800C5460
	dw 0x24020004 ; 800C5464
	dw 0x2402FFFF ; 800C5468
	dw 0x08031530 ; 800C546C
	dw 0xAE020024 ; 800C5470
	dw 0xAE020024 ; 800C5474
	dw 0x2402000F ; 800C5478
	dw 0x08031530 ; 800C547C
	dw 0xAE02002C ; 800C5480
	dw 0x8E02002C ; 800C5484
	dw 0x00000000 ; 800C5488
	dw 0x2442FFFF ; 800C548C
	dw 0x1C40000B ; 800C5490
	dw 0xAE02002C ; 800C5494
	dw 0x08031530 ; 800C5498
	dw 0xAE000024 ; 800C549C
	dw 0x3C04800C ; 800C54A0
	dw 0x24843238 ; 800C54A4
	dw 0x00002821 ; 800C54A8
	dw 0x00A03021 ; 800C54AC
	dw 0x0C023E7A ; 800C54B0
	dw 0x00A03821 ; 800C54B4
	dw 0x0C005472 ; 800C54B8
	dw 0x02002021 ; 800C54BC
	dw 0x8FBF0018 ; 800C54C0
