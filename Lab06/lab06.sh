#!/bin/bash

BaseUrl="http://ctan.math.utah.edu/ctan/tex-archive/macros/latex/contrib/acmart/"

infile="acmart.html"
outfile="lab06-links.txt"

# find 'href', cut out href and everything before it, and the ending > and remove the quotes "
grep 'href' $infile | sed 's/.*href=//' | cut -d '>' -f 1 | sed 's|"|'$BaseUrl'|' | sed 's/"//' > $outfile