#/bin/bash

cd `dirname $0`;
mv -f ours_ORG/*test* test/ORG/;
mv -f ours_MDF/*test* test/MDF/;

FILES=(`ls ours_ORG/`);
OURS_ORG=(`sed 's/
OURS_MDF=(`sed 's/
ORG=(`sed 's/
MDF=(`sed 's/

echo "Risultati ORG: ( ( B - H ) / B )%";

for (( i=0; i<${#FILES[@]}; i++ ));
do
	A=${OURS_ORG[$i]};
	B=${ORG[$i]};
	DIFFB=`echo \($B-$A\)*100/$B | bc`;
	echo "${FILES[$i]}:	$A:	$DIFFB	($B)";
done;

echo "Risultati MDF: ( ( B - H ) / B )%";

for (( i=0; i<${#FILES[@]}; i++ ));
do
	A=${OURS_MDF[$i]};
	B=${MDF[$i]};
	DIFFB=`echo \($B-$A\)*100/$B | bc`;
	echo "${FILES[$i]}:	$A:	$DIFFB	($B)";
done;
