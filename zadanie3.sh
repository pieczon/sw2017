#!/bin/bash

export zmienna1=$1
export zmienna2=$2

function checkpar
{
  if [ $# -lt 1 ]; then
  echo "Wymgana liczba argumentów to 2"
    elif [ $# -eq 2 ]; then
    echo "Wypisanie dwóch napisów: $1 i $2"
    echo "Zapisywanie informacji: $1, do pliku o nazwie: $2"
  else echo "Błędna liczba parametrów, wprowadz min. 2 parametry!"
  fi
}

function savefile
{
  touch $2
  echo "$1">$2
}


checkpar $1 $2

savefile $1 $2



exit 0
