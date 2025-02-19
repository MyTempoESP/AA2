#ifndef __aa2_FTH__
#define __aa2_FTH__
const char code[] PROGMEM =
#define NL "\n"
": w0 5 API ;" NL
// @216/v43	->	addr-Antenna
// @207/v42	->	addr-Ms
// @244/v41	->	addr-Ip
// @254/v40	->	addr-Value
// @124/v39	->	addr-Number
// @276/v38	->	addr-BigNum
// @120/v37	->	addr-Forward
// @273/v36	->	addr-Label
// @138/v35	->	DATA
// @270/v34	->	1-CODE
// @271/v33	->	2-CODE
// @256/v32	->	VERSION
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
// @269/w8	->	Dis
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
"501 VAL v32" NL
": w8" NL
	"NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP NOP" NL
	"0 w0" NL
	"v32 w3" NL
	 "w1" NL
	"TAG NOP NOP NOP w1" NL
	"TAG NOP NOP NOP w1" NL
	"3 w0 NOP" NL
	"0 w4" NL
	 "w1" NL
	"0 API" NL
";" NL
"VAL v33" NL
"VAL v34" NL
"' w8 VAL v35" NL
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
	"v35 + w9" NL
";" NL
": w13" NL
	"v35 + C!" NL
";" NL
": w14" NL
	"v35 + !" NL
";" NL
": w15" NL
	"4" NL
	"v35 w11" NL
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
"' w0 VAL v36" NL
"' w1 VAL v37" NL
"' w2 VAL v38" NL
"' w3 VAL v39" NL
"' w4 VAL v40" NL
"' w5 VAL v41" NL
"' w6 VAL v42" NL
"' w7 VAL v43" NL
": w20" NL
	"DUP >R >R" NL
	"1 R> w19" NL
	"0 R> w19" NL
";" NL
": w21" NL
	"$bbbb v35 !" NL
	"$bbbb v35 $2 + !" NL
	"$bbbb v35 $4 + !" NL
	"$bbbb v35 $6 + !" NL
	"$bbbb v35 $8 + !" NL
	"$bbbb v35 $C + !" NL
	"$bbbb v35 $A + !" NL
	"$bbbb v35 $E + !" NL
";" NL
": w22" NL
	"$bbbb v34 !" NL
	"$bbbb v34 $2 + !" NL
	"$bbbb v33 !" NL
	"$bbbb v33 $2 + !" NL
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
	"v36" NL
	"v38 v34 w20" NL
	"v36" NL
	"v38 v33 w20" NL
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
	"v36" NL
	"v41 v34 w20" NL
	"v36" NL
	"v40 v33 w20" NL
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
	"v36" NL
	"v40 v34 w20" NL
	"v36" NL
	"v42 v33 w20" NL
";" NL
": S-4*" NL
	"w22" NL
	"0 w15" NL
	"1 w15" NL
	"2 w15" NL
	"3 w15" NL
	"v43 0 v34 w19" NL
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
	"v36" NL
	"v41 v34 w20" NL
	"v36" NL
	"v41 v33 w20" NL
";" NL
": S-6*" NL
	"w21" NL
	"w22" NL
	 "$0C" NL
	 "$04" NL
	"w13" NL
	 "$00" NL
	"w13" NL
	"v36" NL
	"v40 v34 w20" NL
";" NL
": S-7*" NL
	"w21" NL
	 "$10" NL
	 "$05" NL
	"w13" NL
	 "$10" NL
	 "$04" NL
	"w13" NL
	 "$CA00 v32 1 RSH OR" NL
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
	"v36" NL
	"v38 v34 w20" NL
	"v36" NL
	"v38 v33 w20" NL
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
"1500 DLY" NL
"50 0 TMI w8" NL
"1 TME" NL
;
#endif
