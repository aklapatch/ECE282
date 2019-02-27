#!/bin/bash

BaseUrl="http://ctan.math.utah.edu/ctan/tex-archive/macros/latex/contrib/acmart/"

outfile="lab06-links.txt"

# find 'href', cut out href and everything before it, and the ending > and remove the quotes "
links=$(grep 'href' acmart.html | sed 's/.*href=//' | cut -d '>' -f 1 | sed 's/"//')

# clear output file
if [ -f $outfile ]
then
	rm $outfile
fi

for link in $links
do
# concatenate base url and the further extension and output to the file
echo "$BaseUrl$link" | sed 's/"//' >> $outfile

done