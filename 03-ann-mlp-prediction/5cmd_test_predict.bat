@echo off

set /A image_size_x=645

echo idcar must be 0
for %%f in (idcar\*.jpg) do (
  echo|set /p="%%f	> " :: echo without newline
  LprPredict.exe %%f model.xml %image_size_x%
)

echo ----------------
echo idcard must be 1
for %%f in (idcard\*.jpg) do (
  echo|set /p="%%f	> " :: echo without newline
  LprPredict.exe %%f model.xml %image_size_x%
)
