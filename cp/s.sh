A='c'
B='brute'
g++ -std=c++17 -O2 $A.cpp -o $A|| exit
g++ -std=c++17 -O2 $B.cpp -o $B|| exit
g++ -std=c++17 -O2 gen.cpp -o gen || exit
for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    ./$A < int > out1
    ./$B < int > out2
    diff -w out1 out2 || break
    # diff -w <(./c < int) <(./brute < int) || break
done