#/bin/bash

cd `dirname $0`;
rm -f ours/*test*;

FILES=(`ls ours/`);
OURS=(`sed 's/
MDF=(`sed 's/
ORG=(`sed 's/

echo "Risultati: ( ( B - H ) / B )%";

for (( i=0; i<${#FILES[@]}; i++ ));
do
	A=${OURS[$i]};
	B=${MDF[$i]};
	C=${ORG[$i]};
	DIFFB=`echo \($B-$A\)*100/$B | bc`;
	DIFFC=`echo \($C-$A\)*100/$C | bc`;
	echo "${FILES[$i]}:	$A:	$DIFFB	($B)	| $DIFFC	($C)";
done;