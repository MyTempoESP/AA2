#ifndef __aa2_FTH__
#define __aa2_FTH__
const char code[] PROGMEM =
#define NL "\n"
": w0 5 API ;" NL
// @322/v50	->	addr-Confirm
// @322/v49	->	Action
// @335/v48	->	arrow-down
// @329/v47	->	ok-down
// @219/v46	->	addr-Antenna
// @210/v45	->	addr-Ms
// @247/v44	->	addr-Ip
// @257/v43	->	addr-Value
// @127/v42	->	addr-Number
// @279/v41	->	addr-BigNum
// @123/v40	->	addr-Forward
// @276/v39	->	addr-Label
// @141/v38	->	DATA
// @273/v37	->	1-CODE
// @274/v36	->	2-CODE
// @259/v35	->	VERSION
// @325/w34	->	do-button
// @318/w33	->	switch-screen
// @312/w32	->	confirm
// @280/w31	->	S-9
// @270/w30	->	S-8
// @245/w29	->	S-7
// @233/w28	->	S-6
// @202/w27	->	S-5
// @193/w26	->	S-4
// @176/w25	->	S-3
// @152/w24	->	S-2
// @134/w23	->	S-1
// @229/w22	->	code-clean!
// @238/w21	->	clean!
// @258/w20	->	program-calls!
// @192/w19	->	call-idx!
// @98/w18	->	call!
// @85/w17	->	encode-call!
// @89/w16	->	prepare-call
// @187/w15	->	data-Big!
// @69/w14	->	data-raw!
// @245/w13	->	data-C!
// @246/w12	->	data!
// @90/w11	->	calc-align
// @71/w10	->	F!
// @79/w9	->	16-bit-encode!
// @298/w8	->	Dis
// @96/w7	->	helper-Antenna
// @94/w6	->	Ms
// @92/w5	->	Ip
// @90/w4	->	Value
// @88/w3	->	Number
// @86/w2	->	BigNum
// @256/w1	->	Forward
// @254/w0	->	Label
": w1 2 API ;" NL
": w2 1 API ;" NL
": w3 4 API ;" NL
": w4 6 API ;" NL
": w5 7 API ;" NL
": w6 3 API ;" NL
": w7" NL
	 "7 6 API  1 w3  8 6 API  w2  6 6 API " NL
	 "7 6 API  2 w3  8 6 API  w2 w1" NL
	 "7 6 API  3 w3  8 6 API  w2  6 6 API " NL
	 "7 6 API  4 w3  8 6 API  w2 w1" NL
";" NL
"501 VAL v35" NL
": w8" NL
	"NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP" NL
	"0 w0" NL
	"v35 w3" NL
	 "w1" NL
	"TAG NOP NOP NOP w1" NL
	"TAG NOP NOP NOP w1" NL
	"3 w0 NOP" NL
	"0 w4" NL
	 "w1" NL
	"0 API" NL
";" NL
"VAL v36" NL
"VAL v37" NL
"' w8 VAL v38" NL
": w9" NL
	"$BF" NL
	"OVR C!" NL
	"1 +" NL
	 "!" NL
";" NL
": w10" NL
	"DUP >R" NL
	"w9" NL
	"R>" NL
	"3 +" NL
	 "C!" NL
";" NL
": w11" NL
	">R" NL
	 "*" NL
	"R>" NL
	 "+" NL
";" NL
": w12" NL
	"v38 + w9" NL
";" NL
": w13" NL
	"v38 + C!" NL
";" NL
": w14" NL
	"v38 + !" NL
";" NL
": w15" NL
	"4" NL
	"v38 w11" NL
	 "w10" NL
";" NL
": w16" NL
	">R" NL
	"$C000 OR" NL
	"R>" NL
";" NL
": w17" NL
	"w16" NL
	"w9" NL
";" NL
": w18" NL
	"w16" NL
	"!" NL
";" NL
": w19" NL
	">R" NL
	"2 R>" NL
	"w11" NL
	"w18" NL
";" NL
"' w0 VAL v39" NL
"' w1 VAL v40" NL
"' w2 VAL v41" NL
"' w3 VAL v42" NL
"' w4 VAL v43" NL
"' w5 VAL v44" NL
"' w6 VAL v45" NL
"' w7 VAL v46" NL
": w20" NL
	"DUP >R >R" NL
	"1 R> w19" NL
	"0 R> w19" NL
";" NL
": w21" NL
	"$bbbb v38 !" NL
	"$bbbb v38 $2 + !" NL
	"$bbbb v38 $4 + !" NL
	"$bbbb v38 $6 + !" NL
	"$bbbb v38 $8 + !" NL
	"$bbbb v38 $C + !" NL
	"$bbbb v38 $A + !" NL
	"$bbbb v38 $E + !" NL
