#as: -march=i386 -mtune=i686
#source: nops-1.s
#objdump: -drw
#name: i386 nops -march=i386 -mtune=i686 1

.*: +file format .*

Disassembly of section .text:

0+ <nop15>:
[	 ]*0:[	 ]+90[	 ]+nop[ 	]*
[	 ]*1:[	 ]+eb 0d[	 ]+jmp[ 	]+10[ 	]+<nop14>
[	 ]*3:[	 ]+90[	 ]+nop[ 	]*
[	 ]*4:[	 ]+90[	 ]+nop[ 	]*
[	 ]*5:[	 ]+90[	 ]+nop[ 	]*
[	 ]*6:[	 ]+90[	 ]+nop[ 	]*
[	 ]*7:[	 ]+90[	 ]+nop[ 	]*
[	 ]*8:[	 ]+90[	 ]+nop[ 	]*
[	 ]*9:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d:[	 ]+90[	 ]+nop[ 	]*
[	 ]*e:[	 ]+90[	 ]+nop[ 	]*
[	 ]*f:[	 ]+90[	 ]+nop[ 	]*

0+10 <nop14>:
[	 ]*10:[	 ]+90[	 ]+nop[ 	]*
[	 ]*11:[	 ]+90[	 ]+nop[ 	]*
[	 ]*12:[	 ]+8d b4 26 00 00 00 00[	 ]+lea[ 	]+0x0\(%esi\),%esi
[	 ]*19:[	 ]+8d bc 27 00 00 00 00[	 ]+lea[ 	]+0x0\(%edi\),%edi

0+20 <nop13>:
[	 ]*20:[	 ]+90[	 ]+nop[ 	]*
[	 ]*21:[	 ]+90[	 ]+nop[ 	]*
[	 ]*22:[	 ]+90[	 ]+nop[ 	]*
[	 ]*23:[	 ]+8d b6 00 00 00 00[	 ]+lea[ 	]+0x0\(%esi\),%esi
[	 ]*29:[	 ]+8d bc 27 00 00 00 00[	 ]+lea[ 	]+0x0\(%edi\),%edi

0+30 <nop12>:
[	 ]*30:[	 ]+90[	 ]+nop[ 	]*
[	 ]*31:[	 ]+90[	 ]+nop[ 	]*
[	 ]*32:[	 ]+90[	 ]+nop[ 	]*
[	 ]*33:[	 ]+90[	 ]+nop[ 	]*
[	 ]*34:[	 ]+8d b6 00 00 00 00[	 ]+lea[ 	]+0x0\(%esi\),%esi
[	 ]*3a:[	 ]+8d bf 00 00 00 00[	 ]+lea[ 	]+0x0\(%edi\),%edi

0+40 <nop11>:
[	 ]*40:[	 ]+90[	 ]+nop[ 	]*
[	 ]*41:[	 ]+90[	 ]+nop[ 	]*
[	 ]*42:[	 ]+90[	 ]+nop[ 	]*
[	 ]*43:[	 ]+90[	 ]+nop[ 	]*
[	 ]*44:[	 ]+90[	 ]+nop[ 	]*
[	 ]*45:[	 ]+8d 74 26 00[	 ]+lea[ 	]+0x0\(%esi\),%esi
[	 ]*49:[	 ]+8d bc 27 00 00 00 00[	 ]+lea[ 	]+0x0\(%edi\),%edi

0+50 <nop10>:
[	 ]*50:[	 ]+90[	 ]+nop[ 	]*
[	 ]*51:[	 ]+90[	 ]+nop[ 	]*
[	 ]*52:[	 ]+90[	 ]+nop[ 	]*
[	 ]*53:[	 ]+90[	 ]+nop[ 	]*
[	 ]*54:[	 ]+90[	 ]+nop[ 	]*
[	 ]*55:[	 ]+90[	 ]+nop[ 	]*
[	 ]*56:[	 ]+8d 76 00[	 ]+lea[ 	]+0x0\(%esi\),%esi
[	 ]*59:[	 ]+8d bc 27 00 00 00 00[	 ]+lea[ 	]+0x0\(%edi\),%edi

0+60 <nop9>:
[	 ]*60:[	 ]+90[	 ]+nop[ 	]*
[	 ]*61:[	 ]+90[	 ]+nop[ 	]*
[	 ]*62:[	 ]+90[	 ]+nop[ 	]*
[	 ]*63:[	 ]+90[	 ]+nop[ 	]*
[	 ]*64:[	 ]+90[	 ]+nop[ 	]*
[	 ]*65:[	 ]+90[	 ]+nop[ 	]*
[	 ]*66:[	 ]+90[	 ]+nop[ 	]*
[	 ]*67:[	 ]+89 f6[	 ]+mov[ 	]+%esi,%esi
[	 ]*69:[	 ]+8d bc 27 00 00 00 00[	 ]+lea[ 	]+0x0\(%edi\),%edi

