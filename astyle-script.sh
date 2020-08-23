#!/usr/bin/bash

for i in `cat files-to-beautify.txt`
do
  rm -f $i.orig
  /cygdrive/c/Users/mpolia/Downloads/AStyle_3.1_windows/AStyle/bin/AStyle.exe --indent=spaces=2 --indent-classes --indent-switches --break-blocks --pad-comma  --pad-oper --pad-paren-out --pad-header  --add-braces --convert-tabs --style=allman $i
done

