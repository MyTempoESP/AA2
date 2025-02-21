#ifndef __aa2_FTH__
#define __aa2_FTH__
const char code[] PROGMEM =
#define NL "\n"
": w0" NL
// @359/v34	->	VOID
// @103/v33	->	DATA
// @308/v32	->	1-CODE
// @313/v31	->	2-CODE
// @287/v30	->	VERSION
// @372/w29	->	do-button
// @365/w28	->	switch-screen
// @359/w27	->	confirm
// @365/w26	->	VOID!
// @360/w25	->	VOID@
// @317/w24	->	S-9
// @307/w23	->	S-8
// @340/w22	->	PROG-S-7
// @270/w21	->	S-7
// @337/w20	->	PROG-S-6
// @245/w19	->	S-6
// @334/w18	->	PROG-S-5
// @202/w17	->	S-5
// @331/w16	->	PROG-S-4
// @176/w15	->	S-4
// @328/w14	->	PROG-S-3
// @147/w13	->	S-3
// @325/w12	->	PROG-S-2
// @111/w11	->	S-2
// @322/w10	->	PROG-S-1
// @81/w9	->	S-1
// @258/w8	->	clean!
// @172/w7	->	data-Big!
// @271/w6	->	data-C!
// @272/w5	->	data!
// @63/w4	->	calc-align
// @63/w3	->	F!
// @54/w2	->	16-bit-encode!
// @343/w1	->	Dis
// @304/w0	->	Button-Data
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
	"NOP NOP NOP NOP" NL
";" NL
"501 VAL v30" NL
": w1" NL
	"NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP" NL
	"0 5 API" NL
	"v30 4 API" NL
	 "2 API" NL
	"TAG NOP NOP NOP 2 API" NL
	"TAG NOP NOP NOP 2 API" NL
	"3 5 API NOP" NL
	"0 6 API" NL
	 "2 API" NL
	 "0 API" NL
";" NL
"VAL v31" NL
"VAL v32" NL
"' w1 VAL v33" NL
": w2" NL
	"$BF" NL
	"OVR C!" NL
	"1 +" NL
	 "!" NL
";" NL
": w3" NL
	"DUP >R" NL
	"w2" NL
	"R>" NL
	"3 +" NL
	 "C!" NL
";" NL
": w4" NL
	">R" NL
	 "*" NL
	"R>" NL
	 "+" NL
";" NL
": w5" NL
	"v33 + w2" NL
";" NL
": w6" NL
	"v33 + C!" NL
";" NL
": w7" NL
	"4" NL
	"v33 w4" NL
	 "w3" NL
";" NL
": w8" NL
	"$bbbb v33 !" NL
	"$bbbb v33 $2 + !" NL
	"$bbbb v33 $4 + !" NL
	"$bbbb v33 $6 + !" NL
	"$bbbb v33 $8 + !" NL
	"$bbbb v33 $C + !" NL
	"$bbbb v33 $A + !" NL
	"$bbbb v33 $E + !" NL
";" NL
": S-1*" NL
	"w8" NL
	 "$02" NL
	 "$0C" NL
	"w6" NL
	 "$02" NL
	"w7" NL
	 "$01" NL
	 "$04" NL
	"w6" NL
	 "$00" NL
	"w7" NL
";" NL
": w10" NL
	"0 0 0 0 S-1*" NL
	 "$05B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v32 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v31 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-2*" NL
	"w8" NL
	 "$07" NL
	 "$0E" NL
	"w6" NL
	 "$02" NL
	"w5" NL
	 "$05" NL
	"w5" NL
	 "$08" NL
	"w5" NL
	 "$0B" NL
	"w5" NL
	 "$04" NL
	 "$01" NL
	"w6" NL
	 "$00" NL
	"w6" NL
";" NL
": w12" NL
	"5 0 0 0 0 S-2*" NL
	 "$05B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$07B4" NL
	 "$02" NL
	"v32 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v31 + !" NL
	 "$06B4" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-3*" NL
	"w8" NL
	 "$0C" NL
	"w6" NL
	 "$08" NL
	"w6" NL
	 "$0A" NL
	 "$04" NL
	"w6" NL
	 "$00" NL
	"w5" NL
";" NL
": w14" NL
	"0 2 5 S-3*" NL
	 "$05B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$06B4" NL
	 "$02" NL
	"v32 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v31 + !" NL
	 "$03B4" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-4*" NL
	"0 w7" NL
	"1 w7" NL
	"2 w7" NL
	"3 w7" NL
";" NL
": w16" NL
	"0 0" NL
	"0 0" NL
	"0 0" NL
	"0 0 S-4*" NL
	 "$08B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$BBBB" NL
	 "$02" NL
	"v32 + !" NL
	 "$BBBB" NL
	 "$00" NL
	"v31 + !" NL
	 "$BBBB" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-5*" NL
	 "$16" NL
	 "$08" NL
	"w6" NL
	 "$02" NL
	"w5" NL
	 "$01" NL
	"w6" NL
	 "$00" NL
	"w6" NL
	 "$DA7E" NL
	 "$05" NL
	"w5" NL
	 "$0B" NL
	 "$0F" NL
	"w6" NL
	 "$100" NL
	 "$0C" NL
	"w5" NL
	 "$0B" NL
	"w6" NL
	 "$0A" NL
	"w6" NL
	 "$09" NL
	"w6" NL
";" NL
": w18" NL
	"0 0 0 0 0 0 S-5*" NL
	 "$05B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$07B4" NL
	 "$02" NL
	"v32 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v31 + !" NL
	 "$07B4" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-6*" NL
	"w8" NL
	 "$0C" NL
	 "$04" NL
	"w6" NL
	 "$00" NL
	"w6" NL
";" NL
": w20" NL
	"2 S-6*" NL
	 "$05B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$06B4" NL
	 "$02" NL
	"v32 + !" NL
 	 "$BBBB" NL
	 "$00" NL
	"v31 + !" NL
	 "$BBBB" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-7*" NL
	"w8" NL
	 "$10" NL
	 "$05" NL
	"w6" NL
	 "$10" NL
	 "$04" NL
	"w6" NL
	 "$CA00 v30 1 RSH OR" NL
	 "$00" NL
	"w5" NL
	 "$12" NL
	 "$0D" NL
	"w6" NL
	 "$10" NL
	 "$0C" NL
	"w6" NL
	 "$08" NL
	"w5" NL
";" NL
": w22" NL
	"0 S-7*" NL
	 "$05B4" NL
	 "$00" NL
	"v32 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v32 + !" NL
	 "$05B4" NL
	 "$00" NL
	"v31 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v31 + !" NL
";" NL
": S-8*" NL
	"0 TME" NL
	"100 DLY" NL
		 "2 API" NL
	"$13 5 API 2 API" NL
	"$14 5 API 2 API" NL
		 "2 API" NL
	"0 API" NL
";" NL
": S-9*" NL
	"0 TME" NL
	"100 DLY" NL
	 "2 API" NL
	"$0E 5 API 2 API" NL
	"$0F 5 API 2 API" NL
	 "2 API" NL
	"0 API" NL
	"5000 DLY" NL
	"1 TME" NL
";" NL
"' w0 2 + VAL v34" NL
": w25 v34 + C@ ;" NL
": w26 v34 + C! ;" NL
"$00 0 w26" NL
"$00 1 w26" NL
"$00 2 w26" NL
": w27 $00 2 w26 ;" NL
"' w27 v34 3 + !" NL
"' w10 v34 $05 + !" NL
"' w12 v34 $07 + !" NL
"' w14 v34 $09 + !" NL
"' w16 v34 $0B + !" NL
"' w18 v34 $0D + !" NL
"' w20 v34 $0F + !" NL
"' w22 v34 $11 + !" NL
": w28" NL
	"v34 3 + @ C@ 1 + 7 MOD DUP DUP" NL
	"v34 3 + @ C!" NL
	"$60 OR v34 2 + C!" NL
	 "$02 *" NL
	 "$05 +" NL
	 "v34 + @ EXE" NL
";" NL
": w29" NL
	"6 IN 0 = DUP" NL
	"7 IN 0 = DUP" NL
	"0 w25 NOT AND" NL
	"IF" NL
		"w27" NL
	"THN" NL
	"0 w26" NL
	"1 w25 NOT AND" NL
	"IF" NL
		"w28" NL
	"THN" NL
	"1 w26" NL
";" NL
"500 DLY" NL
"100 1 TMI w1" NL
"10 0 TMI w29" NL
"1 TME" NL
;
#endif
