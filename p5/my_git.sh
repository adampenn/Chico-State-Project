#!/bin/bash

echo "Please enter your commit message:"

read message

`git add --all`

`git commit -m $message`


for i in $( ls )
do
  echo `du -s $i | awk '{printf $1}'` >> filesize
  done
  # Flag for seeing if the bigfile file needs to be removed
  rmBig=false
  # go threw bigfile and see if they are a certain size
  while read f
  do
    if [ $f -ge 5 ]
      then
          rmBig=true
              echo $f >> bigfile
                fi

