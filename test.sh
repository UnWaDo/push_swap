make
make bonus
v=0
min=1000000000
max=0
len=100
echo "" > oficial
echo "" > self_made
for (( i=1; i<=$len; i++ ))
do
    ARG=$(python3 -c "import random as rd; a=[i for i in range($1)]; rd.shuffle(a); print(' '.join([str(i) for i in a]))")
    echo $ARG >> oficial
    ./push_swap $ARG > output
    t=$(wc -l < output)
    if (( $t < $min )); then
        min=$t
    fi
    if (( $t > $max )); then
        max=$t
    fi
    let v+=t
    cat output | ./checker_linux $ARG >> oficial
    echo $t >> oficial
    cat output | ./checker $ARG >> self_made
done
let v/=$len
if [[ $(grep "KO" oficial) == "" ]]; then
    echo "OK"
    echo "Minimal: $min"
    echo "Maximum: $max"
    echo "Average: $v"
    if [[ $(grep "KO" self_made) == "" ]]; then
        echo "Checker OK"
    else
        echo "Checker KO"
    fi
else
    echo "KO"
fi