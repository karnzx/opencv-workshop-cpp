@echo off

set /A image_size_x=645

echo you can manaully predict by use `LprPredict.exe {image} model.xml {image_size_x}`

echo idcar must be 0
echo idcard must be 1
for %%f in (resized-image-645\*.jpg) do (
  echo|set /p="%%f	> " :: echo without newline
  LprPredict.exe %%f model.xml %image_size_x%
)
