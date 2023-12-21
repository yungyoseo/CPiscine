#!/bin/bash

#echo "$FT_NBR1" | tr "'\\\"?!\'" '01234' | | tr 'mrdoc' '01234' | 

export FT_RESULT=24441423
echo "obase=13; ibase=5; $FT_RESULT" | bc | tr '0123456789ABC' 'gtaio luSnemf'

