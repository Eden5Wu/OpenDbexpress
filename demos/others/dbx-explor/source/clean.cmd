@del /Q /s *.dcu >nul 2>nul
@del /Q /s *.dpu >nul 2>nul
@del /Q /s *.drc >nul 2>nul
@del /Q /s *.ddp >nul 2>nul
@del /Q /s *.map >nul 2>nul
@rem del /Q /s *.jdbg >nul 2>nul
@del /Q OdbcExplor.000 >nul 2>nul
@del /Q dcc32.log >nul 2>nul
@del /Q sqlnet.log >nul 2>nul
@del /Q OdbcExplor.stat >nul 2>nul
@del /Q OdbcExplor.upx >nul 2>nul
@rem del /s *.map >nul 2>nul

@if "%1" == "-f" del OdbcExplor.exe>nul 2>nul
