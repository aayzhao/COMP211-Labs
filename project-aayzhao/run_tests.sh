#!/bin/bash  

# Thanks Benjamin Dod for his code!
  
# to add your own tests, add directories to the `test_data/`  
# directory following the naming convention (e.g. `case0, case1, ...`).  
# for each case, there must be an input and output file  
# just like the provided cases.  
  
CASE_DIR="test_data"  
  
for CASE in $(ls ./test_data); do  
	echo -n "testing $CASE ... "  
	CASE_FP="$CASE_DIR/$CASE" 
 
	# note that if you're working in WSL, you may need to add the 
	# --strip-trailing-cr flag to the diff command or else the diff 
	# will not run properly for each case.
        # If you're working in the Docker environment, you shouldn't
        # have to change this command though.
    { ./project < "$CASE_FP/input"; } 2>&1 | diff "$CASE_FP/output" -
	if [ $? -eq 1 ];  
	then  
                echo -e "\u001b[31;1m$CASE failed, diff shown above.\u001b[0m"  
	else  
		echo -e "\u001b[32;1mpassed!\u001b[0m"  
	fi  
done
