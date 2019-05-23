copy /y MSCOMM32.DEP %windir%\system32\
copy /y MSCOMM32.oca %windir%\system32\
copy /y mscomm32.ocx %windir%\system32\
regsvr32 /s %windir%\system32\mscomm32.ocx
reg add HKCR\Licenses\4250E830-6AC2-11cf-8ADB-00AA00C00905 /v "" /t REG_SZ /d "kjljvjjjoquqmjjjvpqqkqmqykypoqjquoun" /f