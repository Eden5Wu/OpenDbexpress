// CodeGear C++Builder
// Copyright (c) 1995, 2011 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DbxOpenOdbcASA.pas' rev: 23.00 (Win32)

#ifndef DbxopenodbcasaHPP
#define DbxopenodbcasaHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbxopenodbcasa
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Word ASA_REGISTER_MESSAGE_CALLBACK = System::Word(0x770);
extern PACKAGE System::AnsiString AsaCallbackMessage;
extern PACKAGE System::Word WM_ASACALLBACK;
extern PACKAGE bool WM_ASACALLBACK_SUPPORTED;
extern PACKAGE int __stdcall ASA_MESSAGE_INIT(unsigned bWindow);
extern PACKAGE void __stdcall ASA_MESSAGE_CALLBACK(void * sqlca, char msg_type, int code, System::Word Len, char * msg);

}	/* namespace Dbxopenodbcasa */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DBXOPENODBCASA)
using namespace Dbxopenodbcasa;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DbxopenodbcasaHPP
