/* Generated by Nim Compiler v0.10.2 */
/*   (c) 2014 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, i386, gcc */
/* Command for C compiler:
   gcc -c  -w  -I/usr/lib/nim -o /home/eric/Desktop/nim/nail/nimcache/os.o /home/eric/Desktop/nim/nail/nimcache/os.c */
#define NIM_INTBITS 32
#include "nimbase.h"
typedef struct TY13206 TY13206;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct indexerror3255 indexerror3255;
typedef struct Exception Exception;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tcell45135 tcell45135;
typedef struct tcellseq45151 tcellseq45151;
typedef struct tgcheap47216 tgcheap47216;
typedef struct tcellset45147 tcellset45147;
typedef struct tpagedesc45143 tpagedesc45143;
typedef struct tmemregion27410 tmemregion27410;
typedef struct tsmallchunk26640 tsmallchunk26640;
typedef struct tllchunk27404 tllchunk27404;
typedef struct tbigchunk26642 tbigchunk26642;
typedef struct tintset26617 tintset26617;
typedef struct ttrunk26613 ttrunk26613;
typedef struct tavlnode27408 tavlnode27408;
typedef struct tgcstat47214 tgcstat47214;
typedef struct tbasechunk26638 tbasechunk26638;
typedef struct tfreecell26630 tfreecell26630;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(void, TY3089) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY3094) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY3089 marker;
TY3094 deepcopy;
};
struct  TNimObject  {
TNimType* m_type;
};
struct  Exception  {
  TNimObject Sup;
Exception* parent;
NCSTRING name;
NimStringDesc* message;
NimStringDesc* trace;
};
struct  indexerror3255  {
  Exception Sup;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  tcell45135  {
NI Refcount;
TNimType* Typ;
};
struct  tcellseq45151  {
NI Len;
NI Cap;
tcell45135** D;
};
struct  tcellset45147  {
NI Counter;
NI Max;
tpagedesc45143* Head;
tpagedesc45143** Data;
};
typedef tsmallchunk26640* TY27422[512];
typedef ttrunk26613* ttrunkbuckets26615[256];
struct  tintset26617  {
ttrunkbuckets26615 Data;
};
struct  tmemregion27410  {
NI Minlargeobj;
NI Maxlargeobj;
TY27422 Freesmallchunks;
tllchunk27404* Llmem;
NI Currmem;
NI Maxmem;
NI Freemem;
NI Lastsize;
tbigchunk26642* Freechunkslist;
tintset26617 Chunkstarts;
tavlnode27408* Root;
tavlnode27408* Deleted;
tavlnode27408* Last;
tavlnode27408* Freeavlnodes;
};
struct  tgcstat47214  {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
NI64 Maxpause;
};
struct  tgcheap47216  {
void* Stackbottom;
NI Cyclethreshold;
tcellseq45151 Zct;
tcellseq45151 Decstack;
tcellset45147 Cycleroots;
tcellseq45151 Tempstack;
NI Recgclock;
tmemregion27410 Region;
tgcstat47214 Stat;
};
typedef NI TY26620[16];
struct  tpagedesc45143  {
tpagedesc45143* Next;
NI Key;
TY26620 Bits;
};
struct  tbasechunk26638  {
NI Prevsize;
NI Size;
NIM_BOOL Used;
};
struct  tsmallchunk26640  {
  tbasechunk26638 Sup;
tsmallchunk26640* Next;
tsmallchunk26640* Prev;
tfreecell26630* Freelist;
NI Free;
NI Acc;
NF Data;
};
struct  tllchunk27404  {
NI Size;
NI Acc;
tllchunk27404* Next;
};
struct  tbigchunk26642  {
  tbasechunk26638 Sup;
tbigchunk26642* Next;
tbigchunk26642* Prev;
NI Align;
NF Data;
};
struct  ttrunk26613  {
ttrunk26613* Next;
NI Key;
TY26620 Bits;
};
typedef tavlnode27408* TY27414[2];
struct  tavlnode27408  {
TY27414 Link;
NI Key;
NI Upperbound;
NI Level;
};
struct  tfreecell26630  {
tfreecell26630* Next;
NI Zerofield;
};
struct TY13206 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
static N_INLINE(NimStringDesc*, pop_138310)(TY13206** s_138318);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
N_NIMCALL(TGenericSeq*, setLengthSeq)(TGenericSeq* seq, NI elemsize, NI newlen);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_18801)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(NimStringDesc*, cstrToNimstr)(NCSTRING str);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(tcell45135*, usrtocell_48846)(void* usr);
static N_INLINE(void, rtladdzct_50404)(tcell45135* c);
N_NOINLINE(void, addzct_48817)(tcellseq45151* s, tcell45135* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
STRING_LITERAL(TMP390, "invalid index", 13);
NIM_BOOL envcomputed_136807;
TY13206* environment_136809;
extern NCSTRING* environ;
extern TFrame* frameptr_16242;
extern int cmdCount;
extern NCSTRING* cmdLine;
extern TNimType NTI20801; /* ref IndexError */
extern TNimType NTI3255; /* IndexError */
extern tgcheap47216 gch_47244;

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
	result = 0;
	result = (NI)((NU32)(a) - (NU32)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (0 <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (0 <= (NI)(result ^ (NI)((NU32) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	BeforeRet: ;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_16242 == NIM_NIL)) goto LA4;
		LOC1 = 0;
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_16242).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_16242;
	frameptr_16242 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_18801();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_16242 = (*frameptr_16242).prev;
}

static N_INLINE(NimStringDesc*, pop_138310)(TY13206** s_138318) {
	NimStringDesc* result;
	NI l;
	NI TMP386;
	nimfr("pop", "system.nim")
	result = 0;
	nimln(1810, "system.nim");
	nimln(1810, "system.nim");
	nimln(1810, "system.nim");
	TMP386 = subInt((*s_138318)->Sup.len, 1);
	l = (NI32)(TMP386);
	nimln(1811, "system.nim");
	if ((NU)(l) >= (NU)((*s_138318)->Sup.len)) raiseIndexError();
	result = copyString((*s_138318)->data[l]);
	nimln(1812, "system.nim");
	(*s_138318) = (TY13206*) setLengthSeq(&((*s_138318))->Sup, sizeof(NimStringDesc*), l);
	popFrame();
	return result;
}

N_NIMCALL(NI, paramcount_140639)(void) {
	NI result;
	NI32 TMP389;
	nimfr("paramCount", "os.nim")
	result = 0;
	nimln(1701, "os.nim");
	nimln(1701, "os.nim");
	TMP389 = subInt(cmdCount, ((NI32) 1));
	result = ((NI) ((NI32)(TMP389)));
	popFrame();
	return result;
}

static N_INLINE(tcell45135*, usrtocell_48846)(void* usr) {
	tcell45135* result;
	nimfr("usrToCell", "gc.nim")
	result = 0;
	nimln(118, "gc.nim");
	nimln(118, "gc.nim");
	nimln(118, "gc.nim");
	result = ((tcell45135*) ((NI)((NU32)(((NI) (usr))) - (NU32)(((NI)sizeof(tcell45135))))));
	popFrame();
	return result;
}

static N_INLINE(void, rtladdzct_50404)(tcell45135* c) {
	nimfr("rtlAddZCT", "gc.nim")
	nimln(199, "gc.nim");
	addzct_48817((&gch_47244.Zct), c);
	popFrame();
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	tcell45135* c;
	nimfr("nimGCunrefNoCycle", "gc.nim")
	nimln(233, "gc.nim");
	c = usrtocell_48846(p);
	nimln(235, "gc.nim");
	{
		nimln(167, "gc.nim");
		(*c).Refcount -= 8;
		nimln(168, "gc.nim");
		if (!((NU32)((*c).Refcount) < (NU32)(8))) goto LA3;
		nimln(236, "gc.nim");
		rtladdzct_50404(c);
	}
	LA3: ;
	popFrame();
}

N_NIMCALL(NimStringDesc*, paramstr_140609)(NI i) {
	NimStringDesc* result;
	indexerror3255* e_140616;
	NimStringDesc* LOC7;
	nimfr("paramStr", "os.nim")
	result = 0;
	nimln(1696, "os.nim");
	{
		NIM_BOOL LOC3;
		nimln(1696, "os.nim");
		LOC3 = 0;
		nimln(1696, "os.nim");
		LOC3 = (i < ((NI) (cmdCount)));
		if (!(LOC3)) goto LA4;
		nimln(1696, "os.nim");
		LOC3 = (0 <= i);
		LA4: ;
		if (!LOC3) goto LA5;
		nimln(1696, "os.nim");
		nimln(1696, "os.nim");
		nimln(1696, "os.nim");
		if ((NU)(i) > (NU)(50000)) raiseIndexError();
		result = cstrToNimstr(cmdLine[(i)- 0]);
		goto BeforeRet;
	}
	LA5: ;
	e_140616 = 0;
	nimln(2149, "system.nim");
	e_140616 = (indexerror3255*) newObj((&NTI20801), sizeof(indexerror3255));
	(*e_140616).Sup.Sup.m_type = (&NTI3255);
	nimln(2150, "system.nim");
	LOC7 = 0;
	LOC7 = (*e_140616).Sup.message; (*e_140616).Sup.message = copyStringRC1(((NimStringDesc*) &TMP390));
	if (LOC7) nimGCunrefNoCycle(LOC7);
	nimln(1697, "os.nim");
	raiseException((Exception*)e_140616, "IndexError");
	BeforeRet: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, HEX00_osInit)(void) {
	nimfr("os", "os.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, HEX00_osDatInit)(void) {
}
