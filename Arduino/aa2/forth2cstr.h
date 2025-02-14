#ifndef __aa2_FTH__
#define __aa2_FTH__
const char code[] PROGMEM =
#define NL "\n"
    // @364/v53	->	atn
    // @362/v52	->	MS-
    // @360/v51	->	IP-
    // @358/v50	->	Val
    // @268/v49	->	Num
    // @354/v48	->	Big
    // @352/v47	->	Fwd
    // @265/v46	->	Lbl
    // @339/v45	->	2-C
    // @263/v44	->	1-C
    // @284/v43	->	confirm-pin
    // @279/v42	->	arrow-pin
    // @308/v41	->	confirm-state
    // @302/v40	->	arrow-state
    // @286/v39	->	current-screen
    // @322/v38	->	action
    // @157/v37	->	DATA
    // @329/v36	->	1-CODE
    // @329/v35	->	2-CODE
    // @93/v34	->	VERSION
    // @26/w33	->	Dis
    // @251/w32	->	ci!
    // @249/w31	->	adC
    // @329/w30	->	adB
    // @327/w29	->	ad!
    // @325/w28	->	Atn
    // @346/w27	->	do-button
    // @309/w26	->	clicked?
    // @307/w25	->	update-confirm-state
    // @301/w24	->	update-arrow-state
    // @291/w23	->	update-state
    // @301/w22	->	next-screen
    // @288/w21	->	confirm-pressed?
    // @282/w20	->	arrow-pressed?
    // @316/w19	->	Antenna!
    // @319/w18	->	call-idx!
    // @220/w17	->	call!
    // @149/w16	->	encode-call!
    // @154/w15	->	prepare-call
    // @313/w14	->	aligned-data-Big!
    // @313/w13	->	aligned-data-C!
    // @310/w12	->	aligned-data!
    // @157/w11	->	calc-align
    // @130/w10	->	F!
    // @144/w9	->	16-bit-encode!
    // @326/w8	->	w33
    // @318/w7	->	antenna
    // @316/w6	->	Ms
    // @314/w5	->	Ip
    // @312/w4	->	Value
    // @310/w3	->	Number
    // @308/w2	->	BigNum
    // @306/w1	->	Forward
    // @304/w0	->	Label
    ": w0 5 API ;" NL ": w1 2 API ;" NL ": w2 1 API ;" NL ": w3 4 API ;" NL
    ": w4 6 API ;" NL ": w5 7 API ;" NL ": w6 3 API ;" NL ": w7" NL
    "7 6 API  1 w3  8 6 API  w2  6 6 API " NL "7 6 API  2 w3  8 6 API  w2 w1" NL
    "7 6 API  3 w3  8 6 API  w2  6 6 API " NL "7 6 API  4 w3  8 6 API  w2 w1" NL
    ";" NL "501 VAL v34" NL ": w8" NL "NOP NOP NOP NOP" NL "NOP NOP NOP NOP" NL
    "NOP NOP NOP NOP" NL "NOP NOP NOP NOP" NL "0 w0" NL "v34 w3" NL "w1" NL
    "TAG NOP NOP NOP w1" NL "TAG NOP NOP NOP w1" NL "3 w0 NOP" NL "0 w4" NL
    "w1" NL "0 API" NL ";" NL "VAL v35" NL "VAL v36" NL "' w8 VAL v37" NL
    ": w9" NL "$BF" NL "OVR C!" NL "1 +" NL "!" NL ";" NL ": w10" NL "DUP >R" NL
    "w9" NL "R>" NL "3 +" NL "C!" NL ";" NL ": w11" NL ">R" NL "*" NL "R>" NL
    "+" NL ";" NL ": w12" NL "v37 w11" NL "w9" NL ";" NL ": w13" NL "v37 w11" NL
    "C!" NL ";" NL ": w14" NL "4" NL "v37 w11" NL "w10" NL ";" NL ": w15" NL
    ">R" NL "$C000 OR" NL "R>" NL ";" NL ": w16" NL "w15" NL "w9" NL ";" NL
    ": w17" NL "w15" NL "!" NL ";" NL ": w18" NL ">R" NL "2 R>" NL "w11" NL
    "w17" NL ";" NL ": w19" NL "0 w14" NL "1 w14" NL "2 w14" NL "3 w14" NL
    ";" NL "VAR v38" NL "VAR v39" NL "1 v39 !" NL "VAR v40" NL "VAR v41" NL
    "7 VAL v42" NL "6 VAL v43" NL ": w20" NL "v42 IN 0 =" NL ";" NL ": w21" NL
    "v43 IN 0 =" NL ";" NL ": w22" NL "v39 @" NL "1 + 7 MOD" NL "v39 !" NL
    ";" NL ": w23" NL "DUP @ >R" NL "DUP >R" NL "!" NL "R>" NL "R>" NL ";" NL
    ": w24" NL "w20 v40" NL "w23" NL ";" NL ": w25" NL "w21 v41" NL "w23" NL
    ";" NL ": w26" NL "NOT" NL "AND" NL ";" NL ": w27" NL "w24" NL "w26 IF" NL
    "w22" NL "THN" NL "w25" NL "w26 IF" NL "-1 v38 !" NL "THN" NL ";" NL
    "v36 VAL 1-C" NL "v35 VAL 2-C" NL ": Atn w19 ;" NL ": ad! w12 ;" NL
    ": adB w14 ;" NL ": adC w13 ;" NL ": ci! w18	 ;" NL ": Dis w8 ;" NL
    "' w0 VAL Lbl" NL "' w1 VAL Fwd" NL "' w2 VAL Big" NL "' w3 VAL Num" NL
    "' w4 VAL Val" NL "' w5 VAL IP-" NL "' w6 VAL MS-" NL "' w7 VAL atn" NL
    "1500 DLY" NL "1 TME" NL;
#endif
