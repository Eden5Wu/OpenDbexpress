// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dbxopenodbcutils.pas' rev: 11.00

#ifndef DbxopenodbcutilsHPP
#define DbxopenodbcutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Strutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Fmtbcd.hpp>	// Pascal unit
#include <Dbxopenodbctypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbxopenodbcutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int DefaultSystemCodePage;
extern PACKAGE int __fastcall (*AnsiPos)(const AnsiString Substr, const AnsiString S);
extern PACKAGE void __fastcall FreeMemAndNil(void *MemPtr);
extern PACKAGE void __fastcall MaxSet(int &x, int n)/* overload */;
extern PACKAGE bool __fastcall MaxSet(int &x, int n, int max)/* overload */;
extern PACKAGE void __fastcall MaxSet(int &x, const AnsiString S)/* overload */;
extern PACKAGE bool __fastcall MaxSet(int &x, const AnsiString S, int max)/* overload */;
extern PACKAGE void __fastcall MaxSet(int &x, const WideString S)/* overload */;
extern PACKAGE bool __fastcall MaxSet(int &x, const WideString S, int max)/* overload */;
extern PACKAGE int __fastcall BCD2Str(char * pOut, const Fmtbcd::TBcd &ABcd, char ADot = '\x2e', bool bExpFormat = false);
extern PACKAGE void __fastcall Str2BCD(char * PValue, unsigned ASize, Fmtbcd::TBcd &ABcd, char ADot);
extern PACKAGE int __fastcall WideStringLengthFromStr(const char * S);
extern PACKAGE int __fastcall WideStringLengthFromStrings(const Classes::TStrings* L);
extern PACKAGE int __fastcall WCharFromChar(WideChar * WCharDest, int DestChars, const char * CharSource, int SrcBytes);
extern PACKAGE int __fastcall StringToWideChar(const AnsiString Source, WideChar * Dest, int DestChars);
extern PACKAGE int __fastcall StringToWStr(const AnsiString Source, WideChar * &Dest)/* overload */;
extern PACKAGE int __fastcall StringToWStr(const WideString Source, WideChar * &Dest)/* overload */;
extern PACKAGE int __fastcall StringsToWStr(const Classes::TStrings* L, WideChar * &Dest)/* overload */;
extern PACKAGE int __fastcall StrLenNil(const char * AStr);
extern PACKAGE unsigned __fastcall WStrLen(const WideChar * Str);
extern PACKAGE int __fastcall WStrComp(const WideChar * Str1, const WideChar * Str2);
extern PACKAGE int __fastcall WStrIComp(const WideChar * Str1, const WideChar * Str2);
extern PACKAGE int __fastcall WStrLComp(const WideChar * Str1, const WideChar * Str2, unsigned MaxLen);
extern PACKAGE int __fastcall WStrCopy(WideChar * Dest, const WideChar * Source)/* overload */;
extern PACKAGE int __fastcall WStrCopy(WideChar * Dest, const WideString Source)/* overload */;
extern PACKAGE WideChar * __fastcall WStrLCopy(WideChar * Dest, const WideChar * Source, unsigned MaxLen);
extern PACKAGE int __fastcall StrBuffCopy(const char * Source, char * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrBuffCopy(const WideChar * Source, WideChar * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrBuffCopy(const AnsiString Source, char * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrBuffCopy(const WideString Source, WideChar * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrBuffCopy(const AnsiString Source, char * &Dest, System::PInteger MaxLen)/* overload */;
extern PACKAGE int __fastcall StrBuffCopy(const WideString Source, WideChar * &Dest, System::PInteger MaxLen)/* overload */;
extern PACKAGE int __fastcall StrClone(const char * Source, /* out */ char * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const char * Source, /* out */ WideChar * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const AnsiString Source, /* out */ char * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideString Source, WideChar * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideChar * Source, /* out */ char * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideChar * Source, /* out */ WideChar * &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const char * Source, AnsiString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideChar * Source, AnsiString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const char * Source, WideString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideChar * Source, WideString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const AnsiString Source, AnsiString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideString Source, AnsiString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const AnsiString Source, WideString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall StrClone(const WideString Source, WideString &Dest, unsigned MaxLen = (unsigned)(0x0))/* overload */;
extern PACKAGE bool __fastcall StrIsEmpty(const char * Source)/* overload */;
extern PACKAGE bool __fastcall StrIsEmpty(const WideChar * Source)/* overload */;
extern PACKAGE bool __fastcall StrIsEmpty(const AnsiString Source)/* overload */;
extern PACKAGE bool __fastcall StrIsEmpty(const WideString Source)/* overload */;
extern PACKAGE bool __fastcall StrNotEmpty(const char * Source)/* overload */;
extern PACKAGE bool __fastcall StrNotEmpty(const WideChar * Source)/* overload */;
extern PACKAGE bool __fastcall StrNotEmpty(const AnsiString Source)/* overload */;
extern PACKAGE bool __fastcall StrNotEmpty(const WideString Source)/* overload */;
extern PACKAGE AnsiString __fastcall StrPtrToString(const void * Source, bool bUnicode)/* overload */;
extern PACKAGE AnsiString __fastcall StrPtrToString(const char * Source)/* overload */;
extern PACKAGE AnsiString __fastcall StrPtrToString(const WideChar * Source)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const char * S1, const char * S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const WideChar * S1, const WideChar * S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const char * S1, const WideChar * S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const WideChar * S1, const char * S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const AnsiString S1, const AnsiString S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const WideString S1, const WideString S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const AnsiString S1, const WideString S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const WideString S1, const AnsiString S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const char * S1, const AnsiString S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const AnsiString S1, const char * S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const WideChar * S1, const WideString S2)/* overload */;
extern PACKAGE bool __fastcall StrSameText(const WideString S1, const WideChar * S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const char * S1, const char * S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const WideChar * S1, const WideChar * S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const char * S1, const WideChar * S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const WideChar * S1, const char * S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const AnsiString S1, const AnsiString S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const WideString S1, const WideString S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const AnsiString S1, const WideString S2)/* overload */;
extern PACKAGE bool __fastcall StrISameText(const WideString S1, const AnsiString S2)/* overload */;
extern PACKAGE char * __fastcall PAnsiCharParam(const char * P)/* overload */;
extern PACKAGE char * __fastcall PAnsiCharParam(const AnsiString P)/* overload */;
extern PACKAGE AnsiString __fastcall StrAnsiStringParam(const char * P)/* overload */;
extern PACKAGE AnsiString __fastcall StrAnsiStringParam(const AnsiString P)/* overload */;
extern PACKAGE WideString __fastcall ChangeFileExtW(const WideString FileName, const WideString Extension);
extern PACKAGE AnsiString __fastcall PIntToStr(System::PInteger AValue)/* overload */;
extern PACKAGE AnsiString __fastcall ArgStrNull(const AnsiString S)/* overload */;

}	/* namespace Dbxopenodbcutils */
using namespace Dbxopenodbcutils;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dbxopenodbcutils
