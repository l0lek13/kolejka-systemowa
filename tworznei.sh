#!/bin/bash

make wys
make odb
./wys
echo "koniec 1"
./odb
echo "koniec 2"
./spr.sh
echo "koniec 3"
rm odb
rm wys