";" NL
": w22" NL
	"$bbbb v37 !" NL
	"$bbbb v37 $2 + !" NL
	"$bbbb v36 !" NL
	"$bbbb v36 $2 + !" NL
";" NL
": S-1*" NL
	"w21" NL
	 "$02" NL
	 "$0C" NL
	"w13" NL
	 "$02" NL
	"w15" NL
	 "$01" NL
	 "$04" NL
	"w13" NL
	 "$00" NL
	"w15" NL
	"v39" NL
	"v41 v37 w20" NL
	"v39" NL
	"v41 v36 w20" NL
";" NL
": S-2*" NL
	"w21" NL
	 "$07" NL
	 "$0C" NL
	"w13" NL
	 "$0B" NL
	"w13" NL
	 "$0A" NL
	"w13" NL
	 "$09" NL
	"w13" NL
	 "$08" NL
	"w13" NL
	 "$04" NL
	 "$01" NL
	"w13" NL
	 "$00" NL
	"w13" NL
	"v39" NL
	"v44 v37 w20" NL
	"v39" NL
	"v43 v36 w20" NL
";" NL
": S-3*" NL
	"w21" NL
	 "$0C" NL
	"w13" NL
	 "$08" NL
	"w13" NL
	 "$0A" NL
	 "$04" NL
	"w13" NL
	 "$00" NL
	"w12" NL
	"v39" NL
	"v43 v37 w20" NL
	"v39" NL
	"v45 v36 w20" NL
";" NL
": S-4*" NL
	"w22" NL
	"0 w15" NL
	"1 w15" NL
	"2 w15" NL
	"3 w15" NL
	"v46 0 v37 w19" NL
";" NL
": S-5*" NL
	 "$16" NL
	 "$08" NL
	"w13" NL
	 "$02" NL
	"w12" NL
	 "$01" NL
	"w13" NL
	 "$00" NL
	"w13" NL
	 "$DA7E" NL
	 "$05" NL
	"w12" NL
	 "$0B" NL
	 "$0F" NL
	"w13" NL
	 "$100" NL
	 "$0C" NL
	"w12" NL
	 "$0B" NL
	"w13" NL
	 "$0A" NL
	"w13" NL
	 "$09" NL
	"w13" NL
	"v39" NL
	"v44 v37 w20" NL
	"v39" NL
	"v44 v36 w20" NL
";" NL
": S-6*" NL
	"w21" NL
	"w22" NL
	 "$0C" NL
	 "$04" NL
	"w13" NL
	 "$00" NL
	"w13" NL
	"v39" NL
	"v43 v37 w20" NL
";" NL
": S-7*" NL
	"w21" NL
	 "$10" NL
	 "$05" NL
	"w13" NL
	 "$10" NL
	 "$04" NL
	"w13" NL
	 "$CA00 v35 1 RSH OR" NL
	 "$00" NL
	"w12" NL
	 "$12" NL
	 "$0D" NL
	"w13" NL
	 "$10" NL
	 "$0C" NL
	"w13" NL
	 "$08" NL
	"w12" NL
	"v39" NL
	"v41 v37 w20" NL
	"v39" NL
	"v41 v36 w20" NL
";" NL
": S-8*" NL
	"0 TME" NL
	"100 DLY" NL
		 "w1" NL
	"$13 w0 w1" NL
	"$14 w0 w1" NL
		 "w1" NL
	"0 API" NL
";" NL
": S-9*" NL
	"0 TME" NL
	"100 DLY" NL
		 "w1" NL
	"$0E w0 w1" NL
	"$0F w0 w1" NL
		 "w1" NL
	"0 API" NL
	"5000 DLY" NL
	"1 TME" NL
";" NL
"VAR v47" NL
"VAR v48" NL
"VAR v49" NL
"0 v49 !" NL
"0 v47 !" NL
"0 v48 !" NL
": w32" NL
	"$00 v49 !" NL
";" NL
"' w32 VAL v50" NL
": w33" NL
	"v50 C@ 1 + 7 MOD DUP" NL
	"v50 C!" NL
	"$F0 OR v49 !" NL
";" NL
": w34" NL
	"6 IN 0 = DUP" NL
	"7 IN 0 = DUP" NL
	"v47 @ NOT AND" NL
	"IF" NL
		"w32" NL
	"THN" NL
	"v47 !" NL
	"v48 @ NOT AND" NL
	"IF" NL
		"w33" NL
	"THN" NL
	"v48 !" NL
";" NL
"500 DLY" NL
"50 1 TMI w8" NL
"100 0 TMI w34" NL
"1 TME" NL
;
#endif
