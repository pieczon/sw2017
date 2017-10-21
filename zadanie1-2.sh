#!/bin/bash
if [ $# -lt 1 ]; then
echo "Wymgana liczba argumentów to 2"
elif [ $# -eq 2 ]; then
echo "Wypisanie dwóch napisów: $1 i $2"
echo "Zapisywanie informacji: $1, do pliku o nazwie: $2"

touch $2
echo "$1">$2

else echo "Błędna liczba parametrów, wprowadz min. 2 parametry!"
fi
exit 0