0+70 <nop8>:
[	 ]*70:[	 ]+90[	 ]+nop[ 	]*
[	 ]*71:[	 ]+90[	 ]+nop[ 	]*
[	 ]*72:[	 ]+90[	 ]+nop[ 	]*
[	 ]*73:[	 ]+90[	 ]+nop[ 	]*
[	 ]*74:[	 ]+90[	 ]+nop[ 	]*
[	 ]*75:[	 ]+90[	 ]+nop[ 	]*
[	 ]*76:[	 ]+90[	 ]+nop[ 	]*
[	 ]*77:[	 ]+90[	 ]+nop[ 	]*
[	 ]*78:[	 ]+90[	 ]+nop[ 	]*
[	 ]*79:[	 ]+8d b4 26 00 00 00 00[	 ]+lea[ 	]+0x0\(%esi\),%esi

0+80 <nop7>:
[	 ]*80:[	 ]+90[	 ]+nop[ 	]*
[	 ]*81:[	 ]+90[	 ]+nop[ 	]*
[	 ]*82:[	 ]+90[	 ]+nop[ 	]*
[	 ]*83:[	 ]+90[	 ]+nop[ 	]*
[	 ]*84:[	 ]+90[	 ]+nop[ 	]*
[	 ]*85:[	 ]+90[	 ]+nop[ 	]*
[	 ]*86:[	 ]+90[	 ]+nop[ 	]*
[	 ]*87:[	 ]+90[	 ]+nop[ 	]*
[	 ]*88:[	 ]+90[	 ]+nop[ 	]*
[	 ]*89:[	 ]+8d b4 26 00 00 00 00[	 ]+lea[ 	]+0x0\(%esi\),%esi

0+90 <nop6>:
[	 ]*90:[	 ]+90[	 ]+nop[ 	]*
[	 ]*91:[	 ]+90[	 ]+nop[ 	]*
[	 ]*92:[	 ]+90[	 ]+nop[ 	]*
[	 ]*93:[	 ]+90[	 ]+nop[ 	]*
[	 ]*94:[	 ]+90[	 ]+nop[ 	]*
[	 ]*95:[	 ]+90[	 ]+nop[ 	]*
[	 ]*96:[	 ]+90[	 ]+nop[ 	]*
[	 ]*97:[	 ]+90[	 ]+nop[ 	]*
[	 ]*98:[	 ]+90[	 ]+nop[ 	]*
[	 ]*99:[	 ]+90[	 ]+nop[ 	]*
[	 ]*9a:[	 ]+8d b6 00 00 00 00[	 ]+lea[ 	]+0x0\(%esi\),%esi

0+a0 <nop5>:
[	 ]*a0:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a1:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a2:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a3:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a4:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a5:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a6:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a7:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a8:[	 ]+90[	 ]+nop[ 	]*
[	 ]*a9:[	 ]+90[	 ]+nop[ 	]*
[	 ]*aa:[	 ]+90[	 ]+nop[ 	]*
[	 ]*ab:[	 ]+90[	 ]+nop[ 	]*
[	 ]*ac:[	 ]+8d 74 26 00[	 ]+lea[ 	]+0x0\(%esi\),%esi

0+b0 <nop4>:
[	 ]*b0:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b1:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b2:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b3:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b4:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b5:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b6:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b7:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b8:[	 ]+90[	 ]+nop[ 	]*
[	 ]*b9:[	 ]+90[	 ]+nop[ 	]*
[	 ]*ba:[	 ]+90[	 ]+nop[ 	]*
[	 ]*bb:[	 ]+90[	 ]+nop[ 	]*
[	 ]*bc:[	 ]+8d 74 26 00[	 ]+lea[ 	]+0x0\(%esi\),%esi

0+c0 <nop3>:
[	 ]*c0:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c1:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c2:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c3:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c4:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c5:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c6:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c7:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c8:[	 ]+90[	 ]+nop[ 	]*
[	 ]*c9:[	 ]+90[	 ]+nop[ 	]*
[	 ]*ca:[	 ]+90[	 ]+nop[ 	]*
[	 ]*cb:[	 ]+90[	 ]+nop[ 	]*
[	 ]*cc:[	 ]+90[	 ]+nop[ 	]*
[	 ]*cd:[	 ]+8d 76 00[	 ]+lea[ 	]+0x0\(%esi\),%esi

0+d0 <nop2>:
[	 ]*d0:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d1:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d2:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d3:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d4:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d5:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d6:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d7:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d8:[	 ]+90[	 ]+nop[ 	]*
[	 ]*d9:[	 ]+90[	 ]+nop[ 	]*
[	 ]*da:[	 ]+90[	 ]+nop[ 	]*
[	 ]*db:[	 ]+90[	 ]+nop[ 	]*
[	 ]*dc:[	 ]+90[	 ]+nop[ 	]*
[	 ]*dd:[	 ]+90[	 ]+nop[ 	]*
[	 ]*de:[	 ]+66 90[ 	]+xchg[ 	]+%ax,%ax
#pass
