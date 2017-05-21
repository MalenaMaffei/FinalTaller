#!/bin/bash

git pull
git status

echo "add todo y pushear? [y/n]"
read answer
if echo "$answer" | grep -iq "^y" ;then
    echo "mensaje commit: "
    read $mensaje
    git add .
    git commit -m '"$mensaje"'
    git push
fi
