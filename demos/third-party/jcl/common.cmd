@echo off

rem Common options

  set UsePack=0
  set DEBUG=1
  set MAPFILE=1
  set JDBG=0
  set CleanDcc32Log=1
  set DEBUG_BATCH=0
  set TRACE_STACK_SOURCE=1

  set UserLib=.

rem set Include and Resource path
  set UserLibI=%UserLib%
  set UserLibR=%UserLib%

  @rem set UserCOpt=-D_DEBUG_;_TRACE_CALLS_;_CHECK_LEAKS_ -$R-,O-,D+,L+
