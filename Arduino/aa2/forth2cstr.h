#ifndef __aa2_FTH__
#define __aa2_FTH__
const char code[] PROGMEM =
#define NL "\n"
": w0" NL
// @301/v27	->	BAG
// @85/v26	->	DATA
// @266/v25	->	1-CODE
// @271/v24	->	2-CODE
// @248/v23	->	VERSION
// @313/w22	->	AC@
// @315/w21	->	do-button
// @307/w20	->	switch-screen
// @301/w19	->	confirm
// @276/w18	->	S-A
// @276/w17	->	lock-display
// @305/w16	->	BAG!
// @306/w15	->	BAG@
// @231/w14	->	S-7
// @210/w13	->	S-6
// @171/w12	->	S-5
// @152/w11	->	S-4
// @127/w10	->	S-3
// @95/w9	->	S-2
// @69/w8	->	S-1
// @225/w7	->	clean!
// @151/w6	->	data-Big!
// @260/w5	->	data-C!
// @239/w4	->	data!
// @53/w3	->	F!
// @49/w2	->	Encode!
// @294/w1	->	Dis
// @32/w0	->	Button-Data
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
"501 VAL v23" NL
": w1" NL
	"NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP" NL
	"0 5 API" NL
	"v23 4 API" NL
	 "2 API" NL
	"TAG NOP NOP NOP 2 API" NL
	"TAG NOP NOP NOP 2 API" NL
	"3 5 API NOP" NL
	"0 6 API" NL
	 "2 API" NL
	 "0 API" NL
";" NL
"VAL v24" NL
"VAL v25" NL
"' w1 VAL v26" NL
"' w0 2 + VAL v27" NL
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
	"v26 + w2" NL
";" NL
": w5 v26 + C! ;" NL
": w6 4 * v26 + w3 ;" NL
": w7" NL
	"$bbbb v26 !" NL
	"$bbbb v26 $2 + !" NL
	"$bbbb v26 $4 + !" NL
	"$bbbb v26 $6 + !" NL
	"$bbbb v26 $8 + !" NL
	"$bbbb v26 $C + !" NL
	"$bbbb v26 $A + !" NL
	"$bbbb v26 $E + !" NL
";" NL
": S-1*" NL
	"w7" NL
	 "$02" NL
	 "$0C" NL
	"w5" NL
	 "$02" NL
	"w6" NL
	 "$01" NL
	 "$04" NL
	"w5" NL
	 "$00" NL
	"w6" NL
	 "$05B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v25 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v24 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": S-2*" NL
	"w7" NL
	 "$07" NL
	 "$0E" NL
	"w5" NL
	 "$02" NL
	"w4" NL
	 "$05" NL
	"w4" NL
	 "$08" NL
	"w4" NL
	 "$0B" NL
	"w4" NL
	 "$04" NL
	 "$01" NL
	"w5" NL
	 "$00" NL
	"w5" NL
	 "$05B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$07B4" NL
	 "$02" NL
	"v25 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v24 + !" NL
	 "$06B4" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": S-3*" NL
	"w7" NL
	 "$0C" NL
	"w5" NL
	 "$08" NL
	"w5" NL
	 "$0A" NL
	 "$04" NL
	"w5" NL
	 "$00" NL
	"w4" NL
	 "$05B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$06B4" NL
	 "$02" NL
	"v25 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v24 + !" NL
	 "$03B4" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": S-4*" NL
	"0 w6" NL
	"1 w6" NL
	"2 w6" NL
	"3 w6" NL
	 "$08B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$BBBB" NL
	 "$02" NL
	"v25 + !" NL
	 "$BBBB" NL
	 "$00" NL
	"v24 + !" NL
	 "$BBBB" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": S-5*" NL
	 "$16" NL
	 "$08" NL
	"w5" NL
	 "$02" NL
	"w4" NL
	 "$01" NL
	"w5" NL
	 "$00" NL
	"w5" NL
	 "$DA7E" NL
	 "$05" NL
	"w4" NL
	 "$0B" NL
	 "$0F" NL
	"w5" NL
	 "$100" NL
	 "$0C" NL
	"w4" NL
	 "$0B" NL
	"w5" NL
	 "$0A" NL
	"w5" NL
	 "$09" NL
	"w5" NL
	 "$05B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$07B4" NL
	 "$02" NL
	"v25 + !" NL
 	 "$05B4" NL
	 "$00" NL
	"v24 + !" NL
	 "$07B4" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": S-6*" NL
	"w7" NL
	 "$0C" NL
	 "$04" NL
	"w5" NL
	 "$00" NL
	"w5" NL
	 "$05B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$06B4" NL
	 "$02" NL
	"v25 + !" NL
 	 "$BBBB" NL
	 "$00" NL
	"v24 + !" NL
	 "$BBBB" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": S-7*" NL
	"w7" NL
	 "$10" NL
	 "$05" NL
	"w5" NL
	 "$10" NL
	 "$04" NL
	"w5" NL
	 "$CA00 v23 1 RSH OR" NL
	 "$00" NL
	"w4" NL
	 "$12" NL
	 "$0D" NL
	"w5" NL
	 "$10" NL
	 "$0C" NL
	"w5" NL
	 "$08" NL
	"w4" NL
	 "$05B4" NL
	 "$00" NL
	"v25 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v25 + !" NL
	 "$05B4" NL
	 "$00" NL
	"v24 + !" NL
	 "$01B4" NL
	 "$02" NL
	"v24 + !" NL
";" NL
": w15 v27 + C@ ;" NL
": w16 v27 + C! ;" NL
"$00 $02 w16" NL
": w17" NL
	 "$80" NL
	 "$00" NL
	"w5" NL
	"100 DLY" NL
";" NL
": S-A" NL
 "w17" NL
	"2 API" NL
	"SWP 5 API 2 API" NL
	"DUP 0 = IF" NL
		"2 API DRP" NL
	"ELS" NL
		"5 API 2 API" NL
	"THN" NL
	"2 API" NL
	"0 API" NL
";" NL
": w19 $00 2 w16 ;" NL
"' w19 v27 3 + !" NL
": w20" NL
	"v27 3 + @ C@ 1 + 7 MOD DUP" NL
	"v27 3 + @ C!" NL
	"$60 OR 2 w16" NL
";" NL
": w21" NL
	"6 IN 0 = DUP" NL
	"7 IN 0 = DUP" NL
	"0 w15 NOT AND" NL
	"IF" NL
		"w19" NL
	"THN" NL
	"0 w16" NL
	"1 w15 NOT AND" NL
	"IF" NL
		"w20" NL
	"THN" NL
	"1 w16" NL
";" NL
": AC@ 2 w15 ;" NL
"500 DLY" NL
"100 1 TMI w1" NL
"10 0 TMI w21" NL
"1 TME" NL
;
#endif
